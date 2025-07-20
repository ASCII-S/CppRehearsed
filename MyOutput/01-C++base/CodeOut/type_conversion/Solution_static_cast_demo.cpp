#include <iostream>
#include <string>
using namespace std;

// Solution for TODO 1: Define a base class named Animal
class Animal {
public:
    int age;
    
    Animal(int a = 0) : age(a) {}
    
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
    
    virtual ~Animal() = default;
};

// Solution for TODO 2: Define a derived class named Dog
class Dog : public Animal {
public:
    string breed;
    
    Dog(string b = "Unknown", int a = 0) : Animal(a), breed(b) {}
    
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
    
    void wagTail() {
        cout << "Dog wags tail" << endl;
    }
};

// Solution for TODO 3: Define another derived class named Cat
class Cat : public Animal {
public:
    Cat(int a = 0) : Animal(a) {}
    
    void makeSound() override {
        cout << "Cat meows" << endl;
    }
    
    void climb() {
        cout << "Cat climbs tree" << endl;
    }
};

int main() {
    cout << "=== static_cast Demo ===" << endl;
    
    // Solution for TODO 4: Basic type conversion using static_cast
    cout << "\n=== Basic Type Conversion ===" << endl;
    
    int intValue = 65;
    char charValue = static_cast<char>(intValue);
    cout << "int 65 to char: " << charValue << endl;
    
    double doubleValue = 3.14;
    int intFromDouble = static_cast<int>(doubleValue);
    cout << "double 3.14 to int: " << intFromDouble << endl;
    
    // Solution for TODO 5: Safe upcast (derived to base)
    cout << "\n=== Safe Upcast ===" << endl;
    
    Dog dog1("Golden Retriever", 3);
    Animal* animalPtr = static_cast<Animal*>(&dog1);
    animalPtr->makeSound();  // Calls Dog::makeSound due to polymorphism
    
    // Solution for TODO 6: Potentially unsafe downcast (base to derived)
    cout << "\n=== Downcast (when object is actually Dog) ===" << endl;
    
    Animal* animalPtr2 = new Dog("Bulldog", 2);
    Dog* dogPtr = static_cast<Dog*>(animalPtr2);
    dogPtr->makeSound();
    dogPtr->wagTail();  // This works because the object is actually a Dog
    
    // Solution for TODO 7: Dangerous downcast example
    cout << "\n=== Dangerous Downcast ===" << endl;
    
    Animal* animalPtr3 = new Cat(1);
    Dog* dogPtr2 = static_cast<Dog*>(animalPtr3);
    // dogPtr2->wagTail();  // UNDEFINED BEHAVIOR! The object is actually a Cat!
    
    // Comment: This is dangerous because we're casting a Cat pointer to a Dog pointer.
    // Calling Dog-specific methods on a Cat object leads to undefined behavior.
    // static_cast doesn't perform runtime type checking, so it allows this dangerous cast.
    
    cout << "Dangerous cast performed (commented out the dangerous call)" << endl;
    
    // Solution for TODO 8: Void pointer conversion
    cout << "\n=== Void Pointer Conversion ===" << endl;
    
    int value = 42;
    int* intPtr = &value;
    void* voidPtr = static_cast<void*>(intPtr);
    int* intPtr2 = static_cast<int*>(voidPtr);
    
    cout << "Original value: " << value << endl;
    cout << "Through void pointer: " << *intPtr2 << endl;
    
    // Cleanup
    delete animalPtr2;
    delete animalPtr3;
    
    return 0;
}

// Note: This solution demonstrates both safe and unsafe uses of static_cast
// Key learning points:
// 1. static_cast is safe for basic type conversions
// 2. Upcasting (derived to base) is always safe
// 3. Downcasting (base to derived) is potentially dangerous without runtime checks
// 4. void* conversions are possible but require careful handling 