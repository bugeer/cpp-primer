#ifndef __QUERY__
#define __QUERY__

#include "QueryBase.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "WordQuery.h"
#include <iostream>
#include <memory>

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &s);
    QueryResult eval(const TextQuery &t) const {
        std::cout << "Query::eval" << std::endl;
        return q->eval(t);
    }
    std::string rep() const {
        std::cout << "Query:rep" << std::endl;
        return q->rep();
    }

private:
    Query(std::shared_ptr<QueryBase> query): q(query) { }
    std::shared_ptr<QueryBase> q;
};

std::ostream& operator<<(std::ostream &os, const Query &query);
Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);

#endif // !__QUERY__
