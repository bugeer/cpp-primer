#include "QueryResult.h"
#include "TextQuery.h"
#include <cstddef>
#include <memory>
#include "NotQuery.h"

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();

    auto it0 = result.begin();
    auto it1 = result.end();
    auto sz  = result.get_file()->size();

    for(std::size_t n=0; n != sz; n++) {
        if(it0 == it1 || *it0 != n) {
            ret_lines->insert(n);
        } else if(it0 != it1) {
            ++it0;
        }
    }

    return QueryResult(rep(), ret_lines, result.get_file());
}
