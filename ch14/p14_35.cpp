#include <iostream>
#include <istream>
#include <string>

class PrintString {
public:
    std::string operator()(std::istream &is = std::cin) {
        std::string line;
        std::getline(is, line);

        if(is.fail()) {
            return "";
        } else {
            return line;
        }
    }

private:

};

int main (int argc, char *argv[]) {
    PrintString ps;
    std::string str = ps();

    std::cout << "your input: " << std::endl;
    std::cout << str << std::endl;

    return 0;
}
