#include <iostream>
struct Base {
    int memfcn() {
        std::cout << "Base.memfcn()" << std::endl;
        return 0;
    }
};

struct Derived : public Base {
    int memfcn(int) {
        std::cout << "Derived.memfcn()" << std::endl;
        return 1;
    }
};

class B {
public:
    virtual int func() { std::cout << "\tB.func()" << std::endl; return 0; }
};

class D1 : public B {
public:
    int func(int) { std::cout << "\tD1.func(int)" << std::endl; return 1; }
    virtual void f2() { std::cout << "\tD1.f2()" << std::endl;  }
};

class D2 : public D1 {
public:
    int func(int) { std::cout << "\tD2.func(int)" << std::endl; return 0;} // new func non virtual; override D1's int func(int);
    int func() { std::cout << "\tD2.func()" << std::endl; return 1;} // override B's virtual int func();
    void f2() { std::cout << "\tD2.f2()" << std::endl; } // override D1's virtual int f2();
};

int main (int argc, char *argv[]) {
    {
        Derived d;
        Base b;

        b.memfcn();
        d.memfcn(10);
        // d.memfcn();
        d.Base::memfcn();
    }
    {
        B  b;
        D1 d1;
        D2 d2;

        B *bp1 = &b;
        B *bp2 = &d1;
        B *bp3 = &d2;

        std::cout << std::endl;
        std::cout << "bp1->func();" << std::endl;
        bp1->func();
        std::cout << "bp2->func();" << std::endl;
        bp2->func();
        std::cout << "bp3->func();" << std::endl;
        bp3->func();

        D1 *d1p = &d1;
        D1 *d2p = &d2;
        std::cout << std::endl;
        // bp2->f2();
        std::cout << "d1p->f2();" << std::endl;
        d1p->f2();
        std::cout << "d2p->f2();" << std::endl;
        d2p->f2();

        B  *p1 = &d2;
        D1 *p2 = &d2;
        D2 *p3 = &d2;
        std::cout << std::endl;
        // std::cout << "p1->func(42);" << std::endl;
        // p1->func(42);
        std::cout << "p2->func(42);" << std::endl;
        p2->func(42);
        std::cout << "p3->func(42);" << std::endl;
        p3->func(42);
    }

    return 0;
}
