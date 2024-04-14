#include <cstring>
#include <iostream>
#include <vector>

template <typename T>
int compare(const T& v1, const T& v2) {
    if(v1 > v2) {
        return -1;
    }
    if(v2 > v1) {
        return 1;
    }

    return 0;
}

template <unsigned N, unsigned M>
int compare2(const char (&p1)[N], const char (&p2)[M]) {
    return strcmp(p1, p2);
}

int main (int argc, char *argv[]) {
    std::vector<int> v1{1, 2, 3};
    std::vector<int> v2{1, 2, 3};
    std::cout << compare(0, 1) << std::endl;
    std::cout << compare(v1, v2) << std::endl;

    std::cout << compare2("hi", "mom") << std::endl;

    return 0;
}
