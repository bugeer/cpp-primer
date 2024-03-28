#include "Sales_data.h"
#include <iostream>

int main (int argc, char *argv[]) {
    std::cout << "*** Create Object By (string, unsigned, double): " << std::endl;
    Sales_data sd_param_all("book", 10, 200);
    std::cout << std::endl;

    std::cout << "*** Create Object By (): " << std::endl;
    Sales_data sd_non_param;
    std::cout << std::endl;

    std::cout << "*** Create Object By (string): " << std::endl;
    Sales_data sd_param_str("haha");
    std::cout << std::endl;

    std::cout << "*** Create Object By (istream&): " << std::endl;
    Sales_data sd_param_is(std::cin);
    std::cout << std::endl;

    return 0;
}
