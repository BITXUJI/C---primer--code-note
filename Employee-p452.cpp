#include <string>
#include <iostream>
class Employee
{
    friend std::ostream &operator<<(std::ostream &, const Employee &);

public:
    Employee() = default;
    Employee(const std::string &nm) : name(nm) { id = number++; }
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

private:
    std::size_t id;
    static std::size_t number;
    std::string name;
};
std::size_t Employee::number = 5;
std::ostream &operator<<(std::ostream &os, const Employee &emp)
{
    os << emp.name << " " << emp.id;
    return os;
}

int main(int argc, char const *argv[])
{
    Employee a("simon");
    Employee b("gallagher");
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
