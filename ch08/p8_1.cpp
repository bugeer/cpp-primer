#include <iostream>
#include <istream>
#include <string>

std::istream& do_istram(std::istream &is) {
    is.clear();
    std::string str;
    std::string total;
    while(is >> str) {
        total += str + " ";
    }

    std::cout << "You just input:" << std::endl;
    std::cout << total << std::endl;
    is.clear();

    return is;
}

int main (int argc, char *argv[]) {
    do_istram(std::cin);

    return 0;
}
