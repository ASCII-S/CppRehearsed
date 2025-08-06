#include <iostream>
#include <string>

// TODO 1: Define an abstract class Base with pure virtual function that has implementation
// - Add a pure virtual function pureVirtualFunc() with implementation
// - Add a virtual destructor with implementation
// - Add a regular function regularFunc() that prints "Base regular function"

// TODO 2: Implement Derived1 class that inherits from Base
// - Override pureVirtualFunc() to print "Derived1 implementation"
// - Add a function that calls base class implementation using Base::pureVirtualFunc()

// TODO 3: Implement Derived2 class that inherits from Base
// - Override pureVirtualFunc() to print "Derived2 implementation"
// - Add a function that calls base class implementation using Base::pureVirtualFunc()

// TODO 4: Define an abstract class with pure virtual destructor
// - Create class AbstractBase with pure virtual destructor
// - Implement the pure virtual destructor (it must have implementation)
// - Add a pure virtual function abstractFunc() that returns void

// TODO 5: Implement ConcreteClass that inherits from AbstractBase
// - Implement abstractFunc() to print "Concrete implementation"
// - Add a regular function concreteFunc() that prints "Concrete function"

// TODO 6: Implement a function to demonstrate pure virtual function with implementation
// - Create a function that takes Base pointer
// - Call pureVirtualFunc() and regularFunc()
// - Show how derived classes can call base implementation

int main() {
    std::cout << "=== Pure Virtual Function Advanced Demo ===" << std::endl;
    
    // TODO 7: Test pure virtual function with implementation
    // - Create Derived1 and Derived2 objects
    // - Create Base pointers pointing to these objects
    // - Call the demonstration function with these pointers
    // - Show that derived classes can call base implementation
    
    // TODO 8: Test pure virtual destructor
    // - Create ConcreteClass object
    // - Create AbstractBase pointer pointing to it
    // - Call abstractFunc() and concreteFunc()
    // - Show that pure virtual destructor works correctly
    
    // TODO 9: Demonstrate calling base implementation from derived classes
    // - Call functions in Derived1 and Derived2 that use Base::pureVirtualFunc()
    // - Show the difference between calling derived and base implementations
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 