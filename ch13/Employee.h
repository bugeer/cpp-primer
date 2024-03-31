#ifndef __EMPLOYEE__
#define __EMPLOYEE__

#include <iostream>
#include <ostream>
#include <string>

class Employee {
public:
    static size_t e_count;

    Employee(): name(""), sid(Employee::e_count) {
        ++Employee::e_count;
    }

    Employee(std::string n): name(n), sid(Employee::e_count) {
        ++Employee::e_count;
    }

    Employee(const Employee& rhs): name(rhs.name), sid(Employee::e_count) {
        ++Employee::e_count;
    }

    std::ostream& print() {
        std::cout << "Employee name: " << name << " sid: " << sid << std::endl;

        return std::cout;
    }

private:
    std::string name;
    size_t sid;
};

#endif // !__EMPLOYEE__
