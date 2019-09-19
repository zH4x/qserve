#include "args.hpp"

Args::Args(int argc, char** argv) {
    this->cliArgs = std::vector<std::string>(argv, argv + argc);
}

bool Args::findFlag(const std::string& shortName, const std::string& fullName){
    for(auto &arg : this->cliArgs){
        if (arg == shortName || arg == fullName) return true;
    }
    return false;
}

Args::ParamResult Args::findArg(const std::string shortName, const std::string& fullName){
    ParamResult result;
    for (int i = 0; i < this->cliArgs.size(); i++){
        if (this->cliArgs.at(i) == shortName || this->cliArgs.at(i) == fullName) {
            if (i < this->cliArgs.size() - 1){
                result.success = true;
                result.value = this->cliArgs.at(i + 1);
                return result;
            }
        }
    }
    result.success = false;
    result.value = "NA";
    return result;
}