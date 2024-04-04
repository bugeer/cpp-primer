#include <deque>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::deque<std::string> str_deque;
    std::string word;

    std::cout << "input strings to a deque" << std::endl;
    while(std::cin >> word) {
        str_deque.push_back(word);
    }

    std::cout << "string deque: " << std::endl;
    for(auto& s : str_deque) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
