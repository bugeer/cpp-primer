#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "../ch10/Sales_data.h"

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
    {
        print_section("map iterator");
        std::map<std::string, int> si_map{{"haha", 123}, {"fuck", 999}};
        std::map<std::string, int>::iterator map_it = si_map.begin();

        std::cout << "<key: value>: <" << map_it->first << ", " << map_it->second << ">" << std::endl;;
        map_it++;
        std::cout << "<key: value>: <" << map_it->first << ", " << map_it->second << ">" << std::endl;;
        std::cout << std::endl;
    }
    {
        print_section("set iterator");
        std::set<int> iset = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::set<int>::iterator set_it = iset.begin();
        std::cout << "print int set: " << std::endl;
        while(set_it != iset.end()) {
            // *set_it = 42;
            std::cout << *set_it++ << " " << std::endl;
        }
        std::cout << std::endl;
    }
    {
        print_section("p11_19");
        std::multiset<Sales_data, bool(*)(const Sales_data&, const Sales_data&)>::iterator it;
    }
    {
        print_section("p11_22");
        std::pair<std::map<std::string, std::vector<int>>::iterator, bool> my_insert(std::pair<std::string, std::vector<int>>);
    }
    {
        print_section("delete");
        std::map<int, int> iimap = {{1,1}, {2,2}, {3,3}, {4,4}};
        std::cout << iimap.erase(iimap.begin())->first << std::endl;
        std::cout << iimap.erase(2) << std::endl;
        std::cout << iimap.erase(1) << std::endl;
        std::cout << iimap.erase(9) << std::endl;
    }
    {
        std::vector<int> ivec;
        ivec[0] = 1;
    }

    return 0;
}
