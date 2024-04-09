#ifndef __STR_BLOB_PTR__
#define __STR_BLOB_PTR__

#include "StrBlob.h"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();
    std::vector<std::string>::iterator begin();
    std::vector<std::string>::iterator end();

    std::size_t operator- (const StrBlobPtr& rhs) {
        if(wptr.lock() != rhs.wptr.lock()) {
            throw std::runtime_error("not the same StrBlobPtr");
        }

        return curr - rhs.curr;
    }
    const StrBlobPtr& operator+ (size_t sz) {
        curr += sz;

        return *this;
    }

private:
    std::size_t curr;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

#endif // !__STR_BLOB_PTR__
