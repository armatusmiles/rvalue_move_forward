#include <type_traits>
#include <utility>
#include <iostream>
using namespace std;

class Person {
public:
    template<typename T>
    explicit Person(T&& n) { cout << "Person constructor\n";}

    Person(const Person& rhs) { cout << "Person copy constructor\n"; }
    Person(Person&& rhs) { cout << "Person move constructor\n";}
};

class SpecialPerson: public Person {
public:
    SpecialPerson() : Person(0) { cout << "SpecialPerson constructor\n"; }
    SpecialPerson(const SpecialPerson& rhs)
    : Person(rhs) { cout << "SpecialPerson copy constructor\n"; }

  SpecialPerson(SpecialPerson&& rhs)
    : Person(std::move(rhs)) { cout << "SpecialPerson move constructor\n";}
};

int main()
{
    SpecialPerson p;
    cout << "\n";
    SpecialPerson p2(p);
    cout << "\n";
    SpecialPerson p3(std::move(p));
}