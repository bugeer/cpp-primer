#include "Quote.h"

class NoDerived final{
};

class Base {
};

class Last final : Base {
};

// class Bad : NoDerived { };
// class Bad2 : Last { };

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1: B {
    void f1(int) const override;
    // void f2(int) override;
    // void f3() override;
    // void f4() override;
};

struct D2 : B {
    void f1(int) const final;
};

struct D3 : D2 {
    void f2();
    // void f1(int) const; // f1 in D2 is final.
};

int main (int argc, char *argv[]) {
    {
        Bulk_quote bulk;
        Quote *itemP = &bulk;
        // Bulk_quote *bulkP = itemP;
        Bulk_quote *bulkP = static_cast<Bulk_quote*>(itemP);
    }
    {
        // 15.3
        
    }

    return 0;
}
