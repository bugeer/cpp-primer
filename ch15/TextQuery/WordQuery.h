#ifndef __WORD_QUERY__
#define __WORD_QUERY__

#include "QueryBase.h"
#include <iostream>

class WordQuery : public QueryBase {
    friend class Query;

public:
    WordQuery();

private:
    WordQuery(const std::string &s): query_word(s) {
        std::cout << "WordQuery::WordQuery(const std::string &s)" << std::endl;
    }

    QueryResult eval(const TextQuery &t) const override {
        std::cout << "WordQuery::eval" << std::endl;
        return t.query(query_word);
    }
    std::string rep() const override {
        std::cout << "WordQuery::rep" << std::endl;
        return query_word;
    }

    std::string query_word;
};

#endif // !__WORD_QUERY__
