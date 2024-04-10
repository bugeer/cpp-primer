#include <algorithm>
#include <iostream>
#include <vector>
class Equal {
public:
    Equal(int v): val(v) { }

    bool operator()(int rhs) {
        return val == rhs;
    }

private:
    int val;
};

int main (int argc, char *argv[]) {
    std::vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7};
    int oldVal, newVal;
    std::cout << "Input old value and new value:" << std::endl;
    std::cin >> oldVal >> newVal;

    std::replace_if(iv.begin(), iv.end(), Equal(oldVal), newVal);

    std::cout << "After repalce:" << std::endl;
    for(const auto &i : iv) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
