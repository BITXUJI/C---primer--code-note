#include <string>
#include <iostream>
#include <fstream>
#include <vector>
int main(int argc, char const *argv[])
{
    std::string character_select = "acemnorsuvwxz";
    std::ifstream is("words");
    std::string word;
    std::string word_selected;
    std::string::size_type max = 0;
    while (is >> word)
    {
        if (word.find_first_not_of(character_select) == std::string::npos)
        {
            if (word.size() > max)
                word_selected = word;
        }
    }
    std::cout << word_selected << std::endl;
    return 0;
}
