#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool check_size(const std::string& s, std::string::size_type sz) {
    return s.size() >= sz;
}

int main (int argc, char *argv[]) {
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::string::size_type max = 6;

    int count = std::count_if(ivec.cbegin(), ivec.cend(), [max](int i) {
        return i >= max;
    });

    std::cout << "no less than " << max << ": " << count << std::endl;

    std::vector<std::string> svec = {
        "aaa", "bbbbbbbb", "fuuuuuuuuuuuuck", "aa", "TTTTTTTTTTTT"
    };

    auto anchor = std::find_if(
        svec.begin(),
        svec.end(),
        std::bind(check_size, std::placeholders::_1, max)
    );

    std::cout << "the first string of not less than "
        << max << ": " << *anchor << std::endl;

    return 0;
}
