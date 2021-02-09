#ifndef VEC_H
#define VEC_H
#include <memory>
#include <utility>
#include <initializer_list>
template <typename T>
class Vec
{
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(std::initializer_list<T> l);
    Vec(const Vec &);
    Vec(Vec &&) noexcept;
    Vec &operator=(const Vec &);
    Vec &operator=(Vec &&) noexcept;
    ~Vec();
    void push_back(const T &);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    void reserve(std::size_t n);
    void resize(std::size_t n);
    void resize(std::size_t n, const T &t);

private:
    static std::allocator<T> alloc;
    void chk_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> alloc_n_copy(const T *, const T *);
    void free();
    void reallocate();
    void wy_alloc_n_move(std::size_t n);
    T *elements;
    T *first_free;
    T *cap;
};
template <typename T>
std::allocator<T> Vec<T>::alloc;
template <typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *first, const T *last)
{
    auto data = alloc.allocate(last - first);

    return std::make_pair(data, std::uninitialized_copy(first, last, data));
}
template <typename T>
void Vec<T>::free()
{
    if (elements) // not nullptr
    {
        while (first_free != elements)
            alloc.destroy(--first_free);
        alloc.deallocate(elements, cap - elements);
    }
}
template <typename T>
void Vec<T>::reallocate()
{
    std::size_t newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first); // move elements
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}
template <typename T>
void Vec<T>::wy_alloc_n_move(std::size_t n)
{
    // allocate as required.
    std::size_t newCapacity = n;
    T *newData = alloc.allocate(newCapacity);

    // move the data from old place to the new one
    T *dest = newData;
    T *old = elements;
    for (std::size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*old++));

    free();

    // update data structure
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}
template <typename T>
Vec<T>::~Vec()
{
    free();
}
template <typename T>
Vec<T>::Vec(std::initializer_list<T> l)
{
    auto p = alloc_n_copy(l.begin(), l.end());
    elements = p.first;
    cap = first_free = p.second;
}
template <typename T>
Vec<T>::Vec(const Vec &rhs)
{
    auto p = alloc_n_copy(rhs.begin(), rhs.end());
    elements = p.first;
    cap = first_free = p.second;
}
template <typename T>
Vec<T>::Vec(Vec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}
template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    auto p = alloc_n_copy(rhs.begin(), rhs.end());
    free(); //remember to free old memory
    elements = p.first;
    cap = first_free = p.second;
    return *this;
}
template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free(); //free first
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
void Vec<T>::push_back(const T &rhs)
{
    chk_n_alloc();
    alloc.construct(first_free++, rhs);
}
template <typename T>
void Vec<T>::reserve(std::size_t n)
{
    if (n <= capacity())
        return;
    wy_alloc_n_move(n);
}

template <typename T>
void Vec<T>::resize(std::size_t n)
{
    resize(n, T());
}
template <typename T>
void Vec<T>::resize(std::size_t n, const T &t)
{
    if (n < size())
    {
        // destroy the range [element+n, first_free) using destructor
        for (auto p = elements + n; p != first_free;)
            alloc.destroy(p++);
        // update first_free to point to the new address
        first_free = elements + n;
    }
    else if (n > size())
    {
        for (auto i = size(); i != n; ++i)
            push_back(t);
    }
}
#endif // !VEC_H
