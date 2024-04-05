#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

typedef std::vector<int>         IntVect;
typedef std::list<int>           IntList;
typedef std::forward_list<int>   IntForw;

void handle_vector(IntVect& ivec) {
    auto iter = ivec.begin();
    while(iter != ivec.end()) {
        if(*iter % 2) {
            iter = ivec.insert(iter, *iter);
            iter += 2;
        } else {
            iter = ivec.erase(iter);
        }
    }

    for(auto i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void handle_list(IntList& ilist) {
    auto iter = ilist.begin();
    while(iter != ilist.end()) {
        if(*iter % 2) {
            iter = ilist.insert(iter, *iter);
            iter ++;
            iter ++;
        } else {
            iter = ilist.erase(iter);
        }
    }

    for(auto i : ilist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void handle_forw(IntForw& ilist) {
    auto prev = ilist.before_begin();
    auto curr = ilist.begin();

    while(curr != ilist.end()) {
        if(*curr % 2) {
            curr = ilist.insert_after(prev, *curr);
            curr ++;
            curr ++;
            prev ++;
            prev ++;
        } else {
            curr = ilist.erase_after(prev);
        }
    }

    for(auto i : ilist) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main (int argc, char *argv[]) {
    IntVect ivec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    handle_vector(ivec);

    IntList ilist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    handle_list(ilist);

    IntForw iforw = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    handle_forw(iforw);

    return 0;
}
