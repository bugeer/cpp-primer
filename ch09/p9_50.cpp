#include <iostream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<std::string> char_numbs  = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<std::string> char_double = {"1.3", "2.3", "3.3", "4.3", "5.3", "6.3", "7.3", "8.3", "9.3"};

    int sum = 0;
    double d_sum = 0.0;

    for(auto &i : char_numbs) {
        sum += std::stoi(i);
    }
    std::cout << "sum: " << sum << std::endl;

    for(auto &i : char_double) {
        d_sum += std::stod(i);
    }
    std::cout << "sum: " << d_sum << std::endl;

    return 0;
}

