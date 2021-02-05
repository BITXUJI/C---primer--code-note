#ifndef HASPTR_H
#define HASPTR_H
#include <string>
#include <iostream>
class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &, const HasPtr &);

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    // HasPtr &operator=(const HasPtr &hp)
    // {
    //     auto p = new std::string(*hp.ps);
    //     delete ps;
    //     ps = p;
    //     i = hp.i;
    //     return *this;
    // }
    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        return *this;
    }
    bool operator<(const HasPtr &rhs)
    {
        return *ps < *rhs.ps;
    }
    void show() const
    {
        std::cout << *ps << std::endl;
    }
    ~HasPtr() { delete ps; }

private:
    std::string *ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "swap(HasPtr &,HasPtr &)" << std::endl;
}
inline bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    std::cout << "compare " << *lhs.ps << " and " << *rhs.ps << std::endl;
    return *lhs.ps < *rhs.ps;
}
#endif