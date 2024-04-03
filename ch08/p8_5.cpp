#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void process(std::ifstream& ifs, std::vector<std::string> &words) {
    std::string word;

    while(ifs >> word) {
        words.push_back(word);
    }
}

void print_file(std::vector<std::string> &words) {
    std::cout << "The content of the file: " << std::endl;
    for(auto it=words.begin(); it!=words.end(); it++) {
        std::cout << *it << std::endl;
    }

    std::cout << "EOF" << std::endl;
}

int main (int argc, char *argv[]) {
    std::vector<std::string> words;

    for(auto p=argv+1; p!=argv+argc; ++p) {
        std::ifstream input(*p);

        if(input) {
            process(input, words);
        } else {
            std::cerr << "couldn't open: " + std::string(*p);
        }
    }

    print_file(words);

    return 0;
}
