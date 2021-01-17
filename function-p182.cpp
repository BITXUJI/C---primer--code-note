#include <iostream>
#include <vector>
#include <string>
int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

void f1()
{ /**/
}
void f2(void)
{ /**/
}

// error: 'v2' has not been declared
// int f3(int v1, v2)
// { /**/
// }

int f4(int v1, int v2)
{ /**/
}

//error: cannot convert 'std::string' {aka 'std::__cxx11::basic_string<char>'} to 'int' in return
// int f5()
// {
//     std::string s;
//     return s;
// }
f6(int i)
{
    /**/
}

//error: redefinition of 'int v1'
// int calc(int v1, int v1)
// {
//     /**/
// }

//error: named return values are no longer supported
// double square(double x) return x * x;

double square(double x)
{
    return x * x;
}
int main(int argc, char const *argv[])
{
    int num = fact(5);
    //error: invalid conversion from 'const char*' to 'int' [-fpermissive]
    // fact("hello");

    // error:too few arguments to function 'int fact(int)'
    //  fact();
    //error:too many arguments to function 'int fact(int)'
    // fact(21, 22);
    fact(3.14);
    std::cout << num << std::endl;
    return 0;
}
