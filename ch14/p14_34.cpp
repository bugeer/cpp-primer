#include <iostream>

class BranchCall {
public:
    BranchCall() { }

    int operator()(bool condition, int valTrue, int valFalse) {
        return condition ? valTrue : valFalse;
    }

private:

};

int main (int argc, char *argv[]) {
    BranchCall bc;

    std::cout << bc(6 == 6, 42, -42) << std::endl;

    return 0;
}
