#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main (int argc, char *argv[]) {
    std::istream_iterator<int> int_iter(std::cin), eof;
    std::vector<int> ivec(int_iter, eof);
    std::sort(ivec.begin(), ivec.end(), [](int a, int b) { return a < b; });

    std::cout << std::endl;

    std::ostream_iterator<int> out_iter(std::cout, " | ");
    std::copy(ivec.cbegin(), ivec.cend(), out_iter);

    std::cout << std::endl;

    return 0;
}
