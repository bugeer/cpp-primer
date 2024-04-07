#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

void print_words(std::vector<std::string>& words) {
    for(auto &i : words) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
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

bool check_size(const std::string &s, std::string::size_type sz) {
    return s.size() < sz;
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
    elimDups(words);

    auto wc = std::partition(
        words.begin(),
        words.end(),
        std::bind(check_size, std::placeholders::_1, sz)
    );
    auto count = words.end() - wc;

    std::cout << "words no less than " << sz <<": " << std::endl;
    std::for_each(
            wc,
        words.end(),
        [](const std::string &s) {
            std::cout << s << " ";
        }
    );

    std::cout << std::endl;
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

    biggies(words, 4);

    return 0;
}
