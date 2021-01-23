#include <vector>
#include <string>
int main(int argc, char const *argv[])
{
    std::vector<int> ivec = {1, 2, 3};
    std::vector<std::string> svec = {"a", "an", "the"};

    std::vector<int> ivec1(ivec);
    std::vector<int> ivec2 = ivec;
    std::vector<int> ivec3(ivec.begin(), ivec.end());
    std::vector<int> ivec4;
    std::vector<int> ivec5(10);
    std::vector<int> ivec6(10, 1);
    std::vector<std::string> svec1(10, "hi");
    std::vector<std::string> svec2{10, "hi"};
    return 0;
}
