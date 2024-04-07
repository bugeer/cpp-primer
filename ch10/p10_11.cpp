#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void print_words(std::vector<std::string>& words) {
    for(auto &i : words) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

bool isShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string>& words) {
    std::cout << "init: " << std::endl;
    print_words(words);
    std::sort(words.begin(), words.end());
    std::cout << "sord: " << std::endl;
    print_words(words);
    auto end_unique = std::unique(words.begin(), words.end());
    std::cout << "unique: " << std::endl;
    print_words(words);
    words.erase(end_unique, words.end());
    std::cout << "erase: " << std::endl;
    print_words(words);
}

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

    std::vector<std::string> words;
    std::string word;

    while(ifs >> word) {
        words.push_back(word);
    }

    elimDups(words);

    std::stable_sort(words.begin(), words.end(), isShorter);
    std::cout << "sort: " << std::endl;
    print_words(words);

    return 0;
}
