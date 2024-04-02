#include <string>

struct X {
    int i;
    std::string s;
};

struct HasX {
    X mem;
};

X x, x2 = std::move(x);
HasX hx, hx2 = std::move(hx);
