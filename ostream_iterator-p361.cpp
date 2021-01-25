#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
int main(int argc, char const *argv[])
{
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 6, 8};
    // for (auto e : vec)
    // {
    //     *out_iter++ = e;
    // }
    std::copy(vec.begin(), vec.end(), out_iter);
    std::cout << std::endl;
    return 0;
}
