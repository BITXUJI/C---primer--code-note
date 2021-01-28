// #include <iostream>
// #include <memory>

// int main(int argc, char const *argv[])
// {
//     const char *str1 = "Hello";
//     const char *str2 = "World";
//     std::unique_ptr<char[]> up(new char[50]);
//     for (std::size_t i = 0; i != sizeof(str1); ++i)
//         up[i] = str1[i];
//     for (std::size_t i = sizeof(str1); i != sizeof(str1) + sizeof(str2); ++i)
//         up[i] = str2[i - sizeof(str1)];
//     for()
//     return 0;
// }
#include <iostream>
#include <string>
#include <cstring>

#include <memory>

int main()
{
    const char *c1 = "Hello ";
    const char *c2 = "World";
    unsigned len = strlen(c1) + strlen(c2) + 1;
    char *r = new char[len]();
    std::strcat_s(r, len, c1);
    std::strcat_s(r, len, c2);
    std::cout << r << std::endl;

    std::string s1 = "Hello ";
    std::string s2 = "World";
    std::strcpy_s(r, len, (s1 + s2).c_str());
    std::cout << r << std::endl;

    delete[] r;

    return 0;
}