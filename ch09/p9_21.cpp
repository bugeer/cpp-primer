#include <iostream>
#include <vector>
#include <string>

int main (int argc, char *argv[]) {
    std::vector<std::string> str_vector;
    auto iter = str_vector.begin();
    std::string word;
    while(std::cin >> word) {
        iter = str_vector.insert(iter, word);
    }

    std::cout << "the vector: " << std::endl;
    for(auto &i : str_vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
