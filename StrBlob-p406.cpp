#include <string>
#include "StrBlob.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    StrBlob b1;
    {
        // error: converting to 'StrBlob' from initializer list would use explicit constructor 'StrBlob::StrBlob(std::initializer_list<std::__cxx11::basic_string<char> >)'
        // StrBlob b2 = {"a", "an", "the"};
        StrBlob b2({"a", "an", "the"});
        b1 = b2;
        b2.push_back("about");
    }

    return 0;
}
