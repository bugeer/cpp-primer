#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> ivec = {1, 111, 1111, 11111, 111111, 111111};
    int count = std::count_if(
        ivec.begin(),
        ivec.end(),
        std::bind(std::greater<int>(), std::placeholders::_1, 1024)
    );
    std::cout << "greater than 1024: " << count << std::endl;

    std::vector<std::string> svec = {"pooh", "fuck", "off"};
    auto found = std::find_if(
        svec.begin(),
        svec.end(),
        std::bind(std::not_equal_to<std::string>(), std::placeholders::_1, "pooh")
    );
    std::cout << "the first string not phooh: " << *found << std::endl;

    std::vector<int> ivec2 = {1, 111, 1111, 11111, 111111, 111111};
    for(auto i: ivec2) { 
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::transform(
        ivec2.begin(),
        ivec2.end(),
        ivec2.begin(),
        std::bind(std::multiplies<int>(), std::placeholders::_1, 2)
    );
    std::cout << "After multiply 2: " << std::endl;
    for(auto i: ivec2) { 
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
