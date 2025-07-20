// Solution for C++ Override Practice
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak() const
    {
        cout << "Animal sound" << endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void speak() const override
    {
        cout << "Meow!" << endl;
    }
};

int main()
{
    Animal a;
    Dog d;
    Cat c;
    Animal *pa = &a;
    Animal *pd = &d;
    Animal *pc = &c;
    pa->speak(); // Animal sound
    pd->speak(); // Woof!
    pc->speak(); // Meow!
    return 0;
}