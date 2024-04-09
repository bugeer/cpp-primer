#include <fstream>
#include <iostream>

#include "StrBlob.h"
#include "StrBlobPtr.h"

int main (int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "No Input file!" << std::endl;
        return -1;
    }

    std::ifstream ifs(argv[1]);
    if(!ifs) {
        std::cerr << "Can't Open Input file: " << argv[1] << std::endl;
        return -2;
    }

    std::string word;
    StrBlob sb;
    StrBlobPtr sbp(sb);

    while (ifs >> word) {
        sb.push_back(word);
    }

    std::cout << "file content: " << std::endl;
    for(auto it=sbp.begin(); it!=sbp.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
