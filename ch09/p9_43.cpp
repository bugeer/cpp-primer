#include <iostream>
#include <string>

void replace(std::string &s, const std::string &oldVal, const std::string &newVal) {
    for(auto curr = s.begin(); curr <= s.end() - oldVal.size();) {
        if(oldVal == std::string(curr, curr + oldVal.size())) {
            curr = s.erase(curr, curr+oldVal.size());
            curr = s.insert(curr, newVal.cbegin(), newVal.cend());
            curr += newVal.size();
        } else {
            ++curr;
        }
    }
}

int main (int argc, char *argv[]) {
    std::string s0 = "haha tho haha";
    std::cout << "s0: " << s0 << std::endl;
    replace(s0, "tho", "though");
    std::cout << "s0: " << s0 << std::endl;

    std::string s1 = "haha thru haha";
    std::cout << "s1: " << s1 << std::endl;
    replace(s1, "thru", "through");
    std::cout << "s1: " << s1 << std::endl;

    return 0;
}
