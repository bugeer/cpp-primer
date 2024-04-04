#include <iostream>
#include <list>
#include <string>

int main (int argc, char *argv[]) {
    std::list<std::string> str_list;
    std::string word;

    std::cout << "input strings to a deque" << std::endl;
    while(std::cin >> word) {
        str_list.push_back(word);
    }

    std::cout << "string list: " << std::endl;
    for(auto& s : str_list) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
