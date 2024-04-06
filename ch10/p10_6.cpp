#include <algorithm>
#include <iostream>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill_n(ivec.begin(), ivec.size(), 0);

    std::cout << "fill_n 0: " << std::endl;
    for(auto i : ivec) std::cout << i << "\t";
    std::cout << std::endl;

    return 0;
}
