#ifndef __QUERY_BASE__
#define __QUERY_BASE__

#include "TextQuery.h"
#include "QueryResult.h"

#include <string>

class Query;

class QueryBase {
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

#endif // !__QUERY_BASE__
