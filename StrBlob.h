#ifndef STRBLOB_H
#define STRBLOB_H
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include <stdexcept>
class StrBlobPtr;
class StrBlob
{
public:
    friend class StrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string &front();
    std::string &back();
    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string &deref() const;
    StrBlobPtr &incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}
void StrBlob::pop_back()
{
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}
std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    data->front();
}
std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    data->back();
}
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("Unbound StrBlobPtr");
    if (i > ret->size())
        throw std::out_of_range(msg);
    return ret;
}
std::string &StrBlobPtr::deref() const
{
    auto ret = check(curr, "deref");
    return (*ret)[curr];
}
StrBlobPtr &StrBlobPtr::incr()
{
    auto ret = check(curr, "incr");
    ++curr;
    return *this;
}
StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}
#endif // !STRBLOB_H
