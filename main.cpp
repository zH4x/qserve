#include <iostream>
#include "ipaddress.hpp"
#include "serverconfig.hpp"



// change default settings in defaults.hpp


int main(int argc, char** argv)
{
    Args args(argc, argv);
    
    auto ip = GetPrimaryIp();
    std::cout << ip << std::endl;

    ServerConfig config(args);
    std::cout << config << std::endl;

    httplib::Server svr;
    svr.set_base_dir(config.webroot.c_str());
    std::cout << "Server Started, CTRL+C to kill" << std::endl;
    bool success = svr.listen(config.domainName.c_str(), config.port);
    if (!success) {
        std::cout << "An error occured, is the selected port (" << config.port << ") available?" << std::endl;
    }
    return 0;
}
