#ifndef __DISC_QUOTE__
#define __DISC_QUOTE__

#include <cstddef>
#include <iostream>
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

protected:
    double price = 0.0;

private:
    std::string bookNo;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc) { }

    double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(std::string &book, double price, std::size_t qty, double disc)
        : Disc_quote(book, price, qty, disc) { }

    double net_price(std::size_t n) const override {
        if(n > quantity) {
            return (1-discount) * quantity * price;
        } else {
            return quantity * price;
        }
    }

private:

};

class Limite_quote : Disc_quote {
public:
    Limite_quote() = default;
    Limite_quote(std::string &book, double price, std::size_t qty, double disc)
        : Disc_quote(book, price, qty, disc) { }

    double net_price(std::size_t n) const override {
        if(n < quantity) {
            return (1-discount) * quantity * price;
        } else {
            return quantity * price;
        }
    }

private:

};

#endif // !__DISC_QUOTE__
