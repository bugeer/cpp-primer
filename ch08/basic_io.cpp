#include <chrono>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    {
        std::ofstream out1, out2;
        // out1 = out2;
        // gistd::ofstream print(std::ofstream);
        // out2 = print(out2);
        std::cout << "Hello world." << std::endl;
    }

    // state
    {
        print_section("handle state");
        auto old_state = std::cin.rdstate();
        std::cin.clear();
        std::cout << "init... state: " << old_state << std::endl;

        // do something with cin.
        std::cout << "input a int: " << std::endl;
        int ival;
        std::cin >> ival;
        auto state = std::cin.rdstate();
        std::cout << "read... state: " << state << std::endl;

        std::cin.clear();
        std::cin.setstate(std::_S_goodbit);
        state = std::cin.rdstate();
        std::cout << "reset... state: " << state << std::endl;
    }

    {
        print_section("handle buffer");
        std::cout << "Hi! endl"  << std::endl;
        for(int i=0; i<=100; i++) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "\r\033[K" << "Hi! flush: " << (100-i) << "%" << std::flush;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Hi! ends"  << std::ends;
    }

    {
        print_section("tie streams");
        std::cin.tie(&std::cout);
        std::ostream *old_tie = std::cin.tie(nullptr);
        std::cin.tie(&std::cerr);
        std::cin.tie(old_tie);
    }

    return 0;
}
