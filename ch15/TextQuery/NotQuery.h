#ifndef __NOT_QUERY__
#define __NOT_QUERY__

#include "QueryBase.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "Query.h"
#include <iostream>

class NotQuery : public QueryBase {
    friend Query operator~(const Query &);

private:
    NotQuery(const Query &q): query(q) {
        std::cout << "NotQuery::NotQuery(const Query &q)" << std::endl;
    }

    QueryResult eval(const TextQuery&) const override;
    std::string rep() const override {
        std::cout << "NoQuery::rep" << std::endl;
        return "~(" + query.rep() + ")";
    }

    Query query;
};

Query operator~(const Query &);

#endif // !__NOT_QUERY__
