// C++ Override Practice
// Estimated time: 10 minutes
#include <iostream>
using namespace std;

// TODO 1: Define a base class Animal
// - Add a virtual function speak() that prints "Animal sound"
class Animal
{
public:
    Animal(){}

    virtual void speak() const
    {
        cout << "Animal sound" << endl;
    }

};

// TODO 2: Define a derived class Dog
// - Override speak() to print "Woof!"
// - Use 'override' keyword
class Dog : public Animal
{
public:
    Dog(){}

    void speak() const override
    {
        cout << "Woof" << endl;
    }
};

// TODO 3: Define a derived class Cat
// - Override speak() to print "Meow!"
// - Use 'override' keyword
class Cat : public Animal
{
public:
    Cat(){}

    void speak() const override 
    {
        cout << "Meow" << endl;
    }
};

int main()
{
    // TODO 4: Create Animal, Dog, Cat objects
    // - Use base class pointer to call speak() on Dog and Cat
    // - Observe runtime polymorphism
    Animal * a = new Animal();
    a->speak();
    a = new Dog();
    a->speak();
    a = new Cat();
    a-> speak();
    return 0;
}