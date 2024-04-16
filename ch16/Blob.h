#ifndef __BLOB__
#define __BLOB__

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Blob {
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob(): data(std::make_shared<std::vector<T>>()){
    }
    Blob(std::initializer_list<T> il): data(std::make_shared<std::vector<T>>(il)) {
    }

    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(T &t) {
        data->push_back(t);
    }
    void push_back(T &&t) {
        data->push_back(std::move(t));
    }
    void pop_back();
    T& operator[](size_type i);
    const T& operator[](size_type i) const;
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if(i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    data->front();
}

template <typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    data->front();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    data->back();
}

template <typename T>
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    data->back();
}

#endif // !__BLOB__
