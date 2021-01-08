#include <iostream>
int main(int argc, const char **argv)
{
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0; // x :const int
    decltype(cj) y = x; // y : const int&

    //error: 'z' declared as reference but not initialized
    //decltype(cj) z; // z :const int&

    //decltype +reference
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b; // b : int

    //error: 'c' declared as reference but not initialized
    //decltype(*p) c; // b :const int&

    // error: 'd' declared as reference but not initialized
    //decltype((i)) d; //d :int&

    decltype(i) e; //e :int

    //decltype+pointer
    decltype(p) f; //f: int*
    return 0;
}