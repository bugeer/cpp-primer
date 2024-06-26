#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    {
        print_section("accumulate");
        std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        std::cout << "int sum: "
            << std::accumulate(ivec.cbegin(), ivec.cend(), 0)
            << std::endl;

        std::vector<std::string> svec = {"aaa", " ", "fuck", " off"};
        std::cout << "string sum: "
            << std::accumulate(svec.cbegin(), svec.cend(), std::string(""))
            << std::endl;
    }
    {
        print_section("equal");
        std::vector<int> ivec1 = {0, 1, 2, 3, 4, 5};
        std::vector<int> ivec2 = {1, 2, 3, 4, 5};

        std::cout << "equal: "
            << std::equal(ivec1.cbegin()+1, ivec1.cend(), ivec2.cbegin())
            << std::endl;
    }
    {
        print_section("p10.4");
        std::vector<double> dvec = {1.1, 2.2, 3.3, 4.4, 5.5};
        std::cout << "sum of double: "
            << std::accumulate(dvec.cbegin(), dvec.cend(), 0.0)
            << std::endl;
    }
    {
        print_section("std::fill");
        std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << "init: " << std::endl;
        for(auto i : ivec) std::cout << i << "\t";
        std::cout << std::endl;

        std::fill(ivec.begin(), ivec.end(), 0);
        std::cout << "fill 0: " << std::endl;
        for(auto i : ivec) std::cout << i << "\t";
        std::cout << std::endl;

        std::fill(ivec.begin(), ivec.begin()+ivec.size()/2, 10);
        std::cout << "half fill 10: " << std::endl;
        for(auto i : ivec) std::cout << i << "\t";
        std::cout << std::endl;
    }

    {
        print_section("p10.14 lambda");
        auto sum = [](int a, int b) {
            return a + b;
        };
        std::cout << "sum(1, 2): " << sum(1, 2) << std::endl;

        print_section("p10.15 lambda");
        int x = 10;
        auto add = [x](int a) {
            return x + a;
        };
        std::cout << "9+x: " << add(9) << std::endl;

        std::vector<int> ivec = {-1, -2, -3, -4, 0, 1, 2, 3, 4};
        std::cout << "init: " << std::endl;
        for(auto i : ivec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::transform(ivec.begin(), ivec.end(), ivec.begin(), [](int i){
            // return i < 0 ? -i : i;
            if(i<0) return -i; else return i;
        });
        std::cout << "transform: " << std::endl;
        for(auto i : ivec) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    {
        print_section("insert iterator");
        std::list<int> ilist0 = {1, 2, 3, 4};
        std::list<int> ilist1;
        std::list<int> ilist2;

        std::copy(ilist0.cbegin(), ilist0.cend(), std::front_inserter(ilist1));
        std::copy(ilist0.cbegin(), ilist0.cend(), std::inserter(ilist2, ilist2.begin()));

        std::cout << "ilist0: ";
        for(auto i : ilist0) { std::cout << i << " "; }
        std::cout << std::endl;
        std::cout << "ilist1: ";
        for(auto i : ilist1) { std::cout << i << " "; }
        std::cout << std::endl;
        std::cout << "ilist2: ";
        for(auto i : ilist2) { std::cout << i << " "; }
        std::cout << std::endl;
    }

    {
        print_section("reverse iterator");
        std::vector<int> ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        for(auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter) {
            std::cout << *r_iter << std::endl;
        }
    }

    return 0;
}
