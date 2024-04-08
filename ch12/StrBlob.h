#ifndef __STR_BLOB__
#define __STR_BLOB__

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(StrBlob &&) = default;
    StrBlob(const StrBlob &) = default;
    StrBlob(std::initializer_list<std::string> il);
    StrBlob &operator=(StrBlob &&) = default;
    StrBlob &operator=(const StrBlob &) = default;
    ~StrBlob();

    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    void push_back(const std::string &s) {
        data->push_back(s);
    }
    void pop_back();
    std::string& front();
    std::string& back();
    std::string& front() const;
    std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

#endif // !__STR_BLOB__
