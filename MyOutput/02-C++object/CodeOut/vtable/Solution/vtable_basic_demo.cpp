#include <iostream>
#include <typeinfo>
using namespace std;

// Solution for TODO 1: Define a base class Animal with virtual functions
class Animal {
public:
    // TODO 1.1: Add virtual destructor
    virtual ~Animal() = default;

    // TODO 1.2: Add pure virtual function makeSound()
    virtual string makeSound() = 0;

    // TODO 1.3: Add virtual function getName()
    virtual string getName() {
        return "Animal";
    }

    // TODO 1.4: Add virtual function getType()
    virtual string getType() {
        return "Base Animal";
    }
};

// Solution for TODO 2: Define a Dog class that inherits from Animal
class Dog : public Animal {
public:
    // TODO 2.1: Override makeSound()
    string makeSound() override {
        return "Woof! Woof!";
    }

    // TODO 2.2: Override getName()
    string getName() override {
        return "Dog";
    }

    // TODO 2.3: Add wagTail() virtual function
    virtual void wagTail() {
        cout << "Dog wagging tail" << endl;
    }
};

// Solution for TODO 3: Define a Cat class that inherits from Animal  
class Cat : public Animal {
public:
    // TODO 3.1: Override makeSound()
    string makeSound() override {
        return "Meow! Meow!";
    }

    // TODO 3.2: Override getName()
    string getName() override {
        return "Cat";
    }

    // TODO 3.3: Override getType()
    string getType() override {
        return "Feline";
    }

    // TODO 3.4: Add purr() virtual function
    virtual void purr() {
        cout << "Cat purring" << endl;
    }
};

// Solution for TODO 4: Create a function to demonstrate polymorphism
void demonstratePolymorphism(Animal* animal) {
    // TODO 4.1: Call virtual functions and print results
    cout << "Animal makeSound: " << animal->makeSound() << endl;
    cout << "Animal name: " << animal->getName() << endl;
    cout << "Animal type: " << animal->getType() << endl;
}

// Solution for TODO 5: Create a function to show vtable pointer information
void showVTableInfo(Animal* animal) {
    // TODO 5.1: Print object size using sizeof
    cout << animal->getName() << " object size: " << sizeof(*animal) << " bytes" << endl;

    // TODO 5.2: Print type information using typeid
    cout << animal->getName() << " type: " << typeid(*animal).name() << endl;

    // TODO 5.3: Print address of the object (to show vptr concept)
    cout << animal->getName() << " object address: " << animal << endl;
    
    // Show vtable pointer (first 8 bytes of object)
    void** vtable_ptr = *reinterpret_cast<void***>(animal);
    cout << animal->getName() << " vtable address: " << vtable_ptr << endl;
}

int main() {
    cout << "=== Virtual Table (vtable) Basic Demonstration ===" << endl;
    
    // Solution for TODO 6: Create objects and demonstrate vtable behavior
    
    cout << "\n--- Creating Dog object ---" << endl;
    // TODO 6.1: Create Dog object and store in Animal* pointer
    Animal* dog = new Dog();

    cout << "\n--- Creating Cat object ---" << endl;
    // TODO 6.2: Create Cat object and store in Animal* pointer
    Animal* cat = new Cat();

    cout << "\n--- Demonstrating Polymorphism ---" << endl;
    // TODO 6.3: Call demonstratePolymorphism for both objects
    demonstratePolymorphism(dog);
    cout << endl;
    demonstratePolymorphism(cat);

    cout << "\n--- VTable Information ---" << endl;
    // TODO 6.4: Call showVTableInfo for both objects
    showVTableInfo(dog);
    cout << endl;
    showVTableInfo(cat);

    cout << "\n--- Multiple objects of same class ---" << endl;
    // TODO 6.5: Create another Dog object and show they share vtable
    Animal* dog2 = new Dog();
    cout << "First Dog vtable: " << *reinterpret_cast<void***>(dog) << endl;
    cout << "Second Dog vtable: " << *reinterpret_cast<void***>(dog2) << endl;
    cout << "Both Dogs share the same vtable: " 
         << (*reinterpret_cast<void***>(dog) == *reinterpret_cast<void***>(dog2) ? "Yes" : "No") << endl;

    cout << "\n--- Direct function calls vs Virtual calls ---" << endl;
    // TODO 6.6: Demonstrate difference between direct calls and virtual calls
    Dog* directDog = static_cast<Dog*>(dog);
    cout << "Virtual call through Animal*: " << dog->makeSound() << endl;
    cout << "Direct call through Dog*: " << directDog->makeSound() << endl;
    cout << "Both resolve to Dog::makeSound() due to vtable mechanism" << endl;
    
    // Demonstrate compile-time vs runtime binding
    cout << "\nCompile-time binding (static call): ";
    directDog->Dog::makeSound(); // Explicit class scope - bypasses vtable
    cout << "\nRuntime binding (virtual call): " << dog->makeSound() << endl;
    
    // TODO 6.7: Clean up memory
    delete dog;
    delete cat;
    delete dog2;

    return 0;
} 