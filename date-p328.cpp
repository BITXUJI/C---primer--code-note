#include <string>
#include <iostream>
class Date
{
private:
    unsigned year;
    unsigned month;
    unsigned day;

public:
    Date(const std::string &s);
};
std::string month = {"January", "Febuary"};
Date::Date(const std::string &s)
{
    std::string::size_type pos;
}
