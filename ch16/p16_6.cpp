#include <cstddef>
#include <iostream>

template <typename T, size_t N>
T* begin(T (&arr)[N]) {
    return arr;
}

template <typename T, size_t N>
T* end(T (&arr)[N]) {
    return arr+N;
}

int main (int argc, char *argv[]) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto it=begin(arr); it != end(arr); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    for(auto it=end(arr); it != begin(arr); --it) {
        std::cout << *(it-1) << " ";
    }
    std::cout << std::endl;

    return 0;
}
