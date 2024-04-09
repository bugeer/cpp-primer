#ifndef __SALES_DATA__
#define __SALES_DATA__

#include <istream>
#include <ostream>
#include <string>

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream& read(std::istream &, Sales_data &);
    friend std::ostream& print(std::ostream &, const Sales_data &);
    friend std::istream& operator>>(std::istream &, Sales_data &);
    friend std::ostream& operator<<(std::ostream &, const Sales_data &);

    friend Sales_data    operator+ (const Sales_data &, const Sales_data &);
    friend bool          operator==(const Sales_data &, const Sales_data &);
    friend bool          operator!=(const Sales_data &, const Sales_data &);

public:
    Sales_data();
    explicit Sales_data(const std::string &no): Sales_data(no, 0, 0.0) { }
    Sales_data(const std::string &no, unsigned us, double price)
        : bookNo(no), units_sold(us), revenue(price*us) { }
    Sales_data(std::istream &is): Sales_data() {
        read(is, *this);
    }

    Sales_data(Sales_data &&) = default;
    Sales_data(const Sales_data &) = default;
    Sales_data &operator=(Sales_data &&) = default;
    Sales_data &operator=(const Sales_data &) = default;
    ~Sales_data();

    Sales_data& operator+=(const Sales_data &);

    std::string isbn() const {
        return bookNo;
    }
    Sales_data& combine(const Sales_data &);

private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data operator+(const Sales_data &, const Sales_data &);
bool operator==(const Sales_data &, const Sales_data &);
bool operator!=(const Sales_data &, const Sales_data &);
std::istream& operator>>(std::istream &, Sales_data &);
std::ostream& operator<<(std::ostream &, const Sales_data &);
std::istream& read(std::istream &, Sales_data &);

inline
double Sales_data::avg_price() const {
    return units_sold > 0 ? revenue/units_sold : 0.0;
}

#endif // !__SALES_DATA__

