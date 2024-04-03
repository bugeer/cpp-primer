#include "Sales_data.h"
#include <fstream>
#include <iostream>

int main (int argc, char *argv[]) {
    if(argc < 3) {
        std::cerr << "No files!" << std::endl;
        return -1;
    }

    std::ifstream in (argv[1]);
    std::ofstream out(argv[2]);
    Sales_data sd;

    out << "Book store log:" << std::endl << std::endl;

    while(read(in, sd)) {
        print(out, sd) << std::endl;
    }

    out.close();

    return 0;
}
