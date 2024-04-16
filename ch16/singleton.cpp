#include <iostream>
using namespace std;


class Singleton
{
public:
    // forbidden 
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    // deconstruct
    ~Singleton() {
        cout << "deconstruct" << endl;
    }
    // get instance
    static Singleton* get_instance()
    {
        // Static local variable initialization is thread-safe
        // and will be initialized only once.
        static Singleton instance{};
        return &instance;
    }

private:
    // hidden construct
    explicit Singleton(){
        cout << "construt " << std::endl;
    }
};


int main() {

    Singleton* s0 = Singleton::get_instance();
    Singleton* s1 = Singleton::get_instance();
    Singleton* s2 = Singleton::get_instance();
    Singleton* s3 = Singleton::get_instance();
    Singleton* s4 = Singleton::get_instance();

    return 0;
}
