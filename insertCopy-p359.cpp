#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <iostream>
template <typename Sequence>
void print(Sequence const &seq)
{
    for (const auto &i : seq)
        std::cout << i << " ";
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> idq;
    std::list<int> ilst;
    std::forward_list<int> iflst;
    std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(idq));
    std::copy(ivec.cbegin(), ivec.cend(), std::inserter(ilst, ilst.begin()));
    std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(iflst));
    for (const auto &item : idq)
        std::cout << item << " ";
    std::cout << std::endl;
    for (const auto &item : ilst)
        std::cout << item << " ";
    std::cout << std::endl;
    for (const auto &item : iflst)
        std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
