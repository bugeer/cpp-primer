#include <cstddef>
#include <functional>
#include <iostream>
#include <stdexcept>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

class SmallInt {
public:
    SmallInt(int v = 0): val(v) {
        if(v < 0 || v > 255) {
            throw std::out_of_range("Bad SmallInt value");
        }
    }

    explicit operator int() {
        return val;
    }

private:
    std::size_t val;
};

int main (int argc, char *argv[]) {
    {
        std::plus<int> intAdd;
        std::negate<int> intNeg;
        int sum = intAdd(10, 20);
        sum = intNeg(intAdd(10, 20));

        std::cout << sum << std::endl;
    }

    {
        print_section("conversion operator");
        SmallInt si = 4;
        int t = static_cast<int>(si) + 3;
        float s = static_cast<int>(si) + 9.0;
    }


    return 0;
}
