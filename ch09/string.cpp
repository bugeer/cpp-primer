#include <iostream>
#include <string>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    {
        print_section("string init");
        const char *cp = "Hello World!";
        char noNull[] = {'H', 'i'};

        std::string s1(cp);
        std::string s2(noNull, 2);
        std::string s3(noNull);
        std::string s4(cp+6, 5);
        std::string s5(s1, 6, 5);
        std::string s6(s1, 6);
        std::string s7(s1, 6, 20);
        // std::string s8(s1, 16);

        std::cout << "s1: " << s1 << std::endl;
        std::cout << "s2: " << s2 << std::endl;
        std::cout << "s3: " << s3 << std::endl;
        std::cout << "s4: " << s4 << std::endl;
        std::cout << "s5: " << s5 << std::endl;
        std::cout << "s6: " << s6 << std::endl;
        std::cout << "s7: " << s7 << std::endl;
        // std::cout << "s8: " << s8 << std::endl;
    }

    {
        print_section("string changing");
        std::string s0 = "hello";
        std::cout << "s0: " << s0 << std::endl;
        s0.insert(s0.size(), 5, '!');
        std::cout << "s0: " << s0 << std::endl;
        s0.erase(s0.size()-5, 5);
        std::cout << "s0: " << s0 << std::endl;

        const char *cp = "Stately, plump Buck";
        s0.assign(cp, 7);
        std::cout << "s0: " << s0 << std::endl;
        s0.insert(s0.size(), cp+7);
        std::cout << "s0: " << s0 << std::endl;
    }

    {
        print_section("append and replace");
        std::string s("C++ Primer");
        std::string s2 = s;
        s.insert(s.size(), " 4th Edition");
        s2.append(" 4th Edition");
        std::cout << "s :" << s  << std::endl;
        std::cout << "s2:" << s2 << std::endl;

        s.erase(11, 3);
        s.insert(11, "5th");
        s2.replace(11, 3, "5th");
        std::cout << "after replace: " << std::endl;
        std::cout << "s :" << s  << std::endl;
        std::cout << "s2:" << s2 << std::endl;
    }

    {
        print_section("string searching");
        std::string name("AnnaBelle");
        auto pos1 = name.find("Anna");
        std::cout << "pos of Anna: " << pos1 << std::endl;
        auto pos2 = name.find("Annx");
        std::cout << "pos of Annx: " << pos2 << std::endl;
    }

    return 0;
}
