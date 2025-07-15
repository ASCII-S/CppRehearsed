#include <iostream>
using namespace std;

// TODO 1: Define a base class named Animal
// Requirements:
// - Add a virtual function named makeSound() that prints "Animal makes a sound"
// - Add a data member named age of type int
class Animal{
    int age;
public:
    virtual void makeSound(){
        std::cout << "Animal makes a sound" << std::endl;
    }
};
// TODO 2: Define a derived class named Dog that inherits from Animal
// Requirements:
// - Override the makeSound() function to print "Dog barks"
// - Add a unique function named wagTail() that prints "Dog wags tail"
// - Add a data member named breed of type string
class Dog  : public Animal{
    string breed;
public:
    void makeSound() override
    {
        std::cout << "Dog barks~" << std::endl;
    }

    void wagTail(){
        std::cout << "Dog wags tail" << std::endl;
    }
};

// TODO 3: Define another derived class named Cat that inherits from Animal
// Requirements:
// - Override the makeSound() function to print "Cat meows"
// - Add a unique function named climb() that prints "Cat climbs tree"
class Cat : public Animal
{
public :
    void makeSound() override
    {
        std::cout << "Cat meows" << std::endl;
    }

    void climb() 
    {
        std::cout << "Cat climbs tree" << std::endl;
    }
};

int main() {
    cout << "=== static_cast Demo ===" << endl;
    
    // TODO 4: Basic type conversion using static_cast
    // Requirements:
    // - Convert integer 65 to char using static_cast
    // - Convert double 3.14 to int using static_cast
    // - Print both results
    
    cout << "\n=== Basic Type Conversion ===" << endl;
    int i = 65;
    std::cout << "cast int 65 to char: " << static_cast<char>(i) << std::endl;
    std::cout << "cast double 3.14 to int: " << static_cast<int>(3.14) << std::endl;
    
    // TODO 5: Safe upcast (derived to base)
    // Requirements:
    // - Create a Dog object
    // - Convert Dog* to Animal* using static_cast
    // - Call makeSound() through the Animal pointer
    
    cout << "\n=== Safe Upcast ===" << endl;
    Dog wangcai;
    Animal* ad = static_cast<Animal*>(&wangcai);
    ad->makeSound();
    
    // TODO 6: Potentially unsafe downcast (base to derived)
    // Requirements:
    // - Create an Animal pointer pointing to a Dog object
    // - Convert Animal* to Dog* using static_cast
    // - Call wagTail() through the Dog pointer
    // - Note: This works because the object is actually a Dog
    
    cout << "\n=== Downcast (when object is actually Dog) ===" << endl;
    Animal* a = new Dog();
    Dog* d = static_cast<Dog*>(a);
    d->wagTail();

    
    // TODO 7: Dangerous downcast example
    // Requirements:
    // - Create an Animal pointer pointing to a Cat object
    // - Convert Animal* to Dog* using static_cast
    // - Try to call wagTail() - this is undefined behavior!
    // - Add a comment explaining why this is dangerous
    
    cout << "\n=== Dangerous Downcast ===" << endl;
    Animal* a3 = new Cat();
    Dog* d3 = static_cast<Dog*>(a3);
    // d3->wagTail;
    d3->makeSound();
    
    // TODO 8: Void pointer conversion
    // Requirements:
    // - Create an int variable with value 42
    // - Convert int* to void* using static_cast
    // - Convert void* back to int* using static_cast
    // - Print the value to verify it works
    
    cout << "\n=== Void Pointer Conversion ===" << endl;
    int i4 = 42;
    void *vp = static_cast<void*>(&i4);
    int * ip4 = static_cast<int*>(vp);
    std::cout << "int i4: " << i4 << std::endl;
    std::cout << "int convert to void* : " << vp << std::endl;
    std::cout << "void* convert back to int* : " << *ip4 << std::endl;
    
    return 0;
}

// Note: This exercise should take approximately 8-10 minutes to complete
// Focus on understanding when static_cast is safe and when it's not 