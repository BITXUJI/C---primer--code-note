#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto iter = std::unique(words.begin(), words.end());
    words.erase(iter, words.end());
}
std::string make_plural(size_t count, const std::string &word, const std::string &ending)
{
    return (count > 1) ? (word + ending) : word;
}
void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    //std::stable_sort
    auto wc = std::stable_partition(words.begin(), words.end(), [sz](const std::string &a) { return a.size() < sz; });
    //auto wc = std::find_if(words.begin(), words.end(), [sz](const std::string &a) { return a.size() >= sz; });
    //auto wc = std::partition(words.begin(), words.end(), [sz](const std::string &a) { return a.size() < sz; });
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(), [](const std::string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words, 5);
    return 0;
}
