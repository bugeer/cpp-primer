#ifndef __CONST_STR_BLOB_PTR__
#define __CONST_STR_BLOB_PTR__

#include "StrBlob.h"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    std::string& deref() const;
    ConstStrBlobPtr& incr();
    std::vector<std::string>::const_iterator cbegin() const;
    std::vector<std::string>::const_iterator cend() const;

private:
    std::size_t curr;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
};


#endif // !__CONST_STR_BLOB_PTR__
