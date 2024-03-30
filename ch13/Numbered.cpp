#include "Numbered.h"
#include <cstddef>
#include <iostream>

size_t Numbered::obj_count = 0;

Numbered::Numbered() {
    mysn = Numbered::obj_count++;
}

Numbered::Numbered(const Numbered& c)  {
    mysn = Numbered::obj_count++;
}

void f(Numbered &s) {
    std::cout << s.mysn << std::endl;
}
