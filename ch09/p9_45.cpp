#include <iostream>
#include <string>

std::string& be_polite(
    std::string& s,
    const std::string& prefix,
    const std::string& postfix
) {
    s.insert(0, prefix + " ");
    s.append(" " + postfix);

    return s;
}

int main (int argc, char *argv[]) {
    std::string name0 = "John";
    be_polite(name0, "Mr.", "Jr.");

    std::cout << name0 << std::endl;

    return 0;
}
    
