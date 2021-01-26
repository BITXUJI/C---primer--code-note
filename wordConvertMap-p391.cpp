#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
int main(int argc, char const *argv[])
{
    std::map<std::string, std::vector<std::string>> word_convert_rule;
    std::ifstream in1("word_convert_rule");
    std::ifstream in2("word_example");
    std::ofstream out("word_result", std::ofstream::app);
    std::string short_word;
    std::string long_word;
    std::string line;
    while (std::getline(in1, line))
    {
        std::istringstream record(line);
        record >> short_word;
        while (record >> long_word)
        {
            word_convert_rule[short_word].push_back(long_word);
        }
    }
    while (std::getline(in2, line))
    {
        std::ostringstream output;
        std::istringstream record(line);
        while (record >> short_word)
        {
            auto iter = word_convert_rule.find(short_word);
            if (iter != word_convert_rule.end())
            {
                long_word = "";
                for (const auto &item : iter->second)
                    long_word += item + " ";
                output << long_word;
            }
            else
            {
                output << short_word << " ";
            }
        }
        output << std::endl;
        out << output.str();
    }
    return 0;
}
