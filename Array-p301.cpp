#include <array>

int main(int argc, char const *argv[])
{
    std::array<int, 42> a;

    // error:declaration does not declare anything[-fpermissive]
    // std::array<std::string, 10>;
    std::array<std::string, 10> strarr;

    std::array<int, 10> ia1;
    std::array<int, 10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> ia3 = {42};
    int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //error: array must be initialized with a brace-enclosed initializer
    // int cpy[10] = digs;

    std::array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> copy = digits;
    return 0;
}
