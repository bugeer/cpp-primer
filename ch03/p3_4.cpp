#include <cstdio>
#include <iostream>
#include <string>

int main()
{
    std::string str0;
    std::string str1;

    std::cout << "Please input the first string: " << std::endl;
    getline(std::cin, str0);

    std::cout << "Please input the second string: " << std::endl;
    getline(std::cin, str1);

    std::cout << "The bigger string is :" << std::endl;
    std::cout << (str0.compare(str1) > 0 ? str0 : str1) << std::endl;

    return 0;
}
