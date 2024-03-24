#include <cstdlib>

extern const int bufSize0 = 1024;

int get_size() {
    return rand() + 100;
}

constexpr int get_const_size() {
    return 1024;
}

int main() {
    const int bufSize1 = 512;
    const int bufSize2 = get_size(); // init on runtime.

    const int ci = 1024;
    const int &r1 = ci;

    // r1 = 42;
    // int &r2 = ci;

    const int &r = 0;
    int i2 = 1024;
    const int* const cii = &i2;
    i2 = 880;


    constexpr int mf = 20;
    constexpr int limite = mf + 1;
    constexpr int sz = get_const_size();

    int null = 0, *p = &null;

    return 0;
}
