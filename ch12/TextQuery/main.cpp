#include "QueryResult.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";

        std::string s;

        if(!(std::cin >> s) || s == "q") {
            break;
        }

        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main (int argc, char *argv[]) {
    std::ifstream in("./input.file");

    runQueries(in);

    return 0;
}
