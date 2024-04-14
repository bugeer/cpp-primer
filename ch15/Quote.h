#ifndef __QUOTE__
#define __QUOTE__

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price) { }

    std::string isbn() const {
        return bookNo;
    }
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual std::ostream& debug() const {
        return std::cout << "Quote: bookNo: " << bookNo << ", price: " << price;
    }

    virtual Quote* clone() const & {
        return new Quote(*this);
    }
    virtual Quote* clone() && {
        return new Quote(std::move(*this));
    }

protected:
    double price = 0.0;

private:
    std::string bookNo;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc)
        : Quote(book, p), discount(disc), min_qty(qty) { }

    double net_price(std::size_t n) const override {
        if(n > min_qty) {
            return n * (1 - discount) * price;
        } else {
            return n * price;
        }
    }

    std::ostream& debug() const override {
        return std::cout << "Bulk_quote: min_qty: " << min_qty << ", discount: " << discount;
    }
    Bulk_quote* clone() const & override {
        return new Bulk_quote(*this);
    }
    Bulk_quote* clone() && override {
        return new Bulk_quote(std::move(*this));
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;

};

double print_total(std::ostream&, const Quote&, size_t);

#endif // !__QUOTE__
