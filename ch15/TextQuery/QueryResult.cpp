#include "QueryResult.h"
#include <ostream>

std::ostream& print(std::ostream& os, const QueryResult &qr) {
    os << qr.sougth << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 0 ? "times" : "time") << std::endl;

    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << std::endl;
    }

    return os;
}
