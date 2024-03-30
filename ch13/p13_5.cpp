#include <iostream>
#include "HasPtr.h"

int main (int argc, char *argv[]) {
    HasPtr hp0("fuck hp0");
    HasPtr hp1 = hp0;

    std::cout << "hp0 addr: " << hp0.getStr() << " hp0 str:" << *hp0.getStr() << std::endl;
    std::cout << "hp1 addr: " << hp1.getStr() << " hp1 str:" << *hp1.getStr() << std::endl;

    return 0;
}
