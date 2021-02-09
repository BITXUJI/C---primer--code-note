#ifndef BLOBPTR_H
#define BLOBPTR_H

#include "Blob.h"
#include <string>
#include <vector>
#include <memory>

template <typename T>
class BlobPtr
{
public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
    T &operator*() const
    {
        auto p = check(curr, "deference past end");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto p = wptr.lock();
    if (!p)
        throw std::runtime_error("unbounded BlobPtr");
    if (i >= p->size())
        throw std::out_of_range(msg);
    return p;
}
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    auto p = *this;
    ++*this;
    return p;
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    auto p = *this;
    --*this;
    return p;
}
#endif // !BLOBPTR_H