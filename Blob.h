#ifndef BLOB_H
#define BLOB_H

#include <initializer_list>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>
template <typename>
class BlobPtr;
template <typename>
class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &, const Blob<T> &);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It>
    Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    T &back();
    T &operator[](size_type i);
    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
    BlobPtr<T> end()
    {
        auto ret = BlobPtr<T>(*this, data->size());
        return ret;
    }

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()){};

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back a empty vector");
    data->pop_back();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on a empty vector");
    return data->back();
}
template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "number out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *(lhs.data) == *(rhs.data);
}

#endif // !BLOB_H