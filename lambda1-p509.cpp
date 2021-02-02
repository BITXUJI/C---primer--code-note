#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
class stringCmp
{
private:
    std::size_t lowbound;
    std::size_t upbound;

public:
    stringCmp(std::size_t lb = 0, std::size_t ub = -1) : lowbound(lb), upbound(ub) {}
    bool operator()(const std::string &s) const
    {
        return (s.size() >= lowbound) && (s.size() <= upbound);
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
    std::size_t lb = 1;
    std::size_t ub = 9;
    auto count = std::count_if(svec.cbegin(), svec.cend(), stringCmp(lb, ub));
    std::cout << " the word of length between " << lb << " and " << ub << " count: " << count << std::endl;
    lb = 10;
    ub = -1;
    count = std::count_if(svec.cbegin(), svec.cend(), stringCmp(lb, ub));
    std::cout << " the word of length between " << lb << " and " << ub << " count: " << count << std::endl;
    return 0;
}
