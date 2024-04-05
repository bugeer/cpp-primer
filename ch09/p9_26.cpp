#include <iostream>
#include <list>
#include <vector>
int main (int argc, char *argv[]) {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    std::vector<int> i_vect;
    std::list<int>   i_list;

    for(auto i : ia) {
        i_vect.push_back(i);
        i_list.push_back(i);
    }

    auto it_vect = i_vect.begin();
    while(it_vect != i_vect.end()) {
        if(*it_vect % 2 == 0) {
            it_vect = i_vect.erase(it_vect);
        } else {
            it_vect++;
        }
    }
    std::cout << "int vector remove even:" << std::endl;
    for(auto i : i_vect) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto it_list = i_list.begin();
    while(it_list != i_list.end()) {
        if(*it_list % 2) {
            it_list = i_list.erase(it_list);
        } else {
            it_list++;
        }
    }
    std::cout << "int list remove odd:" << std::endl;
    for(auto i : i_list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
