#ifndef STRBLOB_H
#define STRBLOB_H
#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <stdexcept>
class StrBlob
{
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    explicit StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string &front();
    std::string &back();
    const std::string &front() const;
    const std::string &back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
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
    check(data->size(), "pop_back on a empty vector");
    data->pop_back();
}

std::string &StrBlob::front()
{
    check(data->size(), "front() failed");
    return data->front();
}
std::string &StrBlob::back()
{
    check(data->size(), "back() failed");
    return data->back();
}

const std::string &StrBlob::front() const
{
    check(data->size(), "front() failed");
    return data->front();
}
const std::string &StrBlob::back() const
{
    check(data->size(), "back() failed");
    return data->back();
}
#endif // !STRBLOB_H
