#include <iostream>
#include <memory>
#include <new>
#include <string>
#include <vector>

class T {
public:
    T();
    T(T &&) = default;
    T(const T &) = default;
    T &operator=(T &&) = default;
    T &operator=(const T &) = default;
    ~T();
private:
};

class Foo {
public:
    Foo();
    Foo(Foo &&) = default;
    Foo(const Foo &) = default;
    Foo(const T&) {};
    Foo &operator=(Foo &&) = default;
    Foo &operator=(const Foo &) = default;
    ~Foo();
private:
};

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

std::shared_ptr<Foo> factory(T arg) {
    return std::make_shared<Foo>(arg);
}

void use_factory(T arg) {
    std::shared_ptr<Foo> p = factory(arg);
}

int main (int argc, char *argv[]) {
    {
        print_section("basic");
        std::shared_ptr<int>         ip  = std::make_shared<int>(42);
        std::shared_ptr<int>         ip2 = std::make_shared<int>();
        std::shared_ptr<std::string> sp  = std::make_shared<std::string>(10, '9');
        auto                         vsp = std::make_shared<std::vector<std::string>>();

        auto p = std::make_shared<int>(42);
        auto q(p);
        std::cout << (p == q ? "ture" : "false") << std::endl;
        std::cout << "p: " << p.use_count() << std::endl;
        std::cout << "q: " << q.use_count() << std::endl;
        auto t = std::make_shared<int>(44);
        std::cout << std::endl;
        std::cout << "p: " << p.use_count() << std::endl;
        std::cout << "q: " << q.use_count() << std::endl;
        std::cout << "t: " << t.use_count() << std::endl;
        std::cout << std::endl;
        t = q;
        std::cout << "p: " << p.use_count() << std::endl;
        std::cout << "q: " << q.use_count() << std::endl;
        std::cout << "t: " << t.use_count() << std::endl;

        int *p1 = new int;
        int *p2 = new (std::nothrow) int;
    }

    return 0;
}
