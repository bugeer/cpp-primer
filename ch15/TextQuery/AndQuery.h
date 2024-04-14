#ifndef __AND_QUERY__
#define __AND_QUERY__

#include "BinaryQuery.h"
#include "QueryBase.h"
#include "Query.h"
#include "BinaryQuery.h"
#include "QueryResult.h"
#include <iostream>

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
private:
    AndQuery(const Query &left, const Query &right): BinaryQuery(left, right, "&") {
        std::cout << "AndQuery(const Query &left, const Query &right)" << std::endl;
    }
    QueryResult eval(const TextQuery&) const override;
};

#endif // !__AND_QUERY__
