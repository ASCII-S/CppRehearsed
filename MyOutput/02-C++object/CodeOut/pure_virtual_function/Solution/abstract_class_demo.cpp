#include <iostream>
#include <string>

// Abstract class Animal with mixed virtual functions
class Animal {
protected:
    std::string name;
    
public:
    Animal(const std::string& n) : name(n) {}
    virtual ~Animal() {}
    
    // Pure virtual function - must be implemented by derived classes
    virtual void makeSound() const = 0;
    
    // Virtual function with default implementation
    virtual void move() const {
        std::cout << "Animal is moving" << std::endl;
    }
    
    // Regular function
    std::string getName() const { return name; }
};

// Dog class inheriting from Animal
class Dog : public Animal {
public:
    Dog(const std::string& n) : Animal(n) {}
    
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
    
    void move() const override {
        std::cout << "Dog is running" << std::endl;
    }
    
    void fetch() const {
        std::cout << "Dog is fetching" << std::endl;
    }
};

// Cat class inheriting from Animal
class Cat : public Animal {
public:
    Cat(const std::string& n) : Animal(n) {}
    
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }
    
    void move() const override {
        std::cout << "Cat is walking gracefully" << std::endl;
    }
    
    void climb() const {
        std::cout << "Cat is climbing" << std::endl;
    }
};

// Function to demonstrate abstract class features
void demonstrateAnimal(Animal* animal) {
    std::cout << "Animal: " << animal->getName() << std::endl;
    animal->makeSound();
    animal->move();
    std::cout << "---" << std::endl;
}

int main() {
    std::cout << "=== Abstract Class Demo ===" << std::endl;
    
    // Create instances of concrete classes
    Dog dog("Buddy");
    Cat cat("Whiskers");
    
    // Demonstrate polymorphism and abstract class features
    Animal* animal1 = &dog;
    Animal* animal2 = &cat;
    
    demonstrateAnimal(animal1);
    demonstrateAnimal(animal2);
    
    // Test that abstract class cannot be instantiated
    // Animal animal("Test"); // This would cause compilation error
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 