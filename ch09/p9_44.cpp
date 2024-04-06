#include <iostream>
#include <string>

void replace(std::string &s, const std::string &oldVal, const std::string &newVal) {
    for(auto curr = 0; curr < s.size();) {
        if(oldVal == s.substr(curr, oldVal.size())) {
            s.replace(curr, oldVal.size(), newVal);
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
