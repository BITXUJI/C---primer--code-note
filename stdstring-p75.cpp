#include <iostream>
#include <string>

using std::string;

main()
{
    //string initialization
    string s1;                   //default initialization
    string s2 = s1;              //copy initialization
    string s3 = "hiya";          //copy initialization
    string s4(10, 'c');          //direct initialization
    string s5("value");          //direct initialization
    string s6 = string(10, 'c'); //copy initialization
    std::cout << s3 << " " << s4 << " " << s5 << " " << s6 << std::endl;

    if (s1.empty())
    {
        std::cout << "s1 is empty" << std::endl;
    }
    std::cout << s3.size() << std::endl;
    if (!s3.empty())
    {
        for (int i = 0; i < s3.size(); i++)
        {
            std::cout << s3[i] << std::endl;
        }
    }
    std::cout << s3 + s5 << std::endl;
    std::cout << (s2 = s5) << std::endl;
    std::cout << (s1 == s2) << std::endl;
    if (s3 < s5)
    {
        std::cout << s3 << std::endl;
    }
    else
    {
        std::cout << s5 << std::endl;
    }

    std::cin >> s1 >> s2;
    std::cout << s1 << " " << s2 << std ::endl;
    // while (getline(std::cin, s1))
    // {
    //     std::cout << s1 << std::endl;
    // }
}