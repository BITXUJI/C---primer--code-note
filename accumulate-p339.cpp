#include <numeric>
#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    int sum = std::accumulate(ivec.cbegin(), ivec.cend(), 0);
    std::cout << " the sum is :" << sum << std::endl;
    std::vector<double> dvec = {1.1, 2.3};
    int dsum = std::accumulate(dvec.cbegin(), dvec.cend(), 0);
    std::cout << " the sum of dvec is:" << dsum << std::endl;
    return 0;
}
