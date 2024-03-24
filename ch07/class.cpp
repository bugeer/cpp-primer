#include "Sales_data_s.h"
#include <iostream>

using namespace std;
int main (int argc, char *argv[]) {
    Sales_data_s total;

    cout << "init total: " << endl;
    print(cout, total);

    cout << endl << endl;

    if(read(cin, total)) {
        Sales_data_s trans;

        while (read(cin, trans)) {
            if(total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }

        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }

    return 0;
}
