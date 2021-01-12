#include <string>
#include <vector>
#include <iostream>
int main(int argc, const char **argv)
{
    std::vector<std::string> text;
    text.push_back("Hello");
    text.push_back("world");
    text.push_back("You.");
    text.push_back("");
    text.push_back("are.");
    for (const auto &s : text)
    {
        std::cout << s;
        if (s.empty() || s[s.size() - 1] == '.')
            std::cout << std::endl;
        else
            std::cout << " ";
    }

    const char *cp = "Hello world";
    if (cp && *cp) //cp not nullptr(0) and *cp or cp[0]  is not empty
        std::cout << "hello " << *cp << std::endl;
    return 0;
}