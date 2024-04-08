#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main (int argc, char *argv[]) {
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {
        "The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a",
    };

    std::string word;

    while(std::cin >> word) {
        if(exclude.find(word) == exclude.end()) {
            auto ret = word_count.insert({word, 1});
            if(!ret.second) {
                ++ret.first->second;
            }
            // std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            // ++word_count[word];
        }
    }

    std::cout << std::endl;
    for(const auto &w : word_count) {
        std::cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times." : " time.") << std::endl;
    }

    return 0;
}


