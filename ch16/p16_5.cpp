#include <iostream>
#include <string>
template<typename T, size_t N>
void print_array(const T (&arr)[N]) {
    for(int i=0; i<N; i++) {
        std::cout << arr[i] << " ";
    }
}

int main (int argc, char *argv[]) {
    int ia[] = {1, 2, 3};
    float fa[] = {1.1, 2.2, 3, 3};
    std::string sa[] = {"hahaha", "222", "hello"};

    std::cout << std::endl;
    print_array<int>(ia);
    std::cout << std::endl;
    print_array(fa);
    std::cout << std::endl;
    print_array(sa);
    std::cout << std::endl;

    return 0;
}
