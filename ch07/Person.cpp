#include "Person.h"

#include <iostream>

std::ostream& print(const Person& person) {
    std::cout << "Name: " << person.get_name() << " Address: " << person.get_address();

    return std::cout;
}

std::istream& read(Person& person) {
    std::cout << "Please input this person's name and address: " << std::endl;
    std::cin >> person.name >> person.address;

    return std::cin;
}
