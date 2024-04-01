#include "HasPtr.h"
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
    HasPtr hp0 = "I'm Fucking Hp0";
    HasPtr hp1 = std::string("I'm Hp1");
    HasPtr hp2 = hp0;
    HasPtr hp3 = hp1;
    HasPtr hp4;
    hp4 = hp0;
    hp0.setStr("I'm Hp0");

    std::cout << std::endl;

    std::cout << "init: " << std::endl;
    std::cout << "hp0: " << hp0.getStr() << std::endl;
    std::cout << "hp1: " << hp1.getStr() << std::endl;
    std::cout << "hp2: " << hp2.getStr() << std::endl;
    std::cout << "hp3: " << hp3.getStr() << std::endl;
    std::cout << "hp4: " << hp4.getStr() << std::endl;

    std::cout << std::endl;

    hp1 = hp1;
    std::cout << "hp1 = hp1: " << hp1.getStr() << std::endl;

    std::cout << std::endl;

    swap(hp0, hp1);
    std::cout << "swap(hp0, hp1)" << std::endl;
    std::cout << "hp0: " << hp0.getStr() << std::endl;
    std::cout << "hp1: " << hp1.getStr() << std::endl;

    std::cout << std::endl;

    swap(hp0, hp0);
    std::cout << "swap(hp0, hp0)" << std::endl;
    std::cout << "hp0: " << hp0.getStr() << std::endl;

    return 0;
}
