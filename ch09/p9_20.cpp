#include <deque>
#include <iostream>
#include <list>

int main (int argc, char *argv[]) {
    std::list<int> int_list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> odd_deque;
    std::deque<int> even_deque;

    for(int i : int_list) {
        if(i % 2 == 0) {
            even_deque.push_back(i);
        } else {
            odd_deque.push_back(i);
        }
    }

    std::cout << "int list: " << std::endl;
    for(int i : int_list) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "odd_deque: " << std::endl;
    for(int i : odd_deque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "even_deque: " << std::endl;
    for(int i : even_deque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
