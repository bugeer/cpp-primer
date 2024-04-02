#include "StrVec.h"
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begine(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(std::initializer_list<std::string> ss) {
    std::pair<std::string*, std::string*> newdata = alloc_n_copy(ss.begin(), ss.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begine(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if(this != &rhs) {
        free();
        elements   = rhs.elements;
        first_free = rhs.first_free;
        cap        = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string& s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::free() {
    if(elements) {
        for(auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }

        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::free_lambda() {

}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;

    for(size_t i=0; i!=size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);

    return {data, std::uninitialized_copy(b, e, data)};
}
