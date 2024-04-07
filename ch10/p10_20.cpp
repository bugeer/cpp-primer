#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int max = 6;

    int count = std::count_if(ivec.cbegin(), ivec.cend(), [max](int i) {
        return i >= max;
    });

    std::cout << "no less than " << max << ": " << count << std::endl;

    std::vector<std::string> svec = {
        "aaa", "bbbbbbbb", "fuuuuuuuuuuuuck", "aa", "TTTTTTTTTTTT"
    };

    int scount = std::count_if(svec.cbegin(), svec.cend(), [max](auto s) {
        return s.size() >= max;
    });

    std::cout << "size no less than " << max << ": " << scount << std::endl;

    return 0;
}
