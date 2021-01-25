#include <numeric>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>
int main(int argc, char const *argv[])
{
    int ai[] = {1, 2, 3, 45, 6, 7, 6};
    std::vector<std::string> vec = {"hello ", "world ", "already "};
    int sum = std::accumulate(std::begin(ai), std::end(ai), 0);
    std::string strsum = std::accumulate(vec.cbegin(), vec.cend(), std::string(""));
    int val = 6;
    auto pos = std::find(std::begin(ai), std::end(ai), val);
    auto count = std::count(std::begin(ai), std::end(ai), val);
    std::cout << strsum << std::endl;
    std::cout << sum << std::endl;
    std::cout << count << std::endl;
    std::cout << *pos << std::endl;
    return 0;
}
