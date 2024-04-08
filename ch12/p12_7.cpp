#include <iostream>
#include <memory>
#include <vector>

typedef std::shared_ptr<std::vector<int>> vec_shared_ptr;

void using_vec_p(vec_shared_ptr p) {
    std::cout << "input number for push back: " << std::endl;
    int iv;
    while (std::cin >> iv) {
        p->push_back(iv);
    }
}

void print_vec_p(vec_shared_ptr p) {
    std::cout << "int vector: " << std::endl;
    for(auto i : *p) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

vec_shared_ptr create_int_vec() {
    return std::make_shared<std::vector<int>>();
}

int main (int argc, char *argv[]) {
    auto pvec = create_int_vec();

    using_vec_p(pvec);
    print_vec_p(pvec);

    return 0;
}
