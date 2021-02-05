#ifndef VEC_H
#define VEC_H
#include <memory>
#include <utility>
template <typename T>
class Vec
{
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(const Vec &);
    Vec(const Vec &&) noexcept;
    Vec &operator=(const Vec &);
    Vec &operator=(const Vec &&) noexcept;
    ~Vec();
    void push_back(const T &);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }

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
Vec<T>::~Vec()
{
    free();
}
template <typename T>
Vec<T>::Vec(const Vec &rhs)
{
    auto p = alloc_n_copy(rhs.begin(), rhs.end());
    elements = p.first;
    cap = first_free = p.second;
}
template <typename T>
Vec<T>::Vec(const Vec &&rhs) noexcept : elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
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
Vec<T> &Vec<T>::operator=(const Vec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free(); //free first
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
        return *this;
    }
}

template <typename T>
void Vec<T>::push_back(const T &rhs)
{
    chk_n_alloc();
    alloc.construct(first_free++, rhs);
}

#endif // !VEC_H
