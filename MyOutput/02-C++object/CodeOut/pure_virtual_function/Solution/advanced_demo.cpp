#include <iostream>
#include <string>

// Abstract class Base with pure virtual function that has implementation
class Base {
public:
    Base() {}
    virtual ~Base() {}
    
    // Pure virtual function with implementation
    virtual void pureVirtualFunc() = 0;
    
    void regularFunc() {
        std::cout << "Base regular function" << std::endl;
    }
};

// Implementation of pure virtual function in base class
void Base::pureVirtualFunc() {
    std::cout << "Base pure virtual function implementation" << std::endl;
}

// Derived1 class inheriting from Base
class Derived1 : public Base {
public:
    void pureVirtualFunc() override {
        std::cout << "Derived1 implementation" << std::endl;
    }
    
    void callBaseImplementation() {
        Base::pureVirtualFunc();
    }
};

// Derived2 class inheriting from Base
class Derived2 : public Base {
public:
    void pureVirtualFunc() override {
        std::cout << "Derived2 implementation" << std::endl;
    }
    
    void callBaseImplementation() {
        Base::pureVirtualFunc();
    }
};

// Abstract class with pure virtual destructor
class AbstractBase {
public:
    // Pure virtual destructor - MUST have implementation
    virtual ~AbstractBase() = 0;
    
    // Pure virtual function
    virtual void abstractFunc() = 0;
};

// Implementation of pure virtual destructor
AbstractBase::~AbstractBase() {
    std::cout << "AbstractBase destructor called" << std::endl;
}

// ConcreteClass inheriting from AbstractBase
class ConcreteClass : public AbstractBase {
public:
    void abstractFunc() override {
        std::cout << "Concrete implementation" << std::endl;
    }
    
    void concreteFunc() {
        std::cout << "Concrete function" << std::endl;
    }
};

// Function to demonstrate pure virtual function with implementation
void demonstrateBase(Base* base) {
    base->pureVirtualFunc();
    base->regularFunc();
    std::cout << "---" << std::endl;
}

int main() {
    std::cout << "=== Pure Virtual Function Advanced Demo ===" << std::endl;
    
    // Test pure virtual function with implementation
    Derived1 derived1;
    Derived2 derived2;
    
    Base* base1 = &derived1;
    Base* base2 = &derived2;
    
    demonstrateBase(base1);
    demonstrateBase(base2);
    
    // Test pure virtual destructor
    ConcreteClass concrete;
    AbstractBase* abstract = &concrete;
    
    abstract->abstractFunc();
    concrete.concreteFunc();
    
    // Demonstrate calling base implementation from derived classes
    std::cout << "\nCalling base implementation from derived classes:" << std::endl;
    derived1.callBaseImplementation();
    derived2.callBaseImplementation();
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 