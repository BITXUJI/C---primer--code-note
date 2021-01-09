#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char **argv)
{
    string st1(10, 'c'), st2;
    st1 = st2;
    string s1 = "hello", s2 = "world";
    string s3 = s1 + s2;
    //  error: expected primary-expression before '=' token
    // s1 + = s2;

    s1 += s2;

    return 0;
}