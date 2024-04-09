#ifndef __TEXT_QUERY__
#define __TEXT_QUERY__

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "../StrBlob.h"

class TQueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream&);
    TQueryResult query(const std::string &) const;

private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<StrBlob::size_type>>> wm;
};

#endif // !__TEXT_QUERY__
