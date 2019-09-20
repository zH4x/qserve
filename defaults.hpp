#ifndef DEFAULTS_DOT_HPP
#define DEFAULTS_DOT_HPP

// The default port to host the server on.  Change with -p or --port
#define DEFAULT_PORT 80

// the default domain name.  Use either localhost, your local IP address, 0.0.0.0 for any, or domain name if you have one
#define DEFAULT_DOMAINNAME "0.0.0.0"

// the webroot for static files to be served from.  By default it's your current directory
#define DEFAULT_WEBROOT "./"

// write verbose info to a log file
#define DEFAULT_LOG false

// capture POST data to a log file
#define DEFAULT_POSTCAPTURE false

#define DEFAULT_QUIET false

#endif