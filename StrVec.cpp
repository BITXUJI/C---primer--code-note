#include "StrVec.h"
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>
std::allocator<std::string> StrVec::alloc;
StrVec::StrVec(std::initializer_list<std::string> rhs){
   range_initialize(rhs.begin(),rhs.end());
}
// StrVec::StrVec(const StrVec &rhs) : elements(alloc.allocate(rhs.first_free - rhs.elements)),
//                                     first_free(std::uninitialized_copy(rhs.elements, rhs.first_free, elements)),
//                                     cap(first_free)){ }
StrVec::StrVec(const StrVec &rhs)
{
    range_initialize(rhs.begin(),rhs.end());
}
// StrVec &StrVec::operator=(const StrVec &rhs)
// {
//     auto p = alloc.allocate(rhs.cap - rhs.elements);
//     auto p1=std::uninitialized_copy(rhs.elements, rhs.first_free, p);
//     free();
//     elements = p;
//     cap =first_free =p1;
//     return *this;
// }
StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    cap = first_free = newdata.second;
    return *this;
}
StrVec::~StrVec()
{
    free();
}
void StrVec::resize(std::size_t n){
    if(n>size()){
        while(n>=capacity())
            reallocate();
        while(first_free<(elements+n))
            alloc.construct(first_free++, "");
    }
    else{
        while (first_free != elements+n)
            alloc.destroy(--first_free);
    }


}
void StrVec::push_back(const std::string &rhs)
{
    chk_n_alloc();
    alloc.construct(first_free++, rhs);
}
std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *lhs, const std::string *rhs)
{
    auto data = alloc.allocate(rhs - lhs);
    return {data, std::uninitialized_copy(lhs, rhs, data)};
}
// void StrVec::free()
// {
//     if (elements)
//     {
//         auto p = first_free;
//         while (p != elements)
//             alloc.destroy(--p);
//         alloc.deallocate(elements, cap - elements);
//     }
// }
void StrVec::free(){
    if(elements){
        std::for_each(elements,first_free,
        [this](std::string &s){alloc.destroy(&s);});
    }
}
// void StrVec::reallocate()
// {
//     auto size = first_free - elements;
//     auto capacity = cap - elements;
//     auto p = alloc.allocate(capacity * 2 + 1);
//     auto p1 = std::uninitialized_copy(elements, first_free, p);
//     free();
//     elements = p;
//     first_free = p1;
//     cap = p + capacity * 2 + 1;
// }

void StrVec::reallocate(){
    auto newcapacity =size()? 2*size():1;
    auto newdata =alloc.allocate(newcapacity);
    auto dest =newdata;
    auto elem =elements;
    for(std::size_t i =0;i!=size();++i)
        alloc.construct(dest++,std::move(*elem++));
    free();
    elements =newdata;
    first_free =dest;
    cap =elements+newcapacity;
}
void StrVec::range_initialize(const std::string* lhs, const std::string* rhs)
{
	auto newdata = alloc_n_copy(lhs, rhs);
	elements = newdata.first;
	first_free = cap = newdata.second;
}