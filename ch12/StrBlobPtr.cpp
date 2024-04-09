#include "StrBlobPtr.h"
#include "StrBlob.h"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

std::vector<std::string>::iterator StrBlobPtr::begin() {
    auto p = check(curr, "begen issue");
    return p->begin();
}

std::vector<std::string>::iterator StrBlobPtr::end() {
    auto p = check(curr, "end issue");
    return p->end();
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();

    if(!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }

    if(i >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs == rhs);
}
