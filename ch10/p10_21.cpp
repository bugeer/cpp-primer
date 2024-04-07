#include <iostream>

int main (int argc, char *argv[]) {
    int loop_count = 5;

    auto l = [&loop_count] () {
        return --loop_count == 0;
    };

    bool is_zero;

    while(!(is_zero = l())) {
        std::cout << loop_count << " " << (is_zero ? "ture" : "false") << std::endl;
    }

    std::cout << loop_count << " " << (is_zero ? "ture" : "false") << std::endl;

    return 0;
}
