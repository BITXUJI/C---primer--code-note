#include <list>
#include <vector>
int main(int argc, char const *argv[])
{
    std::list<int> li = {1, 2, 3};
    std::vector<double> dvec(li.begin(), li.end());
    std::vector<int> ivec = {1, 2, 3, 4};
    std::vector<double> dvec1(ivec.begin(), ivec.end());
    return 0;
}
