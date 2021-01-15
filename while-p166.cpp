// #include <string>
// #include <iostream>
// #include <vector>
// int main(int argc, char const *argv[])
// {
//     std::string word;
//     std::string wordmax = "";
//     int str[100] = {1};
//     std::vector<std::string> vec;
//     int index = 0;
//     std::cin >> word;
//     vec.push_back(word);
//     wordmax = word;
//     str[index] = 1;
//     while (std::cin >> word)
//     {
//         if (word == wordmax)
//         {
//             ++(str[index]);
//         }
//         else
//         {
//             str[++index] = 1;
//             wordmax = word;
//             vec.push_back(word);
//         }
//     }
//     int max1 = str[0];
//     int index1 = 0;
//     for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
//     {
//         if (str[i] > max1)
//         {
//             max1 = str[i];
//             index1 = i;
//         }
//     }

//     std::string s = vec[index1];
//     std::cout << s << " " << max1 << std::endl;
//     return 0;
// }
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;

int main()
{
    pair<string, int> max_duplicated;
    int count = 0;
    for (string str, prestr; cin >> str; prestr = str)
    {
        if (str == prestr)
            ++count;
        else
            count = 0;
        if (count > max_duplicated.second)
            max_duplicated = {prestr, count};
    }

    if (max_duplicated.first.empty())
        cout << "There's no duplicated string." << endl;
    else
        cout << "the word " << max_duplicated.first << " occurred " << max_duplicated.second + 1 << " times. " << endl;

    return 0;
}