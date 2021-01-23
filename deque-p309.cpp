#include <deque>
#include <list>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
    //std::deque<std::string> dq;
    std::list<std::string> dq;
    std::string word;
    while (std::cin >> word)
    {
        dq.push_back(word);
    }
    for (auto i = dq.begin(); i != dq.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    return 0;
}
