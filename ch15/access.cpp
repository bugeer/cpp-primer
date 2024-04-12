#include <cstddef>
#include <iostream>

class Pal;

class Base {
    friend class Pal;
public:
    void pub_mem();
    std::size_t size() const { 
        return n; 
    }

protected:
    int prot_mem;
    std::size_t n;

private:
    char priv_mem;
};

class Derived : private Base {
public:
    using Base::size;
protected:
    using Base::n;
};

class Sneaky : public Base {
    friend void clobber(Sneaky &s) {
        s.j = s.prot_mem = 0;
    }
    friend void clobber(Base &b) {
        // b.prot_mem = 0;
    }
private:
    int j;
};

struct Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; };
    int f() {
        return prot_mem;
    }

    char g() {
        // return priv_mem;
        return ' ';
    }
};

struct Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; };
    int f1() const {
        return prot_mem;
    }
};

struct Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; };
    int f1() const {
        return prot_mem;
    }
};

struct Derived_from_Public : public Pub_Derv {
    void memfcn(Base &b) { b = *this; };
    int user_base() {
        return prot_mem;
    }
};

struct Derived_from_Private : public Priv_Derv {
    // void memfcn(Base &b) { b = *this; };
    int user_base() {
        // return prot_mem;
        return 0;
    }
};

struct Derived_from_Protected : protected Priv_Derv {
    // void memfcn(Base &b) { b = *this; };
    int user_base() {
        // return prot_mem;
        return 0;
    }
};

class Pal {
public:
    int f(Base b) {
        return b.prot_mem;
    }
    int f2(Sneaky s) {
        // return s.j;
        return 0;
    }
    int f3(Sneaky s) {
        return s.prot_mem;
    }
};

class D2 : public Pal {
public:
    int mem(Base b) {
        // return b.prot_mem;
        return 0;
    }
};

int main (int argc, char *argv[]) {
    {
        Base b;
        Sneaky s;
        Pal p;
        std::cout << p.f(b)  << std::endl;
        std::cout << p.f2(s) << std::endl;
        std::cout << p.f3(s) << std::endl;
    }
    {
        Pub_Derv  d1;
        Priv_Derv d2;
        Prot_Derv d3;
        Derived_from_Public    dd1;
        Derived_from_Private   dd2;
        Derived_from_Protected dd3;

        Base *p = &d1;
        // p = &d2;
        // p = &d3;
        p = &dd1;
        // p = &dd2;
        // p = &dd3;
    }

}
