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
    String(const String &&) noexcept;
    String &operator=(const String &);
    String &operator=(const String &&) noexcept;
    const char *c_str();
    char *begin() const { return first; }
    char *end() const { return end; }
    std::size_t size() const { return end - first; }
    std::size_t length() const { return end - first + 1; }
    ~String();

private:
    std::pair<char *, char *> allc_n_copy(const char *, const char *);
    void free();
    static std::allocator<char> alloc;
    char *first;
    char *end;
};
std::allocator<char> String::alloc;

std::pair<char *, char *> String::allc_n_copy(const char *frst, const char *lst)
{
    auto newdata = alloc.allocate(lst - frst);
    return std::make_pair(newdata, std::uninitialized_copy(frst, lst, newdata));
}

void String::free()
{
    if (first)
    {
        std::for_each(first, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(first, end - first);
    }
}
String::~String()
{
    free();
}

String::String(const char *s)
{
}

String::String(const String &)
{
}
String::String(const String &&) noexcept
{
}

String &String::operator=(const String &)
{
}
String &String::operator=(const String &&) noexcept
{
}
const char *String::c_str()
{
}

#endif // !STRING_H
