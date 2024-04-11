#include "Quote.h"
#include <iostream>

int main (int argc, char *argv[]) {
    Quote q("book0", 20);
    Bulk_quote bq("book1", 20, 5, 0.2);

    print_total(std::cout, q,  10);
    print_total(std::cout, bq, 10);

    return 0;
}
