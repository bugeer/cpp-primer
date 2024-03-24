#include "Sales_data_s.h"
#include <iostream>
#include <istream>

double Sales_data_s::avg_price() const {
    if(units_sold) {
        return revenue / units_sold;
    } else {
        return 0;
    }
}

Sales_data_s& Sales_data_s::combine(const Sales_data_s &rhs) {
    units_sold += rhs.units_sold;
    revenue    += rhs.revenue;

    return *this;
}

Sales_data_s add(const Sales_data_s &lhs, const Sales_data_s &rhs) {
    Sales_data_s sum = lhs;
    sum.combine(rhs);

    return sum;
}

std::ostream &print(std::ostream& os, const Sales_data_s& item) {
    os << ""
        << "isbn     : " << item.isbn()      << '\t'
        << "sold     : " << item.units_sold  << '\t'
        << "revenue  : " << item.revenue     << '\t'
        << "avg_price: " << item.avg_price() << '\t';

    return os;
}

std::istream& read(std::istream& is, Sales_data_s& item) {
    std::cout << "Please input the bookNo, sold number and price of the book" << std::endl;
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return is;
}
