#include "Sales_data.h"
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

    Sales_data s1("xxx-dd-123", 10, 20);
    Sales_data s2("xxx-dd-120", 20, 20);
    std::cout << "compare Sales_data" << compare(s1, s2);

    return 0;
}
