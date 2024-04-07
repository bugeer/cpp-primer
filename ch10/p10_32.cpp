#include "Sales_data.h"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <vector>

bool compareIsbn(const Sales_data &s1, const Sales_data &s2) {
    return s1.isbn() < s2.isbn();
}

int process_transaction(std::istream &in, std::ostream &out) {
    std::istream_iterator<Sales_data> i_iter(in), eof;
    std::vector<Sales_data> sds(i_iter, eof);
    if(sds.empty()) {
        std::cerr << "NO DATA!" << std::endl;
        return -1;
    }

    std::sort(sds.begin(), sds.end(), compareIsbn);

    std::ostream_iterator<Sales_data> o_iter(out, "\n");
    
    for(auto bg = sds.begin(), ed = bg; bg != sds.end(); bg = ed) {
        ed = std::find_if_not(bg, sds.end(), [bg](const Sales_data &i) {
            return i.isbn() == bg->isbn();
        });

        o_iter = std::accumulate(bg, ed, Sales_data(bg->isbn()));
    }

    return 0;
}

int main (int argc, char *argv[]) {
    if(argc < 2) {
        std::cerr << "No input file!" << std::endl;
        return -3;
    }

    std::ifstream in(argv[1]);
    if(!in) {
        std::cerr << "Input file error!" << std::endl;
        return -2;
    }

    if(argc >= 3) {
        std::ofstream out(argv[2], std::ofstream::app);

        if(!out) {
            std::cerr << "Fail to open file: " << argv[2] << std::endl;
            return -2;
        }

        return process_transaction(in, out);
    } else {
        return process_transaction(in, std::cout);
    }
}

