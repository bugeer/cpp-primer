#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

class PrintString {
public:
    PrintString(std::ostream &o = std::cout, char c = ' '): os(o), sep(c) { }
    void operator()(const std::string &s) const {
        os << s << sep;
    }

private:
    std::ostream& os;
    char sep;
};

int main (int argc, char *argv[]) {
    std::string s = "hello world.";
    PrintString printer;
    printer(s);
    std::cout << std::endl;

    PrintString errors(std::cerr, '!');
    errors(s);
    std::cout << std::endl;

    std::vector<std::string> sv = {"hello", "fucking", "world"};
    std::for_each(sv.begin(), sv.end(), printer);
    std::cout << std::endl;
    std::for_each(sv.begin(), sv.end(), errors);
    std::cout << std::endl;

    return 0;
}
