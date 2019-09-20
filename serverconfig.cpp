#include "serverconfig.hpp"

void ServerConfig::getConfigCli(Args& args){
    auto domainArg = args.findArg("-d", "--domain-name");
    if (domainArg.success) this->domainName = domainArg.value;

    auto portArg = args.findArg("-p", "--port");
    if (portArg.success) this->port = std::stoi(portArg.value);

    auto webrootArg = args.findArg("-w", "--webroot");
    if (webrootArg.success) this->webroot = webrootArg.value;

	this->logFile = args.findFlag("-l", "--log");
	this->postCapture = args.findFlag("-c", "--capture-post");
	this->quietMode = args.findFlag("-q", "--quiet");
}

ServerConfig::ServerConfig(Args& args){
    this->getConfigCli(args);
}

ServerConfig::ServerConfig(void) {}

inline void printBool(std::ostream& os, bool value)
{
	if (value)
	{
		os << rang::fgB::green << "true" << rang::fg::reset;
	} else
	{
		os << rang::fgB::red << "false" << rang::fg::reset;
	}
}

std::ostream& operator<<(std::ostream& os, const ServerConfig& config)
{
    os << rang::fgB::cyan << "Port: " << rang::fgB::yellow << config.port << std::endl;
	os << rang::fgB::cyan << "WebRoot: " << rang::fgB::yellow << config.webroot << std::endl;
	os << rang::fgB::blue << "Domain Name: " << rang::fgB::yellow << config.domainName << std::endl;
	os << rang::fgB::blue << "Log to file: ";
	printBool(os, config.logFile); os << std::endl;
	os << rang::fgB::blue << "Log POST data: ";
	printBool(os, config.postCapture); os << std::endl;
	os << rang::fg::reset;
    return os;
}