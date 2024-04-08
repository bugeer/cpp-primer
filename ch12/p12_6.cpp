#include <iostream>
#include <vector>

void using_vec_p(std::vector<int> *p) {
    std::cout << "input number for push back: " << std::endl;
    int iv;
    while (std::cin >> iv) {
        p->push_back(iv);
    }
}

void print_vec_p(std::vector<int> *p) {

    std::cout << "int vector: " << std::endl;
    for(auto i : *p) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<int>* create_int_vec() {
    return new std::vector<int>();
}

int main (int argc, char *argv[]) {
    auto *pvec = create_int_vec();

    using_vec_p(pvec);
    print_vec_p(pvec);

    delete pvec;

    return 0;
}
