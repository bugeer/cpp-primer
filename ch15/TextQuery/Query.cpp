#include <memory>
#include <ostream>
#include "Query.h"
#include "AndQuery.h"
#include "NotQuery.h"
#include "OrQuery.h"
#include "QueryBase.h"
#include "WordQuery.h"

std::ostream& operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

Query::Query(const std::string &s): q(new WordQuery(s)) {
    std::cout << "Query::Query(const std::string &)" << std::endl;
}

Query operator~(const Query &operand) {
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
}

Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}
