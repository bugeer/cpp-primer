#ifndef __BINARY_QUERY__
#define __BINARY_QUERY__

#include "QueryBase.h"
#include "Query.h"
#include <iostream>
#include <string>

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s): lhs(l), rhs(r), opSym(s) {
        std::cout << "BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s)" << std::endl;
    }

    std::string rep() const override {
        std::cout << "BinaryQuery::rep" << std::endl;
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;
    std::string opSym;
};

#endif // !__BINARY_QUERY__
