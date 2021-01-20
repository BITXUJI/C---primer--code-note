#ifndef CONSTRUCTIONP262_H
#define CONSTRUCTIONP262_H
#include <string>
#include <vector>
class NoDefault
{

public:
    //NoDefault() = default;
    NoDefault(const std::string &s) : str(s) {}

private:
    std::string str;
};

std::vector<NoDefault> vec(10);

struct A
{
    NoDefault my_mem;
    A(const std::string &s = "") : my_mem(s) {}
};
A a;
std::vector<A> vec1(10);
struct B
{
    B(const std::string &s = "") : b_member(s) {}
    NoDefault b_member;
};

std::vector<B> vec2(10);
#endif // !CONSTRUCTIONP262_H