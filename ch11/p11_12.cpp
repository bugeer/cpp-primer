#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<std::pair<std::string, int>> pvec;

    std::string s;
    int i;
    while(std::cin >> s >> i) {
        pvec.push_back({s, i});
        // pvec.push_back(std::make_pair(s, i));
        // pvec.push_back(std::pair<std::string, int>(s, i));
    }

    std::cout << "the results: " << std::endl;
    for(const auto &i : pvec) {
        std::cout << i.first << ": " << i.second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
