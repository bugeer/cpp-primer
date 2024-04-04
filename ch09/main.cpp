#include <array>
#include <cerrno>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}
int main (int argc, char *argv[]) {
    {
        print_section("init by other container");

        std::list<std::string> authors = {"Milton", "Shakespeare", "Austen"};
        std::vector<const char*> articles = {"a", "an", "the"};
        std::list<std::string> list2(authors);
        // std::deque<std::string> authList(authors);
        // std::vector<std::string> words(articles);
        std::forward_list<std::string> words2(articles.begin(), articles.end());
    }

    {
        print_section("init");

        std::vector<int> i_vec(10, -1);
        std::list<std::string> s_vec(10, "hi!");
        std::forward_list<int> i_list(10);
        std::deque<std::string> s_deq(10);
    }

    {
        print_section("array");

        std::array<int, 10> ia10;
        std::array<int, 10> ia10_2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::array<int, 10> ia10_3 = {42};

        int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        // int cpy[10] = digs;
        std::array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::array<int, 10> copy = digits;
    }

    {
        print_section("p9.11");
        std::vector<int> ivec_1;
        std::vector<int> ivec_2(10);
        std::vector<int> ivec_3(10, 42);
        std::vector<int> ivec_4{1, 2, 3};
        std::vector<int> ivec_5(ivec_2);
        std::vector<int> ivec_6(ivec_2.begin(), ivec_2.end());
    }

    {
        print_section("assign array");
        std::array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::array<int, 10> a2 = {9};

        std::cout << "init array:" << std::endl;
        std::cout << "a1: ";
        for(int i : a1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "a2: ";
        for(int i : a2) {
            std::cout << i << " ";
        }
        std::cout << std::endl << std::endl;

        a2 = a1;
        std::cout << "after a2 = a1:" << std::endl;
        std::cout << "a1: ";
        for(int i : a1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "a2: ";
        for(int i : a2) {
            std::cout << i << " ";
        }
        std::cout << std::endl << std::endl;

        // working fine on g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
        a2 = {0, 1, 2, };
        std::cout << "after a2 = {0}:" << std::endl;
        std::cout << "a1: ";
        for(int i : a1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        std::cout << "a2: ";
        for(int i : a2) {
            std::cout << i << " ";
        }
        std::cout << std::endl << std::endl;
    }

    {
        print_section("container assign function");
        std::list<std::string> names;
        std::vector<const char*> oldstyle;
        // names = oldstyle;
        names.assign(oldstyle.cbegin(), oldstyle.cend());

        std::list<std::string> slist1(1);
        std::cout << "init: " << std::endl;
        for(auto& i : slist1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        slist1.assign(10, "Hiya!");
        std::cout << "after slist1.assign(10, \"Hiya!\");" << std::endl;
        for(auto& i : slist1) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    {
        print_section("swap");
        std::vector<std::string> s_vec1(10);
        std::vector<std::string> s_vec2(24);
        swap(s_vec1, s_vec2);
    }

    return 0;
}
