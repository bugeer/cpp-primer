#include <functional>
#include <iostream>
#include <map>
#include <string>

int add(int a, int b) {
    return a + b;
}

struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

int main (int argc, char *argv[]) {
    auto mod = [](int i, int j) {
        return i % j;
    };
    auto mul = [](int i, int j) {
        return i * j;
    };

    std::function<int(int, int)> f_add = add;
    std::function<int(int, int)> f_dvd = divide();
    std::function<int(int, int)> f_mod = mod;
    std::function<int(int, int)> f_mul = mul;

    std::cout << f_add(4, 2) << std::endl;
    std::cout << f_dvd(4, 2) << std::endl;
    std::cout << f_mod(4, 2) << std::endl;
    std::cout << f_mul(4, 2) << std::endl;
    std::cout << std::endl;

    std::map<std::string, std::function<int(int, int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divide()},
        {"*", mul},
        {"%", mod},
    };

    std::cout <<"10+5=" << binops["+"](10, 5) << std::endl;
    std::cout <<"10-5=" << binops["-"](10, 5) << std::endl;
    std::cout <<"10/5=" << binops["/"](10, 5) << std::endl;
    std::cout <<"10*5=" << binops["*"](10, 5) << std::endl;
    std::cout <<"10%5=" << binops["%"](10, 5) << std::endl;

    int arg1, arg2;
    std::string op;

    while(std::cin >> arg1 >> op >> arg2) {
        std::function<int(int, int)> p_func = binops[op];
        if(p_func) {
            std::cout << arg1 << op << arg2 << "=" << p_func(arg1, arg2) << std::endl;
        } else {
            std::cerr << "input error! try again!" << std::endl;
            std::cin.clear();
        }
    }

    return 0;
}
