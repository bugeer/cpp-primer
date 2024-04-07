#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

void print_section(const std::string &s) {
    std::cout << std::endl;
    std::cout << "********** " << s << " **********" << std::endl;
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    {
        print_section("multi");
        std::vector<int> ivec;
        for(std::vector<int>::size_type i=0; i!=10; ++i) {
            ivec.push_back(i);
            ivec.push_back(i);
        }
        std::set<int> iset(ivec.begin(), ivec.end());
        std::multiset<int> miset(ivec.begin(), ivec.end());

        std::cout << "ivec.size:  " << ivec.size()  << std::endl;
        std::cout << "iset.size:  " << iset.size()  << std::endl;
        std::cout << "miset.size: " << miset.size() << std::endl;
    }
    {
        print_section("p11_9");
        std::map<std::string, std::list<unsigned>> dict;
        print_section("p11_10");
        std::map<std::vector<int>::iterator, int> it_vec_map;
        std::map<std::list<int>::iterator  , int> it_list_map;
    }

    return 0;
}
