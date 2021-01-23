#include <vector>
#include <array>
#include <list>
#include <string>

int main(int argc, char const *argv[])
{
    std::array<int, 10> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> a2 = {1};
    a1 = a2;
    //a2 = {0};
    std::list<std::string> names;
    std::vector<const char *> oldstyle;

    //error: no match for 'operator=' (operand types are 'std::__cxx11::list<std::__cxx11::basic_string<char> >' and 'std::vector<const char*>')
    // names = oldstyle;

    names.assign(oldstyle.cbegin(), oldstyle.cend());

    std::list<std::string> slist1(1);
    slist1.assign(10, "Hiya");

    std::vector<std::string> svec1(10);
    std::vector<std::string> svec2(10);
    swap(svec1, svec2);

    std::list<const char *> chlist1(10, "hi");
    std::vector<std::string> svec3;
    svec3.assign(chlist1.cbegin(), chlist1.cend());

    std::list<const char *> l{"hello", "world"};
    std::vector<std::string> v;
    v.assign(l.cbegin(), l.cend());

    return 0;
}
