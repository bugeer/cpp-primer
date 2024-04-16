#include <cstddef>
#include <iostream>

template<typename T, std::size_t N> constexpr
std::size_t size(T (&arr)[N]) {
    return N;
}

int main (int argc, char *argv[]) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "arr.size == " << size(arr) << std::endl;

    return 0;
}
