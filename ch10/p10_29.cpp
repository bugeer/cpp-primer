#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "No input file!" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[1]);
    if(!ifs) {
        std::cerr << "Input file error!" << std::endl;
        return -1;
    }

    std::vector<std::string> svec;
    std::istream_iterator<std::string> in_str_iter(ifs), eof;
    while(in_str_iter != eof) {
        svec.push_back(*in_str_iter++);
    }

    std::cout << "the string vector: " << std::endl;
    for(auto& i : svec) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
