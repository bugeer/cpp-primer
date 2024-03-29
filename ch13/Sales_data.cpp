#include "Sales_data.h"
#include <iostream>

Sales_data::Sales_data(const Sales_data& sd) 
: bookNo(sd.bookNo), units_sold(sd.units_sold), revenue(sd.revenue) {}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue    += rhs.revenue;

    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);

    return sum;
}

std::ostream &print(std::ostream& os, const Sales_data& item) {
    os << ""
        << "isbn     : " << item.isbn()      << '\t'
        << "sold     : " << item.units_sold  << '\t'
        << "revenue  : " << item.revenue     << '\t'
        << "avg_price: " << item.avg_price() << '\t';

    return os;
}

std::istream& read(std::istream& is, Sales_data& item) {
    std::cout << "Please input the bookNo, sold number and price of the book" << std::endl;
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;

    return is;
}
