#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void process(std::ifstream& ifs, std::vector<std::string> &lines) {
    std::string line;

    while(std::getline(ifs, line)) {
        lines.push_back(line);
    }
}

void print_file(std::vector<std::string> &lines) {
    std::cout << "The content of the file: " << std::endl;
    for(auto it=lines.begin(); it!=lines.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "EOF" << std::endl;
}

int main (int argc, char *argv[]) {
    std::vector<std::string> lines;

    for(auto p=argv+1; p!=argv+argc; ++p) {
        std::ifstream input(*p);

        if(input) {
            process(input, lines);
        } else {
            std::cerr << "couldn't open: " + std::string(*p);
        }
    }

    print_file(lines);

    return 0;
}
