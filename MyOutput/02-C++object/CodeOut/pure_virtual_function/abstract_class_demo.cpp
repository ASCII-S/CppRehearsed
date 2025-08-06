#include <iostream>
#include <string>

// Define an abstract class Animal with mixed virtual functions
class Animal {
public:
    // Pure virtual function makeSound() that returns void
    virtual void makeSound() = 0;

    // Virtual function move() with default implementation "Animal is moving"
    virtual void move() {
        std::cout << "Animal is moving" << std::endl;
    }

    // Regular function getName() that returns the name
    std::string getName() {
        return name;
    }

    // Virtual destructor
    virtual ~Animal() {}

protected:
    // Protected member variable name (string)
    std::string name;
};

// Implement Dog class that inherits from Animal
class Dog : public Animal {
public:
    // Implement constructor that takes name
    Dog(const std::string& n) {
        name = n;
    }

    // Override makeSound() to print "Woof! Woof!"
    void makeSound() override {
        std::cout << "Woof! Woof!" << std::endl;
    }

    // Override move() to print "Dog is running"
    void move() override {
        std::cout << "Dog is running" << std::endl;
    }

    // Add a new function fetch() that prints "Dog is fetching"
    void fetch() {
        std::cout << "Dog is fetching" << std::endl;
    }
};

// Implement Cat class that inherits from Animal
class Cat : public Animal {
public:
    // Implement constructor that takes name
    Cat(const std::string& n) {
        name = n;
    }

    // Override makeSound() to print "Meow! Meow!"
    void makeSound() override {
        std::cout << "Meow! Meow!" << std::endl;
    }

    // Override move() to print "Cat is walking gracefully"
    void move() override {
        std::cout << "Cat is walking gracefully" << std::endl;
    }

    // Add a new function climb() that prints "Cat is climbing"
    void climb() {
        std::cout << "Cat is climbing" << std::endl;
    }
};

// Implement a function to demonstrate abstract class features
void demonstrateAbstractClass(Animal* animal) {
    animal->makeSound();
    animal->move();
    std::cout << "Name: " << animal->getName() << std::endl;
}

int main() {
    std::cout << "=== Abstract Class Demo ===" << std::endl;
    
    // Create instances of concrete classes
    Dog buddy("Buddy");
    Cat whiskers("Whiskers");
    
    // Demonstrate polymorphism and abstract class features
    demonstrateAbstractClass(&buddy);
    demonstrateAbstractClass(&whiskers);
    
    // Test that abstract class cannot be instantiated
    // Animal animal; // Uncomment this line to see the compilation error
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
}