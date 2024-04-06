#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
std::string SHORT_CHARS = "aceimnorsuvwxz";

int main (int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "No File Name!" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[1]);
    if(!ifs) {
        std::cerr << "Can't open file: " << argv[1] << std::endl;
        return -1;
    }

    std::vector<std::string> longest;
    int longth = 0;

    for(std::string str; ifs >> str; ) {
        auto pos = str.find_first_not_of(SHORT_CHARS);
        if(pos == std::string::npos) {
            if(str.size() == longth) {
                longest.push_back(str);
            }
            if(str.size() > longth) {
                longest.clear();
                longth = str.size();
                longest.push_back(str);
            }
        }
    }

    std::cout << "max longth: "<< longth << std::endl;
    std::cout << "the longest short strings are: " << std::endl;
    for(auto & i : longest) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    return 0;
};
