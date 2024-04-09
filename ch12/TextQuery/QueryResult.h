#ifndef __QUERY_RESULT__
#define __QUERY_RESULT__

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "TextQuery.h"

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(
        const std::string& s,
        std::shared_ptr<std::set<TextQuery::line_no>> line_set,
        std::shared_ptr<std::vector<std::string>> v
    ) : sougth(s), lines(line_set), file(v) { };

private:
    std::string sougth;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif // !__QUERY_RESULT__
