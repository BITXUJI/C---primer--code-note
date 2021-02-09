#ifndef STRING_H
#define STRING_H
#include <memory>
#include <utility>
#include <algorithm>
class String
{
public:
    String() : String("") {}
    String(const char *);
    String(const String &);
    String(String &&) noexcept;
    String &operator=(const String &);
    String &operator=(String &&) noexcept;
    const char *c_str() { return elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    std::size_t size() const { return first_free - elements; }
    std::size_t length() const { return first_free - elements + 1; }
    ~String();

private:
    std::pair<char *, char *> allc_n_copy(const char *, const char *);
    void free();
    void range_initializer(const char *, const char *);
    static std::allocator<char> alloc;
    char *elements;
    char *first_free;
};
std::allocator<char> String::alloc;

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = allc_n_copy(first, last);
    elements = newstr.first;
    first_free = newstr.second;
}
std::pair<char *, char *> String::allc_n_copy(const char *b, const char *e)
{
    auto newdata = alloc.allocate(e - b);
    return std::make_pair(newdata, std::uninitialized_copy(b, e, newdata));
}

void String::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, first_free - elements);
    }
}
String::~String()
{
    free();
}

String::String(const char *s)
{
    char *s1 = const_cast<char *>(s);
    while (*s1)
    {
        ++s1;
    }
    range_initializer(s, ++s1);
}

String::String(const String &rhs)
{
    range_initializer(rhs.elements, rhs.first_free);
}
String::String(String &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free)
{
    rhs.elements = rhs.first_free = nullptr;
}

String &String::operator=(const String &rhs)
{
    auto newstr = allc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = newstr.first;
    first_free = newstr.second;
    return *this;
}
String &String::operator=(String &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        rhs.elements = rhs.first_free = nullptr;
    }
    return *this;
}

#endif // !STRING_H
