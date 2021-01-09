#include <iostream>
#include <string>
int main(int argc, const char **argv)
{
    const std::string hexdigits = "0123456789ABCDEF";
    std::cout << "Enter a series of numbers between 0 and 15"
              << " separated by spaces. Hit ENTER when finished: "
              << std::endl;
    std::string result;
    std::string::size_type n;
    while (std::cin >> n)
    {
        if (n < hexdigits.size())
        {
            result += hexdigits[n];
        }
    }
    std::cout << "Yout hex number is: " << result << std::endl;

    std::string s;
    std::cout << s[0] << std::endl; //s[0] :char&
    const std::string s1 = "Keep out!";
    for (auto &c : s1) //c:const char&
    {

        //error: assignment of read-only reference 'c'
        // c = toupper(c);

        std::cout << c << std::endl;
    }

    return 0;
}