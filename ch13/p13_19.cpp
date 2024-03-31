#include "Employee.h"

int main (int argc, char *argv[]) {
    Employee e1;
    Employee e2("haha");
    Employee e3 = e2;

    e1.print();
    e2.print();
    e3.print();

    return 0;
}
