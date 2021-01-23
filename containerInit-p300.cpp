#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
int main(int argc, char const *argv[])
{
    std::list<std::string> authors = {"Milton", "Shakespeare", "Austen"};
    std::vector<const char *> articles = {"a", "an", "the"};

    std::list<std::string> list2(authors);
    // error: no matching function for call to 'std::deque<std::__cxx11::basic_string<char> >::deque(std::__cxx11::list<std::__cxx11::basic_string<char> >&)'
    // std::deque<std::string> authList(authors);
    std::deque<std::string> authList(authors.begin(), authors.end());

    //error: cannot convert 'std::__cxx11::basic_string<char>' to 'const char*' in initialization
    // std::deque<const char *> authList1(authors.begin(), authors.end());

    // error: no matching function for call to 'std::vector<std::__cxx11::basic_string<char> >::vector(std::vector<const char*>&)'
    // std::vector<std::string> words(articles);
    std::vector<std::string> words(articles.begin(), articles.end());
    std::forward_list<std::string> words1(articles.begin(), articles.end());

    //size related initialization
    std::vector<int> ivec(10, -1);
    std::list<std::string> svec(10, "hi");
    std::forward_list<int> ivec1(10);
    std::deque<std::string> svec1(10);
    return 0;
}
