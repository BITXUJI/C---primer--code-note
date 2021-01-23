#include <iostream>
#include <vector>
#include <string>

int main(int argc, const char **argv)
{
    std::vector<int> v1;
    const std::vector<int> v2;
    // error: inconsistent deduction for 'auto': '__gnu_cxx::__normal_iterator<int*, std::vector<int> >'
    // and then '__gnu_cxx::__normal_iterator<const int*, std::vector<int> >'
    // auto it1 = v1.begin(), it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();
    return 0;
}