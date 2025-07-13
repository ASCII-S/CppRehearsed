#include <iostream>
using namespace std;

// TODO 1: Define a base class named Animal
// Requirements:
// - Add a virtual function named makeSound() that prints "Animal makes a sound"
// - Add a data member named age of type int

// TODO 2: Define a derived class named Dog that inherits from Animal
// Requirements:
// - Override the makeSound() function to print "Dog barks"
// - Add a unique function named wagTail() that prints "Dog wags tail"
// - Add a data member named breed of type string

// TODO 3: Define another derived class named Cat that inherits from Animal
// Requirements:
// - Override the makeSound() function to print "Cat meows"
// - Add a unique function named climb() that prints "Cat climbs tree"

int main() {
    cout << "=== static_cast Demo ===" << endl;
    
    // TODO 4: Basic type conversion using static_cast
    // Requirements:
    // - Convert integer 65 to char using static_cast
    // - Convert double 3.14 to int using static_cast
    // - Print both results
    
    cout << "\n=== Basic Type Conversion ===" << endl;
    
    // TODO 5: Safe upcast (derived to base)
    // Requirements:
    // - Create a Dog object
    // - Convert Dog* to Animal* using static_cast
    // - Call makeSound() through the Animal pointer
    
    cout << "\n=== Safe Upcast ===" << endl;
    
    // TODO 6: Potentially unsafe downcast (base to derived)
    // Requirements:
    // - Create an Animal pointer pointing to a Dog object
    // - Convert Animal* to Dog* using static_cast
    // - Call wagTail() through the Dog pointer
    // - Note: This works because the object is actually a Dog
    
    cout << "\n=== Downcast (when object is actually Dog) ===" << endl;
    
    // TODO 7: Dangerous downcast example
    // Requirements:
    // - Create an Animal pointer pointing to a Cat object
    // - Convert Animal* to Dog* using static_cast
    // - Try to call wagTail() - this is undefined behavior!
    // - Add a comment explaining why this is dangerous
    
    cout << "\n=== Dangerous Downcast ===" << endl;
    
    // TODO 8: Void pointer conversion
    // Requirements:
    // - Create an int variable with value 42
    // - Convert int* to void* using static_cast
    // - Convert void* back to int* using static_cast
    // - Print the value to verify it works
    
    cout << "\n=== Void Pointer Conversion ===" << endl;
    
    return 0;
}

// Note: This exercise should take approximately 8-10 minutes to complete
// Focus on understanding when static_cast is safe and when it's not 