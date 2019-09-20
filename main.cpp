#include <iostream>
#include <string>
#include "httplib.h"
#include "serverconfig.hpp"
#include <ctime>

// change default settings in defaults.hpp

// macro to output to both the console, and a file
#define LOG(x) if (!config.quietMode){ std::cout << x; if (config.logFile) logFile << x ; }

void showHelp()
{
	// show options
	std::cout << rang::fgB::cyan << rang::style::bold << "\tArguments" << rang::style::reset << rang::fg::reset << " (pass the flag and a value)" << std::endl;
	std::cout << rang::fgB::cyan << "-p" << rang::fgB::blue << "  --port" << rang::fg::reset << "\t\t Which port to actively listen on" << std::endl;
	std::cout << rang::fgB::cyan << "-w" << rang::fgB::blue << "  --webroot" << rang::fg::reset << "\t\t Directory to use as the webroot" << std::endl;
	std::cout << rang::fgB::cyan << "-d" << rang::fgB::blue << "  --domain-name" << rang::fg::reset << "\t Only listens under a specific domain name" << std::endl;

	std::cout << std::endl;
	std::cout << rang::fgB::yellow << rang::style::bold << "\tFlags" << rang::style::reset << rang::fg::reset << " (standalone options)" << std::endl;
	std::cout << rang::fgB::yellow << "-h" << rang::fgB::green << "  --help" << rang::fg::reset << "\t\t Shows this screen" << std::endl;
	std::cout << rang::fgB::yellow << "-l" << rang::fgB::green << "  --log" << rang::fg::reset << "\t\t Enable Logging to a file" << std::endl;
	std::cout << rang::fgB::yellow << "-c" << rang::fgB::green << "  --capture-post" << rang::fg::reset << "\t Captures POST data to a file" << std::endl;
	std::cout << rang::fgB::yellow << "-q" << rang::fgB::green << "  --quiet" << rang::fg::reset << "\t\t Quiet Mode (No output)" << std::endl;

	std::cout << std::endl << rang::fgB::magenta << rang::style::bold << "\tDefault Settings" << rang::style::reset << rang::fg::reset << " (when ran without args)" << std::endl;
	std::cout << rang::fgB::magenta << "--port " << rang::fg::reset << DEFAULT_PORT << std::endl;
	std::cout << rang::fgB::magenta << "--webroot " << rang::fg::reset << DEFAULT_WEBROOT << std::endl;
	std::cout << rang::fgB::magenta << "--domain-name " << rang::fg::reset << DEFAULT_DOMAINNAME << std::endl;
}

int main(int argc, char** argv)
{
    Args args(argc, argv);

	if (args.findFlag("-h", "--help"))
	{
		showHelp();
		return 0;
	}

	ServerConfig config(args);

	std::ofstream logFile;
	std::ofstream postLogFile;
	if (config.logFile) logFile = std::ofstream("log.txt");
	if (config.postCapture) postLogFile = std::ofstream("POST_log.txt");
	
	LOG(config << std::endl);

    httplib::Server svr;
    svr.set_base_dir(config.webroot.c_str());

	svr.set_logger([&](const httplib::Request& req, const httplib::Response& res) {
		LOG(std::time(0) << rang::fgB::magenta << "\t" << req.method << "\t"
			<< rang::fgB::yellow << req.target << "\t"
			<< rang::fgB::cyan << get_header_value(req.headers, "REMOTE_ADDR"));
			
			if (req.method == "POST")
			{
				// write the POST data to the console/log file
				LOG("\t" << rang::fgB::red << req.body);

				if (config.postCapture) {
					// also put the POST data into it's separate logfile
					postLogFile << std::time(0) << "\t" <<
						req.target << "\t" <<
						get_header_value(req.headers, "REMOTE_ADDR") << "\t" <<
						req.body << std::endl;
				}
			}
		LOG(rang::fg::reset << std::endl)
	});

	LOG(rang::fg::reset << "Server Started, [" << rang::fgB::yellow << "CTRL C" << rang::fg::reset << "] to kill" << std::endl); 
    bool success = svr.listen(config.domainName.c_str(), config.port);
    if (!success) {
		std::cout << rang::fgB::red << "An error occured, is the selected port ("
			<< config.port << ") available?" << rang::fg::reset << std::endl;
    }
    return 0;
}
