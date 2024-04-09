#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

StrBlob::StrBlob(): data(std::make_shared<std::vector<std::string>>()) {
}

StrBlob::StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {
}

StrBlob::~StrBlob() {
}

void StrBlob::check(size_type i, const std::string &msg) const {
    if(i > data->size()) {
        throw std::out_of_range(msg);
    }
}

std::string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::front() const {
    check(0, "front on empty const StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string& StrBlob::back() const {
    check(0, "back on empty const StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const {
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

ConstStrBlobPtr StrBlob::cbegin() {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() {
    auto ret = ConstStrBlobPtr(*this, data->size());
    return ret;
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
    return lhs.data == rhs.data;
}
bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs == rhs);
}
