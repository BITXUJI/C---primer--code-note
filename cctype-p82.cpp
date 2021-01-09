#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(int argc, const char **argv)
{
    string s1 = "value10";
    for (auto i = 0; i < s1.size(); i++)
    {
        if (std::isdigit(s1[i]))
        {
            cout << s1[i] << endl;
        }
    }
    for (auto i : s1)
    {
        cout << i << endl;
    }
    return 0;
}