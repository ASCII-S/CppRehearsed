#include <iostream>
#include <cmath>

// TODO 1: Define an abstract class Shape with a pure virtual function calculateArea()
// - Add a pure virtual function calculateArea() that returns double
// - Add a virtual destructor
// - Add a protected member variable name (string)

// TODO 2: Implement Circle class that inherits from Shape
// - Add radius as private member variable
// - Implement constructor that takes radius and name
// - Override calculateArea() to return π * radius²
// - Add getter for radius

// TODO 3: Implement Rectangle class that inherits from Shape
// - Add width and height as private member variables
// - Implement constructor that takes width, height and name
// - Override calculateArea() to return width * height
// - Add getters for width and height

// TODO 4: Implement a function that demonstrates polymorphism
// - Create a function that takes Shape pointer and prints area
// - Use this function to demonstrate different shapes

int main() {
    std::cout << "=== Pure Virtual Function Basic Demo ===" << std::endl;
    
    // TODO 5: Create instances of Circle and Rectangle
    // - Create a Circle with radius 5.0 and name "Circle"
    // - Create a Rectangle with width 4.0, height 6.0 and name "Rectangle"
    
    // TODO 6: Demonstrate polymorphism using base class pointers
    // - Create Shape pointers pointing to Circle and Rectangle objects
    // - Call the demonstration function with these pointers
    
    // TODO 7: Test that abstract class cannot be instantiated
    // - Try to create a Shape object (this should cause compilation error)
    // - Comment out this line after testing
    
    std::cout << "\n=== Demo completed ===" << std::endl;
    return 0;
} 