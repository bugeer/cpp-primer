#include <functional>
#include <iostream>

int main (int argc, char *argv[]) {
    std::plus<int> intAdd;
    std::negate<int> intNeg;
    int sum = intAdd(10, 20);
    sum = intNeg(intAdd(10, 20));

    std::cout << sum << std::endl;

    return 0;
}
