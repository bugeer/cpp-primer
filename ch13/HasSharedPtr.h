#ifndef __HAS_SHARED_PTR__
#define __HAS_SHARED_PTR__

#include <cstddef>
#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0), use(new std::size_t(1)) { }

    HasPtr(const HasPtr &p)
        : ps(p.ps), i(p.i), use(p.use) {
        ++*use;
    }

    HasPtr& operator= (const HasPtr&);

    // HasPtr& operator= (HasPtr rhs);

    ~HasPtr();

    friend void swap(HasPtr&, HasPtr&);

private:
    std::string *ps;
    int i;
    std::size_t *use;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "HasPtr swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;

    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i,  rhs.i );
}

#endif // !__HAS_SHARED_PTR__
