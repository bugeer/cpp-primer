#ifndef __QUERY_RESULT__
#define __QUERY_RESULT__

#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

#include "TextQuery.h"

class TQueryResult {
    friend std::ostream& print(std::ostream&, const TQueryResult&);

public:
    TQueryResult(
        const std::string& s,
        std::shared_ptr<std::set<StrBlob::size_type>> line_set,
        const StrBlob& v
    ) : sougth(s), lines(line_set), file(v) { };

private:
    std::string sougth;
    std::shared_ptr<std::set<StrBlob::size_type>> lines;
    StrBlob file;
};

#endif // !__QUERY_RESULT__
