#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T_it, typename V>
T_it find_element(T_it it0, T_it it1, const V& v) {
    for( ; it0 != it1; ++it0) {
        if(*it0 == v) {
            return it0;
        }
    }

    return it0;
}


int main (int argc, char *argv[]) {
    std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it0 = find_element<std::vector<int>::iterator, int>(ivec.begin(), ivec.end(), 9);
    std::cout << "found 9 in vector: " << (it0 != ivec.end() ? "9" : "none") << std::endl;
    auto it1 = find_element<std::vector<int>::iterator, int>(ivec.begin(), ivec.end(), 10);
    std::cout << "found 10 in vector: " << (it1 != ivec.end() ? "10" : "none") << std::endl;

    std::list<std::string> slist{"haha", "hello", "world", "fuck", "off"};
    std::list<std::string>::iterator it2 = find_element<std::list<std::string>::iterator, std::string>(slist.begin(), slist.end(), "fuck");
    std::cout << "found 'fuck' in vector: " << (it2 != slist.end() ? "fuck" : "none") << std::endl;
    std::list<std::string>::iterator it3 = find_element(slist.begin(), slist.end(), "fuckU");
    std::cout << "found 'fuckU' in vector: " << (it3 != slist.end() ? "fuckU" : "none") << std::endl;

    return 0;
}
