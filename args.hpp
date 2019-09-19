#ifndef ARGS_DOT_HPP
#define ARGS_DOT_HPP
#include <string>
#include <vector>

class Args {
public:
    struct ParamResult {
        bool success;
        std::string value;
    };
    std::vector<std::string> cliArgs;
    Args(int argc, char** argv);
    bool findFlag(const std::string& shortName, const std::string& fullName);
    ParamResult findArg(const std::string shortName, const std::string& fullName);
};
#endif