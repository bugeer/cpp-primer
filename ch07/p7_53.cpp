#include "Debug.h"
#include <iostream>

int main (int argc, char *argv[]) {
    constexpr Debug io_sub(false, true, false);

    Debug d;
    d.set_hw(true);
    d.set_io(true);
    d.set_other(true);

    if(io_sub.any()) {
        std::cerr << "Print error message" << std::endl;
    }
    return 0;
}
