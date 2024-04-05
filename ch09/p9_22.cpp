#include <iostream>
#include <vector>

std::vector<int>::iterator get_mid(std::vector<int>& v) {
    return v.begin() + v.size()/2;
}

void double_insert(std::vector<int> &iv, int some_val) {
    std::vector<int>::iterator iter = iv.begin();

    while(iter != get_mid(iv)) {
        if(*iter == some_val) {
            iter = iv.insert(iter, 2*some_val);
            iter++;
        }
        iter++;
    }
}

void double_and_insert(std::vector<int>& v, int some_val) {
    auto mid = [&]{ return v.begin() + v.size()/2; };

    for(auto curr = v.begin(); curr != mid(); ++curr) {
        if(*curr == some_val) {
            ++(curr = v.insert(curr, 2*some_val));
        }
    }
}

int main (int argc, char *argv[]) {
    std::vector<int> ivec{1, 9, 1, 9, 9, 9, 1, 1};

    double_insert(ivec, 1);

    for(auto i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::vector<int> v{1, 9, 1, 9, 9, 9, 1, 1};
    double_and_insert(v, 1);

    for(auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
