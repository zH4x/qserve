#include "serverconfig.hpp"

void ServerConfig::getConfigCli(Args& args){
    auto domainArg = args.findArg("-d", "--domain-name");
    if (domainArg.success) this->domainName = domainArg.value;

    auto portArg = args.findArg("-p", "--port");
    if (portArg.success) this->port = std::stoi(portArg.value);

    auto webrootArg = args.findArg("-w", "--webroot");
    if (webrootArg.success) this->webroot = webrootArg.value;
}

ServerConfig::ServerConfig(Args& args){
    this->getConfigCli(args);
}

ServerConfig::ServerConfig(void) {}

std::ostream& operator<<(std::ostream& os, const ServerConfig& config)
{
    os << "Domain Name: " << config.domainName << std::endl;
    os << "Port: " << config.port << std::endl;
    os << "WebRoot: " << config.webroot << std::endl;
    return os;
}