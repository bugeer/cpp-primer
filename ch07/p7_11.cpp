#include "Sales_data_s.h"
#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    Sales_data_s sd1;
    Sales_data_s sd2("Book1");
    Sales_data_s sd3("Book2", 7, 5.8);
    Sales_data_s sd4(cin);

    cout << "print 4 Sales_data_s: " << endl;
    print(cout, sd1) << endl;
    print(cout, sd2) << endl;
    print(cout, sd3) << endl;
    print(cout, sd4) << endl;

    cout << endl;

    return 0;
}
