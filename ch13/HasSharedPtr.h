#ifndef __HAS_SHARED_PTR__
#define __HAS_SHARED_PTR__

#include <cstddef>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0), use(new std::size_t(1)) { }

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

#endif // !__HAS_SHARED_PTR__
