#ifndef __PERSON__
#define __PERSON__

#include <ostream>
#include <string>

class Person {
public:
    std::string name;
    std::string address;

    std::string get_name()    const { return name;    }
    std::string get_address() const { return address; }

    Person() = default;
    Person(const std::string &name): name(name) {}
    Person(const std::string &name, const std::string &addr): address(addr) {}
};

std::ostream& print(const Person&);
std::istream& read(Person&);

#endif // !__PERSON__
