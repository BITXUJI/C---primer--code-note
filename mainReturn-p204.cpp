#include <iostream>
#include <string>
#include <cstdlib>
int main(int argc, char const *argv[])
{
    bool somefailure = true;
    if (somefailure)
    {
        return EXIT_FAILURE;
    }
    else
        return EXIT_SUCCESS;
}
