#ifndef __TEMPLATE_BLOB_PTR__
#define __TEMPLATE_BLOB_PTR__

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template<typename T> class BlobPtr;
template <typename T> int  operator- (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator< (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator> (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
template <typename T> bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T> class Blob;

template<typename T>
class BlobPtr {
    using size_type = typename std::vector<T>::size_type;

    friend int  operator-  <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator== <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator!= <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator<  <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator>  <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator<= <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
    friend bool operator>= <T>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);
public:
    BlobPtr(): wptr(), curr(0) {
    }
    explicit BlobPtr(Blob<T> &b, size_type = 0): wptr(b.data), curr(0) {
    }

    T& operator*() const {
        // check(curr + 1, "operator *");
        // return (*wptr.lock())[curr];
        return (*check(curr+1, "operator *"))[curr];
    }

    T* operator->() const {
        return &**this;
    }

    BlobPtr operator++() {
        check(curr + 1, "operator++()");
        ++curr;
        return *this;
    }
    BlobPtr operator++(int) {
        BlobPtr ret = *this;
        ++*this;
        return ret;
    }
    BlobPtr operator--() {
        check(curr-1, "operator--()");
        --curr;
        return *this;
    }
    BlobPtr operator--(int) {
        BlobPtr ret = *this;
        --ret;
        return ret;
    }
    BlobPtr& operator+=(int n) {
        check(curr + n, "operator+=");
        curr += n;
        return *this;
    }
    BlobPtr& operator-=(int n) {
        check(curr - n, "operator+=");
        curr -= n;
        return *this;
    }
    BlobPtr operator+(int n) {
        BlobPtr ret = *this;
        return ret += n;
    }
    BlobPtr operator-(int n) {
        BlobPtr ret = *this;
        return ret -= n;
    }
private:
    std::weak_ptr<std::vector<T>> wptr;
    size_type curr;
    std::shared_ptr<std::vector<T>> check(size_type pos, const std::string& msg) const {
        std::shared_ptr<std::vector<T>> ptr = wptr.lock();

        if(!ptr) {
            throw std::runtime_error("unbound BlobPtr");
        } else if(pos >= ptr->size()) {
            throw std::out_of_range(msg);
        }

        return ptr;
    }
};

template <typename T>
int operator-(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.curr - rhs.curr;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return (lhs.wptr.lock() == rhs.wptr.lock()) && (lhs.curr == rhs.curr);
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    // compare identity
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs > rhs);
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs < rhs);
}

#endif // !__TEMPLATE_BLOB_PTR__
