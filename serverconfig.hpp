#ifndef SERVERCONFIG_DOT_HPP
#define SERVERCONFIG_DOT_HPP

#include "defaults.hpp"
#include "string"
#include "args.hpp"
#include "iostream"

class ServerConfig {
public:
    int port = DEFAULT_PORT;
    std::string domainName = DEFAULT_DOMAINNAME;
    std::string webroot = DEFAULT_WEBROOT;
    ServerConfig(Args& args);
    ServerConfig(void);
    void getConfigCli(Args& args);
};


std::ostream& operator<<(std::ostream& os, const ServerConfig& config);
#endif