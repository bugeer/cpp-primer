#include <iostream>
#include <string>

const std::string CHARS   = "abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ";
const std::string NUMBERS = "0123456789";

void find_all_numbers(const std::string& str, std::string& numbs) {
    auto pos = 0;
    while(pos < str.size()) {
        pos = str.find_first_of(NUMBERS, pos);
        if(pos != std::string::npos) {
            numbs += str[pos++];
        } else {
            return;
        }
    }
}

void find_all_chars(const std::string& str, std::string& chars) {
    auto pos = 0;
    while(pos < str.size()) {
        pos = str.find_first_of(CHARS, pos);
        if(pos != std::string::npos) {
            chars += str[pos++];
        } else {
            return;
        }
    }
}

int main (int argc, char *argv[]) {
    std::string str = "ab2c3d7R4E6";
    std::string numbs;
    std::string chars;

    find_all_numbers(str, numbs);
    find_all_chars(str, chars);

    std::cout << "Chars: " << chars << std::endl;
    std::cout << "Numbs: " << numbs << std::endl;

    return 0;
}
