#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>
#include <utility>
#include<initializer_list>
class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    void resize(std::size_t );
    void push_back(const std::string &);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
    void range_initialize(const std::string*, const std::string*);
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

#endif // !STRVEC_H