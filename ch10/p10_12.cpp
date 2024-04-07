#include "../ch08/BookStore/Sales_data.h"
#include <algorithm>
#include <iostream>
#include <vector>

bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2) {
    return sd1.isbn() < sd2.isbn();
}

int main (int argc, char *argv[]) {
    std::vector<Sales_data> sds{
        {"book01", 100, 20},
        {"book03", 200, 40},
        {"book02", 300, 70}
    };

    std::cout << "init: " << std::endl;
    for(auto& i : sds) {
        print(std::cout, i) << std::endl;
    }

    auto cpIsbn = [](const Sales_data& sd1, const Sales_data& sd2) {
        return sd1.isbn() < sd2.isbn();
    };

    std::stable_sort(
        sds.begin(),
        sds.end(),
        [](const Sales_data& sd1, const Sales_data& sd2) {
            return sd1.isbn() < sd2.isbn();
        }
    );
    std::cout << "sort: " << std::endl;
    for(auto& i : sds) {
        print(std::cout, i) << std::endl;
    }

    return 0;
}
