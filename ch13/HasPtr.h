#ifndef __HAS_PTR__
#define __HAS_PTR__

#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) { }

    HasPtr(const HasPtr &hp)
        : ps(new std::string(*(hp.ps))), i(0) {
        std::cout << "HasPtr(const HasPtr &hp)" << std::endl;
    }

    HasPtr& operator= (const HasPtr &rhs) {
        std::cout << "HasPtr& operator= (const HasPtr &rhs)" << std::endl;
        auto newp = new std::string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }

    ~HasPtr() {
        delete ps;
    }

    std::string* getStr() const {
        return ps;
    }

private:
    std::string *ps;
    int i;
};

#endif // !__HAS_PTR__
