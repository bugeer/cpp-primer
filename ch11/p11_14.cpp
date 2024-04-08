#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

typedef std::map<std::string, std::vector<std::pair<std::string, std::string>>> FamilySet;

void add_child(FamilySet& set, const std::string& family, const std::string& child, const std::string& birthday) {
    set[family].push_back({child, birthday});
}

void print_family(FamilySet& set) {
    for(const auto &f : set) {
        std::cout << "Family name: " << f.first << std::endl;
        std::cout << "Children name: " << std::endl;
        for(const auto& c : f.second) {
            std::cout << "\t" << c.first << "\t" << c.second << std::endl;
        }
        std::cout << std::endl;
    }
}

int main (int argc, char *argv[]) {
    FamilySet family_set;

    add_child(family_set, "Green", "Jim",   "2001-3-1");
    add_child(family_set, "Green", "James", "2003-8-1");
    add_child(family_set, "Green", "Jay",   "2005-2-9");

    add_child(family_set, "King", "Lily", "2016-9-20");
    add_child(family_set, "King", "Luck", "2020-7-20");

    print_family(family_set);

    return 0;
}
