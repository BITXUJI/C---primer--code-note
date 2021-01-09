#include <iostream>
//using namespace::name;
using std::cin;
using std::cout;
using std::endl;
using namespace std;
int main(int argc, const char **argv)
{
    int i;
    cin >> i;

    // error: 'cout' was not declared in this scope; did you mean 'std::cout'?
    // cout << i;

    std::cout << i << std::endl;
    return 0;
}