#include <forward_list>
#include <iostream>

int main (int argc, char *argv[]) {
    std::forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto prev = flist.before_begin();
    auto curr = flist.begin();

    while(curr != flist.end()) {
        if(*curr % 2) {
            curr = flist.erase_after(prev);
        } else {
            ++curr;
            ++prev;
        }
    }

    std::cout << "after remove odd" << std::endl;
    for(auto i : flist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
