#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
int main(int argc, char const *argv[])
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int> ivec(in_iter, eof);
    std::sort(ivec.begin(), ivec.end());
    std::ostream_iterator<int> out_iter(std::cout, " ");
    // std::copy(ivec.cbegin(), ivec.cend(), out_iter);
    std::unique_copy(ivec.cbegin(), ivec.cend(), out_iter);
    std::cout << std::endl;
    return 0;
}
