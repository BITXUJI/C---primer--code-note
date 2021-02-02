#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
class stringCmp
{
private:
    std::size_t sz;

public:
    stringCmp(std::size_t n) : sz(n) {}
    bool operator()(const std::string &s) const
    {
        return s.size() == sz;
    }
};
int main(int argc, char const *argv[])
{
    std::ifstream in("word_result");
    std::string word;
    std::vector<std::string> svec;
    while (in >> word)
    {
        svec.push_back(word);
    }
    for (std::size_t i = 1; i != 11; ++i)
    {
        auto count = std::count_if(svec.cbegin(), svec.cend(), stringCmp(i));
        std::cout << " the word of length " << i << " count: " << count << std::endl;
    }

    return 0;
}
