#include <cstring>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    std::string str1;
    std::string str2;

    std::cout << "Please input 2 string: " << std::endl;
    std::cin >> str1 >> str2;
    char* sp = new char[str1.size() + str2.size() + 1];
    std::strcpy(sp, str1.c_str());
    std::strcpy(sp+str1.size(), str2.c_str());
    std::cout << "the whole char array: " << std::endl;
    std::cout << sp << std::endl;
    delete []sp;

    std::string str3 = str1 + str2;
    std::cout << "the whole string: " << std::endl;
    std::cout << str3 << std::endl;

    return 0;
}
