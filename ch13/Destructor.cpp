#include "Sales_data.h"
#include <memory>
#include <vector>

bool fcn(const Sales_data *trans, Sales_data accum) {
    Sales_data item1(*trans), item2(accum);

    return item1.isbn() != item2.isbn();
}

int main (int argc, char *argv[]) {
    // std::cout << "L1" <<std::endl;
    // Sales_data *p = new Sales_data;
    // std::cout << "L2" <<std::endl;
    // auto p2 = std::make_shared<Sales_data>();
    // std::cout << "L3" <<std::endl;
    // Sales_data item(*p);
    // std::cout << "L4" <<std::endl;
    // std::vector<Sales_data> vec;
    // std::cout << "L5" <<std::endl;
    // vec.push_back(*p2);
    // std::cout << "L6" <<std::endl;
    // delete p;
    // std::cout << "L7" <<std::endl;

    Sales_data *p = new Sales_data;
    Sales_data it;

    fcn(p, it);

    std::cout << "-----------" << std::endl;


    return 0;
}
