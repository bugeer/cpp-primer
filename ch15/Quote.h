#ifndef __QUOTE__
#define __QUOTE__

#include <cstddef>
#include <ostream>
#include <string>

class Quote {
public:
    Quote();
    Quote(Quote &&) = default;
    Quote(const Quote &) = default;
    Quote &operator=(Quote &&) = default;
    Quote &operator=(const Quote &) = default;
    ~Quote();

    std::string isbn() const;
    virtual double net_price(std::size_t n) const;

private:

};

class Bulk_quote : public Quote {
public:
    Bulk_quote();
    Bulk_quote(Bulk_quote &&) = default;
    Bulk_quote(const Bulk_quote &) = default;
    Bulk_quote &operator=(Bulk_quote &&) = default;
    Bulk_quote &operator=(const Bulk_quote &) = default;
    ~Bulk_quote();

    double net_price(std::size_t) const override;

private:

};

double print_total(std::ostream&, const Quote&, size_t);

#endif // !__QUOTE__
