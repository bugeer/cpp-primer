#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> ivec{2, 3, 4};
    int product = std::accumulate(ivec.begin(), ivec.end(), 1, std::multiplies<int>());

    std::cout << "product: " << product << std::endl;

    int num;
    std::string str_num;
    std::ostringstream oss;
    std::copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>(oss, " * "));

    while(std::cin >> num) {
        if(num % product == 0) {
            std::cout << num << " can be divid by " << oss.str() << ":" << std::endl;
        } else {
            std::cout << num << " can NOT be divid by " << oss.str() << ":" << std::endl;
        }
    }

    return 0;
}
