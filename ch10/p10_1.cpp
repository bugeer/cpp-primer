#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> ivec = {0, 1, 2, 3, 3, 3, 3, 9, 5, 9};

    std::cout << "count of 3: "
        << std::count(ivec.cbegin(), ivec.cend(), 3)
        << std::endl;

    std::vector<std::string> svec = {"aaa", "a", "aaa", "a", "aaa"};

    std::cout << "count of aaa: "
        << std::count(svec.cbegin(), svec.cend(), "aaa")
        << std::endl;

    return 0;
}
