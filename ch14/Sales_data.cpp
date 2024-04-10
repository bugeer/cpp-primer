#include "Sales_data.h"

Sales_data &Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;  // Use default copy constructor
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
    return sd1.isbn() < sd2.isbn();
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    return combine(rhs);
}

Sales_data& Sales_data::operator=(const std::string &isbn) {
    bookNo = isbn;

    return *this;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data ret(lhs);
    return ret += rhs;
}

std::istream& operator>>(std::istream &is, Sales_data &rhs) {
    return read(is, rhs);
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    return print(os, item);
}
