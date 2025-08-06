#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// TODO 1: Define a base class Animal with virtual functions
// Requirements:
// - Add a virtual destructor
// - Add a pure virtual function makeSound()
// - Add a virtual function getName() that returns "Animal"
// - Add a virtual function getType() that returns "Base Animal"
class Animal {
public:
    // TODO 1.1: Add virtual destructor
    virtual ~Animal(){}

    // TODO 1.2: Add pure virtual function makeSound()
    virtual void makeSound() = 0;

    // TODO 1.3: Add virtual function getName()
    virtual string getName()
    {
        return "Animal";
    }

    // TODO 1.4: Add virtual function getType()
    virtual string getType()
    {
        return "Base Animal";
    }
};

// TODO 2: Define a Dog class that inherits from Animal
// Requirements:
// - Override makeSound() to return "Woof! Woof!"
// - Override getName() to return "Dog"
// - Add a new virtual function wagTail() that prints "Dog wagging tail"
class Dog : public Animal {
public:
    // TODO 2.1: Override makeSound()
    void makeSound() override
    {
        std::cout << "woof" << std::endl;
    }

    // TODO 2.2: Override getName()
    string getName() override
    {
        return "Dog";
    }

    // TODO 2.3: Add wagTail() virtual function
    virtual void wagTail()
    {
        std::cout << "wag tail" << std::endl;
    }
    
};

// TODO 3: Define a Cat class that inherits from Animal  
// Requirements:
// - Override makeSound() to return "Meow! Meow!"
// - Override getName() to return "Cat"
// - Override getType() to return "Feline"
// - Add a new virtual function purr() that prints "Cat purring"
class Cat : public Animal {
public:
    // TODO 3.1: Override makeSound()
    void makeSound() override
    {
        std::cout << "Meow" << std::endl;
    }

    // TODO 3.2: Override getName()
    string getName() override
    {
        return "Cat";
    }

    // TODO 3.3: Override getType()
    string getType() override
    {
        return "Feline";
    }

    // TODO 3.4: Add purr() virtual function
    virtual void purr()
    {
        std::cout << "purr" << std::endl;
    }
};

// TODO 4: Create a function to demonstrate polymorphism
// Requirements:
// - Function name: demonstratePolymorphism
// - Parameter: Animal* animal
// - Call makeSound(), getName(), and getType() on the animal
// - Print the results with appropriate labels
void demonstratePolymorphism(Animal* animal) {
    // TODO 4.1: Call virtual functions and print results
    animal->makeSound();
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Animal name: " << animal->getName() << std::endl;
}

// TODO 5: Create a function to show vtable pointer information
// Requirements:
// - Function name: showVTableInfo
// - Parameter: Animal* animal
// - Print the size of the object
// - Print the typeid name of the object
// - Demonstrate that vptr is the same for objects of the same class
void showVTableInfo(Animal* animal) {
    // TODO 5.1: Print object size using sizeof
    std::cout << "size of: " << sizeof(*animal) << std::endl;

    // TODO 5.2: Print type information using typeid
    std::cout << "type: " << typeid(*animal).name() << std::endl;

    // TODO 5.3: Print address of the object (to show vptr concept)
    std::cout << "address: " << reinterpret_cast<void**>(animal) << std::endl;
}

int main() {
    cout << "=== Virtual Table (vtable) Basic Demonstration ===" << endl;
    
    // TODO 6: Create objects and demonstrate vtable behavior
    // Requirements:
    // - Create Dog and Cat objects on heap
    // - Store them in Animal* pointers
    // - Call demonstratePolymorphism for each
    // - Call showVTableInfo for each
    // - Demonstrate that different objects of same class share vtable
    // - Clean up memory
    
    cout << "\n--- Creating Dog object ---" << endl;
    // TODO 6.1: Create Dog object and store in Animal* pointer
    Animal * adptr = new Dog();

    cout << "\n--- Creating Cat object ---" << endl;
    // TODO 6.2: Create Cat object and store in Animal* pointer
    Animal *acptr = new Cat();

    cout << "\n--- Demonstrating Polymorphism ---" << endl;
    // TODO 6.3: Call demonstratePolymorphism for both objects
    demonstratePolymorphism(adptr);
    demonstratePolymorphism(acptr);

    cout << "\n--- VTable Information ---" << endl;
    // TODO 6.4: Call showVTableInfo for both objects
    showVTableInfo(adptr);
    showVTableInfo(acptr);

    cout << "\n--- Multiple objects of same class ---" << endl;
    // TODO 6.5: Create another Dog object and show they share vtable
    Animal *adptr2 = new Dog();
    showVTableInfo(adptr2);

    cout << "\n--- Direct function calls vs Virtual calls ---" << endl;
    // TODO 6.6: Demonstrate difference between direct calls and virtual calls
    
    // TODO 6.7: Clean up memory

    return 0;
}

/*
Expected Output Example:
=== Virtual Table (vtable) Basic Demonstration ===

--- Creating Dog object ---

--- Creating Cat object ---

--- Demonstrating Polymorphism ---
Animal makeSound: Woof! Woof!
Animal name: Dog
Animal type: Base Animal

Animal makeSound: Meow! Meow!
Animal name: Cat
Animal type: Feline

--- VTable Information ---
Dog object size: 8 bytes
Dog type: Dog
Dog object address: 0x...

Cat object size: 8 bytes
Cat type: Cat
Cat object address: 0x...

--- Multiple objects of same class ---
Both Dog objects share the same vtable structure

--- Direct function calls vs Virtual calls ---
Virtual call resolves to derived class implementation
Direct call uses compile-time binding
*/ 