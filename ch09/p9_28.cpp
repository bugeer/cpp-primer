#include <forward_list>
#include <iostream>
#include <string>

typedef std::forward_list<std::string>           str_list;
typedef std::forward_list<std::string>::iterator it_slist;

it_slist insert_string(str_list& list, std::string sfind, std::string sinsert) {
    auto prev = list.before_begin();
    auto curr = list.begin();

    while(curr != list.end()) {
        if(*curr == sfind) {
            return list.insert_after(curr, sinsert);
        }
        prev ++;
        curr ++;
    }

    return list.insert_after(prev, sinsert);
}

int main (int argc, char *argv[]) {
    str_list slist = {"s0", "s1", "s2"};

    insert_string(slist, "s0", "fuck-s0");
    for(auto i : slist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    insert_string(slist, "s2", "fuck-s2");
    for(auto i : slist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
