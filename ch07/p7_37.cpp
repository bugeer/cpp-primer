#include "Sales_data.h"
#include <iostream>

Sales_data first_item(std::cin);

int main (int argc, char *argv[]) {
    Sales_data next;
    Sales_data last("9-999-99999-9");

    std::cout << std::endl << "first_item:" << std::endl;
    print(std::cout, first_item);
    std::cout << std::endl << "next:"       << std::endl;
    print(std::cout, next);
    std::cout << std::endl << "last:"       << std::endl;
    print(std::cout, last);

    return 0;
}
