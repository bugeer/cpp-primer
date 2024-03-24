#ifndef __SALES_DATA_S__
#define __SALES_DATA_S__

#include <istream>
#include <ostream>
#include <string>

struct Sales_data_s;

Sales_data_s add(const Sales_data_s&, const Sales_data_s&);
std::ostream &print(std::ostream&, const Sales_data_s&);
std::istream &read (std::istream&, Sales_data_s&);

struct Sales_data_s {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn() const { return bookNo; }
    Sales_data_s& combine(const Sales_data_s&);
    double avg_price() const;

    Sales_data_s() = default;
    Sales_data_s(const std::string &s): bookNo(s) {}
    Sales_data_s(
        const std::string &s,
        unsigned n,
        double p
    ): bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data_s(std::istream &is) { read(is, *this); }
};

#endif // !__SALES_DATA_S__
