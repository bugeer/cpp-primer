#include "ConstStrBlobPtr.h"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

std::string& ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

std::vector<std::string>::const_iterator ConstStrBlobPtr::cbegin() const {
    auto p = check(curr, "begen issue");
    return p->begin();
}

std::vector<std::string>::const_iterator ConstStrBlobPtr::cend() const {
    auto p = check(curr, "end issue");
    return p->end();
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();

    if(!ret) {
        throw std::runtime_error("unbound ConstStrBlobPtr");
    }

    if(i >= ret->size()) {
        throw std::out_of_range(msg);
    }

    return ret;
}
