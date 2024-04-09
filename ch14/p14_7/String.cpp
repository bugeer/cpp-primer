#include "String.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <ostream>

std::allocator<char> String::alloc;

String::String(const_iterator ci): String() {
    std::cout << "String::String(const_iterator ci)" << std::endl;
    while (ci && *ci != '\0') {
        putchar(*ci++);
    }
}

String::String(std::initializer_list<char> il): String() {
    for(const auto &c : il) {
        push_back(c);
    }
}

String::String(const String &rhs) {
    std::cout << "String::String(const String &rhs)" << std::endl;
    first_item = alloc.allocate(rhs.size());
    first_free = std::uninitialized_copy(rhs.begin(), rhs.end(), first_item);
    cap        = first_item + rhs.size();
}

String::String(String &&rhs) noexcept
    : first_item(rhs.first_item), first_free(rhs.first_free), cap(rhs.cap) {
    std::cout << "String::String(String &&rhs)" << std::endl;
    rhs.first_item = nullptr;
    rhs.first_free = nullptr;
    rhs.cap        = nullptr;
}

String &String::operator=(String &&rhs) noexcept {
    std::cout << "String &String::operator=(String &&rhs)" << std::endl;

    if(this != &rhs) {
        free();

        first_item = rhs.first_item;
        first_free = rhs.first_free;
        cap        = rhs.cap;

        rhs.first_item = nullptr;
        rhs.first_free = nullptr;
        rhs.cap        = nullptr;
    }

    return *this;
}

String& String::operator=(const_iterator ci) {
    *this = String(ci);
    return *this;
}

String& String::operator=(String &rhs) {
    if(this != &rhs) {
        free();

        first_item = alloc.allocate(rhs.size());
        first_free = std::uninitialized_copy(rhs.begin(), rhs.end(), first_item);
        cap        = first_item + rhs.size();
    }

    return *this;
}

String::~String() {
    free();
}

void String::push_back(const_reference cr) {
    if(size() == capacity()) {
        reallocate(empty() ? 1 : 2*capacity());
    }

    alloc.construct(first_free++, cr);
}
void String::pop_back() {
    if(!empty()) {
        alloc.destroy(--first_free);
    }
}

void String::reserve(size_type sz) {
    if(sz > capacity()) {
        reallocate(sz);
    }
}

void String::resize(size_type sz, const_reference cr) {
    if(sz > size()) {
        for(int i=sz-size(); i>0; --i) {
            push_back(cr);
        }
    } else {
        for(int i=size()-sz; i>0; --i) {
            pop_back();
        }
    }
}

void String::reallocate(size_type sz) {
    auto new_first_item = alloc.allocate(sz);
    auto new_first_free = new_first_item;

    for(auto it=begin(); it!=end(); ++it) {
        alloc.construct(new_first_free++, std::move(*it));
    }
    free();

    first_item = new_first_item;
    first_free = new_first_free;
    cap        = new_first_free + sz;
}

void String::free() {
    while(!empty()) {
        alloc.destroy(--first_free);
    }
    alloc.deallocate(first_item, capacity());

    first_item = nullptr;
    first_free = nullptr;
    cap        = nullptr;
}

std::ostream& operator<<(std::ostream& os, const String& rhs) {
    return os << rhs.str();
}
