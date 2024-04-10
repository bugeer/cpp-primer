struct B;

struct A{
    A() = default;
    A(const B&);
};

struct B {
    operator A() const;
};

const A& f(const A& a) {
    return a;
}

int main (int argc, char *argv[]) {
    B b;
    // A a = f(b); // f(B::operator A()) or f(A::A(const B&));
    A a1 = f(A(b));
    A a2 = f(b.operator A());

    return 0;
}
