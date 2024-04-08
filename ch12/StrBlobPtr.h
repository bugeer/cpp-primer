#ifndef __STR_BLOB_PTR__
#define __STR_BLOB_PTR__

#include "StrBlob.h"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr {
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    std::string& deref() const;
    StrBlobPtr& incr();

private:
    std::size_t curr;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
};


#endif // !__STR_BLOB_PTR__
