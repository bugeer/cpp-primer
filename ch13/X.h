#ifndef __CLASS_X__
#define __CLASS_X__

#include <iostream>

class X {
    X () { std::cout << "X()"  << std::endl; }
    ~X() { std::cout << "~X()" << std::endl; }
    X(const X&) {std::cout << "X(const X&)" << std::endl; }
};

#endif // !__CLASS_X__
