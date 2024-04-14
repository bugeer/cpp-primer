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
    using line_it = std::set<TextQuery::line_no>::iterator;
    using line_cit = std::set<TextQuery::line_no>::const_iterator;

public:
    QueryResult(
        const std::string& s,
        std::shared_ptr<std::set<TextQuery::line_no>> line_set,
        std::shared_ptr<std::vector<std::string>> v
    ) : sougth(s), lines(line_set), file(v) { };

    line_it begin() {
        return lines->begin();
    }
    line_it end() {
        return lines->end();
    }
    line_cit cbegin() {
        return lines->cbegin();
    }
    line_cit cend() {
        return lines->cend();
    }

    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }

private:
    std::string sougth;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif // !__QUERY_RESULT__
