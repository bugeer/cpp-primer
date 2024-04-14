#ifndef __OR_QUERY__
#define __OR_QUERY__

#include "BinaryQuery.h"
#include "QueryBase.h"
#include "Query.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
private:
    OrQuery(const Query &lhs, const Query &rhs): BinaryQuery(lhs, rhs, "|") {
        std::cout << "OrQuery::OrQuery(const Query &lhs, const Query &rhs)" << std::endl;
    }
    QueryResult eval(const TextQuery&) const override;
};

#endif // !__OR_QUERY__
