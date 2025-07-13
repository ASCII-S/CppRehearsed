#include <iostream>
#include <typeinfo>
using namespace std;

// TODO 1: Define a polymorphic base class named Shape
// Requirements:
// - Add a virtual destructor
// - Add a pure virtual function named area() that returns double
// - Add a virtual function named getName() that returns "Shape"

// TODO 2: Define a derived class named Circle that inherits from Shape
// Requirements:
// - Add a private member radius of type double
// - Add a constructor that takes radius parameter
// - Override area() to return π * radius²  (use 3.14159 for π)
// - Override getName() to return "Circle"
// - Add a unique function named getRadius() that returns radius

// TODO 3: Define a derived class named Rectangle that inherits from Shape
// Requirements:
// - Add private members width and height of type double
// - Add a constructor that takes width and height parameters
// - Override area() to return width * height
// - Override getName() to return "Rectangle"
// - Add a unique function named getPerimeter() that returns 2*(width+height)

// TODO 4: Create a function named processShape
// Requirements:
// - Take a Shape* parameter
// - Use dynamic_cast to safely check if it's a Circle
// - If it's a Circle, call getRadius() and print the radius
// - Use dynamic_cast to safely check if it's a Rectangle
// - If it's a Rectangle, call getPerimeter() and print the perimeter
// - If neither, print "Unknown shape type"

int main() {
    cout << "=== dynamic_cast Demo ===" << endl;
    
    // TODO 5: Create shape objects
    // Requirements:
    // - Create a Circle object with radius 5.0
    // - Create a Rectangle object with width 4.0 and height 3.0
    // - Store them in Shape* pointers
    
    cout << "\n=== Creating Shapes ===" << endl;
    
    // TODO 6: Safe downcast with dynamic_cast
    // Requirements:
    // - Use dynamic_cast to convert Shape* to Circle*
    // - Check if the cast succeeded (pointer is not nullptr)
    // - If successful, call getRadius() and print the result
    // - If failed, print "Not a circle"
    
    cout << "\n=== Safe Downcast to Circle ===" << endl;
    
    // TODO 7: Failed downcast example
    // Requirements:
    // - Try to cast a Rectangle* to Circle* using dynamic_cast
    // - Check the result and print appropriate message
    
    cout << "\n=== Failed Downcast Example ===" << endl;
    
    // TODO 8: Reference casting with exception handling
    // Requirements:
    // - Create a Shape reference from a Circle object
    // - Use try-catch to handle dynamic_cast with references
    // - Catch std::bad_cast exception and print error message
    
    cout << "\n=== Reference Casting with Exceptions ===" << endl;
    
    // TODO 9: Use the processShape function
    // Requirements:
    // - Call processShape with each shape pointer
    // - Observe how dynamic_cast enables safe type checking
    
    cout << "\n=== Using processShape Function ===" << endl;
    
    return 0;
}

// Note: This exercise should take approximately 10 minutes to complete
// Focus on understanding runtime type checking and safe casting 