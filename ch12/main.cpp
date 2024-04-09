#include <iostream>
#include <memory>
#include <string>
#include <vector>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

void self_delete(int* p) {
    std::cout << "fuck" << std::endl;
    delete p;
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
    {
        print_section("deleter");
        int *p = new int(42);
        // std::shared_ptr<int> sp(new int(42), self_delete);
        std::shared_ptr<int> sp(p, [](int *p){
            std::cout << "lambda fuck" << std::endl;
            delete p;
        });

        {
            auto t = sp;
            std::cout << "in" << std::endl;
        }
        std::cout << "out" << std::endl;
    }
    {
        print_section("dynamic array");
        int *pia = new int[42];
        typedef int arrT[42];
        auto *p = new arrT[42]; // :)
        std::cout << p << std::endl;
        std::cout << p+1 << std::endl;

        delete []pia;
        delete []p;
    }

    return 0;
}
