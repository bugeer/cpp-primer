#include "HasSharedPtr.h"

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if(--*use == 0) {
        delete ps;
        delete  use;
    }

    ps  = rhs.ps;
    i   = rhs.i;
    use = rhs.use;

    return *this;
}

// HasPtr& HasPtr::operator=(const HasPtr rhs) {
//     swap(*this, rhs);
//     return *this;
// }

HasPtr::~HasPtr() {
    if(--*use == 0) {
        delete ps;
        delete use;
    }
}
