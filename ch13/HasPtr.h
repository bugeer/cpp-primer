#ifndef __HAS_PTR__
#define __HAS_PTR__

#include <iostream>
#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) { }

    HasPtr(const char* str): ps(new std::string(str)), i(0) { }

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

    friend void swap(HasPtr& lhs, HasPtr& rhs);

    std::string& getStr() const {
        return *ps;
    }

    void setStr(const std::string &s) {
        *ps = s;
    }

private:
    std::string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "Swap Value-like HasPtr" << std::endl;

    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i,  rhs.i );
}

#endif // !__HAS_PTR__
