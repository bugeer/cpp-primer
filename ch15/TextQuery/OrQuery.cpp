#include "OrQuery.h"
#include "TextQuery.h"
#include <memory>
#include <set>

QueryResult OrQuery::eval(const TextQuery &text) const {
    std::cout << "OrQuery::eval" << std::endl;

    auto left  = lhs.eval(text);
    auto right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());

    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}
