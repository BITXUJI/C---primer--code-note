#include <iostream>
#include <string>
using namespace std;

main()
{
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + "\n";
    string s4 = s1 + ", ";

    // error: invalid operands of types 'const char [6]' and 'const char [3]' to binary 'operator+'
    // string s5 = "hello" + ", ";

    string s6 = s1 + ", " + "world";
    //string s6 = (s1 + ", " + "world");

    //error: invalid operands of types 'const char [6]' and 'const char [3]' to binary 'operator+'
    //string s7 = "hello" + ", " + s2;
    string s7 = "hello" + (", " + s2);
}