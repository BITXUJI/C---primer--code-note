#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
class Person
{
private:
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);
    std::string name;
    std::string address;
    int age = 0;

public:
    // Person(std::string name, std::string address);
    Person() = default;
    Person(const std::string &nm, const std::string &addr, const int &age) : name(nm), address(addr), age(age) {}
    Person(std::istream &is) { read(is, *this); }
    // std::string getName() const;
    // std::string getAddress() const;
    auto getName() const -> std::string const &
    {
        return name;
    }
    auto getAddress() const -> std::string const & { return address; }
    auto getAge() const -> int const & { return age; }
    ~Person();
};
inline std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.address >> person.age;
    return is;
}
inline std::ostream &print(std::ostream &os, const Person &person)
{
    os << "Person's name : " << person.name << "  Person's address : " << person.address << "  Person's age : " << person.age;
    return os;
}

// Person::Person(std::string name, std::string address)
// {
//     this->name = name;
//     this->address = address;
// }

Person::~Person()
{
}
// inline std::string Person::getName() const
// {
//     return name;
// }
// inline std::string Person::getAddress() const
// {
//     return address;
// }
#endif // !Person