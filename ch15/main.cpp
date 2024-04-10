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
    std::string bookNo;
};


