#include <iostream>

typedef double wages;
typedef wages base, *dp;

using uwages = wages;

double f() {
    return 3.14;
}

int main()
{
    // int i = -42;
    // unsigned int u = 10;
    //
    // std::cout << "i+i : " << i+i << std::endl;
    // std::cout << "u+i : " << u+i << std::endl;
    //
    // std::cout << "------------------------------" << std::endl;
    //
    // unsigned int u1 = 10;
    // unsigned int u2 = 42;
    //
    // std::cout << "u1-u2 : " << u1-u2 << std::endl;
    // std::cout << "u2-u1 : " << u2-u1 << std::endl;
    //
    // std::cout << "------------------------------" << std::endl;

    const int bufSize = 512;
    // bufSize = 55;

    int i = 42;
    const int ci = 1024;
    const int &ri = ci;
    // ri = 42;
    // int &r2 = ci;

    double dvalue = 3.14;
    const double &rii = dvalue;

    wages dvalue2 = 3.1416;

    dvalue = dvalue2;
    dp p2double = &dvalue;
    p2double = &dvalue2;

    auto ivalue = 0, *pivalue = &i;
    // auto ivalue2 = 0, dvalue3 = 3.14;

    {
        const int i = 42;
        auto j = i; // int;

        const auto &k = i;// k is const int &k;

        int kk;
        auto *p = &i; // p is const int *
        p = &kk;

        const auto j2 = i, &k2 = i; // j2 is const int; k2 is cont int&
    }
    {
        decltype(f()) sum;

        int a = 3, b = 4;
        decltype(a) c = a;
        decltype((b)) d = a;

        ++c;
        ++d;

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "d: " << d << std::endl;
    }
    {
        struct Sales_data {
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
        };

        struct Sales_data accum, trans, *salesptr;
    }

    return 0;
}
