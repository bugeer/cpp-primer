#ifndef __TEMPLATE_BLOB__
#define __TEMPLATE_BLOB__

#include "BlobPtr.h"
#include "ConstBlobPtr.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <vector>

template<typename T> class BlobPtr;
template<typename T> class ConstBlobPtr;
template<typename T> class Blob;

template<typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template<typename T> bool operator< (const Blob<T> &, const Blob<T> &);

template<typename T>
class Blob {
    friend class BlobPtr<T>;
    friend class ConstBlobPtr<T>;

    friend bool operator== <T>(const Blob&, const Blob&);
    friend bool operator<  <T>(const Blob&, const Blob&);
    
public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;
    using iterator = BlobPtr<T>;
    using const_iterator = ConstBlobPtr<T>;

    Blob(): data(std::make_shared<std::vector<T>>()) {
    }
    Blob(std::initializer_list<T> il) :data(std::make_shared<std::vector<T>>(il)){
    }
    Blob(const Blob &rhs): data(std::make_shared<std::vector<T>>(*rhs.data)) {
    }

    Blob &operator=(const Blob &rhs) {
        data = std::make_shared<std::vector<T>>(*rhs.data);
        return *this;
    }

    T operator[](size_type i) {
        check(i, "operator[]");
        return at(i);
    }
    const T operator[](size_type i) const {
        check(i, "const operator[]");
        return at(i);
    }
    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const T& t) {
        data->push_back(t);
    }
    void push_back(T&& t) {
        data->push_back(std::move(t));
    }
    void pop_back() {
        check(0, "pop_back");
        data->pop_back();
    }
    T& front() {
        check(0, "front");
        return data->front();
    }
    const T& front() const {
        check(0, "const front");
        return const_cast<T&>(const_cast<const Blob&>(*this).front());
    }
    T& back() {
        check(0, "back");
        return data->back();
    }
    const T& back() const {
        check(0, "const back");
        return const_cast<T&>(const_cast<const Blob&>(*this).back());
    }
    const T& at(size_type i) const {
        check(i, "at");
        return const_cast<T&>(const_cast<const Blob&>(*this).at(i));
    }
    T& at(size_type i) {
        check(i, "at");
        return (*data).at(i);
    }
    iterator begin() {
        return iterator(*this);
    }
    iterator end() {
        return iterator(*this, size());
    }
    const_iterator begin() const {
        return const_iterator(*this);
    }
    const_iterator end() const {
        return const_iterator(*this, size());
    }
    const_iterator cbegin() const {
        return const_iterator(*this);
    }
    const_iterator cend() const {
        return const_iterator(*this, size());
    }

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type pos, const std::string &msg) const {
        if(pos >= size()) {
            throw std::out_of_range(msg);
        }
    }
};

template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data == *rhs.data;
}

template<typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator< (const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data < *rhs.data;
}

template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> rhs) {
    return !(lhs < rhs);
}

#endif // !__TEMPLATE_BLOB__
