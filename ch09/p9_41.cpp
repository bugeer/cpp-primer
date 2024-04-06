#include <iostream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<char> char_vec = {'H', 'e', 'l', 'l', 'o', ',', 'w', 'o', 'r', 'l', 'd', '!'};

    std::string s;
    for(auto i : char_vec) {
        s += i;
    }

    std::cout << "s : " << s << std::endl;

    std::string s1(char_vec.cbegin(), char_vec.cend());
    std::cout << "s1: " << s1 << std::endl;

    // p9.42
    std::string s120;
    s120.reserve(120);

    return 0;
}




