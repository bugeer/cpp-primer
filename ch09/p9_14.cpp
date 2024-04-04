#include <iostream>
#include <list>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::list<const char*>   str_list{10, "1111"};
    std::vector<std::string> str_vect;
    str_vect.assign(str_list.cbegin(), str_list.cend());

    std::cout << "after assign:" << std::endl;
    std::cout << "str_list: ";
    for(auto& i : str_list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "str_vect: ";
    for(auto& i : str_vect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
