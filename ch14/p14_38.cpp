#include <algorithm>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class StrRange {
public:
    StrRange(std::size_t low, std::size_t high)
        : min(low), max(high){ }

    bool operator()(std::string str) {
        return str.size() >= min && str.size() <= max;
    }

private:
    std::size_t min;
    std::size_t max;
};

void print_cout(std::vector<std::string>& svec, std::size_t min, std::size_t max) {
    std::cout << "length [" << min << ", " << max << "]: " << std::count_if(svec.begin(), svec.end(), StrRange(min, max)) << std::endl;
}

int main (int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "No Input file!" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[1]);
    if(!ifs) {
        std::cerr << "Can't open file: " << argv[1] << std::endl;
    }
    std::istream_iterator<std::string> it(ifs), eof;

    std::vector<std::string> svec(it, eof);

    print_cout(svec, 4, 4);
    print_cout(svec, 5, 5);
    print_cout(svec, 6, 6);
    print_cout(svec, 1, 8);
    print_cout(svec, 9, 9);
    print_cout(svec, 9, -1);


    return 0;
}
