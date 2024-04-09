#include "TextQuery.h"
#include "../StrBlob.h"
#include "../StrBlobPtr.h"
#include "TQueryResult.h"

#include <iostream>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>

TextQuery::TextQuery(std::ifstream& ifs) {
    std::string line;
    while(std::getline(ifs, line)) {
        file.push_back(line);
    }

    std::string word;

    for(auto it=file.begin(); it != file.end(); it.incr()) {
        std::istringstream iss(it.deref());
        while ((iss >> word)) {
            auto& lines = wm[word];
            if(!lines) {
                lines.reset(new std::set<StrBlob::size_type>);
            }

            lines->insert(it - file.begin());
        }
    }
}

TQueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<StrBlob::size_type>> nodata(new std::set<StrBlob::size_type>);

    auto loc = wm.find(sought);
    if(loc == wm.end()) {
        return TQueryResult(sought, nodata, file);
    } else {
        return TQueryResult(sought, loc->second, file);
    }
}

std::ostream& print(std::ostream& os, const TQueryResult &qr) {
    os << qr.sougth << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 0 ? "times" : "time") << std::endl;

    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
            << (qr.file.begin() + num).deref() << std::endl;
    }

    return os;
}
