#include "Query.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);


    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << "==================" << std::endl;
    std::cout << q << std::endl;
    std::cout << "==================" << std::endl;
    print(std::cout, q.eval(tq)) << std::endl;

    q = Query("fiery") & Query("bird") | ~Query("wind");
    std::cout << "==================" << std::endl;
    std::cout << q << std::endl;
    std::cout << "==================" << std::endl;
    print(std::cout, q.eval(tq)) << std::endl;
}

int main (int argc, char *argv[]) {
    std::ifstream in("./input.file");

    runQueries(in);

    return 0;
}
