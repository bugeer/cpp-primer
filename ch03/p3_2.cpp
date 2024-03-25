#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::string word;

    // if(std::getline(std::cin, line)) {
    //     std::cout << "read a line from cin:" << std::endl;
    //     std::cout << line << std::endl;
    // }

    do
    {
        std::cin >> word;
        line += (word + " ");
    } while(std::cin.get() != '\n');

    std::cout << "the line: " << std::endl;
    std::cout << line << std::endl;;

    return 0;
}
