#include "Quote.h"

double print_total(std::ostream& os, const Quote& q, size_t n) {
    double ret = q.net_price(n);
    os << "ISBN: " << q.isbn()
        << " # sold: " << n << " total due: " << ret << std::endl;

    return 0.0;
}
