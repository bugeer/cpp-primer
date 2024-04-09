#ifndef __MY_STRING__
#define __MY_STRING__

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <ostream>
#include <string>

class String {
    friend std::ostream& operator<<(std::ostream&, const String &);
public:
    typedef size_t     size_type;
    typedef char       *iterator;
    typedef char       &reference;
    typedef const char *const_iterator;
    typedef const char &const_reference;

    String(): first_item(nullptr), first_free(nullptr), cap(nullptr) {
    }
    String(const_iterator);
    String(std::initializer_list<char>);

    String(String &&) noexcept;
    String(const String &);
    String &operator=(String &&) noexcept;
    String &operator=(String &);
    String &operator=(const_iterator);
    ~String();

    void push_back(const_reference);
    void pop_back();

    void reserve(size_type);
    void resize(size_type, const_reference = char());

    bool empty() const {
        return cbegin() == cend();
    }
    size_type size() const {
        return first_free - first_item;
    }
    size_type capacity() const {
        return cap - first_item;
    }

    iterator begin() {
        return first_item;
    }
    iterator end() {
        return first_free;
    }
    const_iterator begin() const {
        return first_item;
    }
    const_iterator end() const {
        return first_free;
    }
    const_iterator cbegin() const {
        return begin();
    }
    const_iterator cend() const {
        return end();
    }

    std::string str() const {
        return std::string(cbegin(), cend());
    }

private:
    static std::allocator<char> alloc;

    iterator first_item;
    iterator first_free;
    iterator cap;

    void reallocate(size_type);
    void free();
};

std::ostream& operator<<(std::ostream &, const String &);

#endif // !__MY_STRING__
