#include "Sales_data.h"
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "No files!" << std::endl;
        return -1;
    }

    std::ifstream in(argv[1]);
    Sales_data sd;

    while(read(in, sd)) {
        print(std::cout, sd) << std::endl;
    }

    return 0;
}
