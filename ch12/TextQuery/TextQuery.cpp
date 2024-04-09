#include "TextQuery.h"
#include "QueryResult.h"

#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

TextQuery::TextQuery(std::ifstream& ifs): file(new std::vector<std::string>) {
    std::string line;
    while(std::getline(ifs, line)) {
        file->push_back(line);
    }

    std::string word;

    for(line_no i=0; i<file->size(); i++) {
        std::istringstream iss(file->at(i));
        while((iss >> word)) {
            auto &lines = wm[word];
            if(!lines) {
                lines.reset(new std::set<line_no>);
            }

            lines->insert(i);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    auto loc = wm.find(sought);

    if(loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    } else {
        return QueryResult(sought, loc->second, file);
    }
}

std::ostream& print(std::ostream& os, const QueryResult &qr) {
    os << qr.sougth << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() > 0 ? "times" : "time") << std::endl;

    for(auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << std::endl;
    }

    return os;
}
