#include <iostream>

struct absInt{
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main (int argc, char *argv[]) {
    int i = -42;
    absInt ai;
    int ui = ai(i);

    std::cout << "i: " << i << " ui: " << ui << std::endl;

    return 0;
}
