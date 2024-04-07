#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool size_no_less(const std::string& s) {
    return s.size() >= 5;
}

int main (int argc, char *argv[]) {
    std::vector<std::string> words = {"a", "123", "123456", "abcdefgijlkmx", "fffffffcuk"};
    auto anchor = std::partition(words.begin(), words.end(), size_no_less);

    std::cout << "string no less than 5:" << std::endl;
    for(auto it = words.cbegin(); it != anchor; it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
