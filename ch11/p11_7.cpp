#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef std::map<std::string, std::vector<std::string>> FamilySet;

void add_child(FamilySet& set, const std::string& family, const std::string& child) {
    set[family].push_back(child);
}

void print_family(FamilySet& set) {
    for(const auto &f : set) {
        std::cout << "Family name: " << f.first << std::endl;
        std::cout << "Children name: " << std::endl;
        for(const auto& c : f.second) {
            std::cout << "\t" << c << std::endl;
        }
        std::cout << std::endl;
    }
}

int main (int argc, char *argv[]) {
    FamilySet family_set;

    add_child(family_set, "Green", "Jim");
    add_child(family_set, "Green", "James");

    add_child(family_set, "King", "Lily");
    add_child(family_set, "King", "Luck");

    print_family(family_set);

    return 0;
}
