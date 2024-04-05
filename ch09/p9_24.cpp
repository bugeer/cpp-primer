#include <iostream>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> ivec;

    std::cout << ivec.at(0);
    std::cout << ivec[0];
    std::cout << ivec.front();
    std::cout << *ivec.begin();

    return 0;
}
