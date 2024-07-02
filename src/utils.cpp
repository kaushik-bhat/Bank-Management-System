#include "utils.h"
#include <sstream>

std::vector<std::string> Utils::split(const std::string& str, char delimiter){
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string item;
    while(getline(ss,item,delimiter)){
        tokens.push_back(item);
    }
    return tokens;
}