#ifndef SERVERCONFIG_DOT_HPP
#define SERVERCONFIG_DOT_HPP

#include "defaults.hpp"
#include "string"
#include "args.hpp"
#include "iostream"
#include "rang.hpp"


class ServerConfig {
public:
    int port = DEFAULT_PORT;
    std::string domainName = DEFAULT_DOMAINNAME;
    std::string webroot = DEFAULT_WEBROOT;
	bool quietMode = DEFAULT_QUIET;
	bool logFile = DEFAULT_LOG;
	bool postCapture = DEFAULT_POSTCAPTURE;
    ServerConfig(Args& args);
    ServerConfig(void);
    void getConfigCli(Args& args);
};


std::ostream& operator<<(std::ostream& os, const ServerConfig& config);
#endif