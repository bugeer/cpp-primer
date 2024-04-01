#ifndef __STRVEC__
#define __STRVEC__

#include <cstddef>
#include <memory>
#include <string>
#include <utility>

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const std::string&);
    size_t size() const {
        return first_free - elements;
    }
    size_t capacity() const {
        return cap - elements;
    }
    std::string *begine() const {
        return elements;
    }
    std::string *end() const {
        return first_free;
    }

private:
    std::string *elements;
    std::string *first_free;
    std::string *cap;

    void free();
    void reallocate();

    std::pair<std::string*, std::string*>
    alloc_n_copy(const std::string*, const std::string*);
    void chk_n_alloc() {
        if(size() == capacity()) {
            reallocate();
        }
    }

    static std::allocator<std::string> alloc;
};

#endif // !__STRVEC__
