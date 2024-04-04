#include <iostream>
#include <list>
#include <vector>

int main (int argc, char *argv[]) {
    std::list  <int> i_list(5, 1);
    std::vector<int> i_vect(5, 2);

    std::vector<double> d_list(i_list.begin(), i_list.end());
    std::vector<int> i_vec2(i_vect);

    std::cout << "double vector:" << std::endl;
    for(auto d : d_list) {
        std::cout << d << " ";
    }
    std::cout << std::endl;

    std::cout << "int vector:" << std::endl;
    for(auto i : i_vec2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
