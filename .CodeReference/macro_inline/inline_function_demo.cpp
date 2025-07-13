/**
 * Inline Function Demo - Understanding inline keyword
 * Estimated completion time: 8-10 minutes
 *
 * Learning objectives:
 * - Practice writing inline functions
 * - Understand type safety in inline functions
 * - Compare inline functions with regular functions
 */

#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

// TODO 1: Create an inline function called 'square' that takes an int parameter
// and returns its square
// Hint: inline return_type function_name(parameters) { ... }
// Write your code here:
inline int square(int a)
{
    return a * a;
}

// TODO 2: Create an inline function called 'max' that takes two parameters
// of the same type and returns the maximum
// Make it a template function to work with different types
// Hint: template<typename T> inline T max(T a, T b) { ... }
// Write your code here:
template <typename T>
inline T my_max(T a, T b)
{
    return ((a > b) ? a : b);
}

// TODO 3: Create an inline function called 'isEven' that checks if a number is even
// Return type should be bool
// Write your code here:
inline bool isEven(int a)
{
    return a % 2 == 0;
}

// TODO 4: Create a class called Calculator with inline member functions
class Calculator
{
private:
    // TODO 4a: Add a private member variable 'value' of type double
    // Write your code here:
    double value;

public:
    // TODO 4b: Create a constructor that takes initial value (inline in class)
    // Write your code here:
    Calculator(int initialValue) : value(initialValue) {}

    // TODO 4c: Create inline member functions for basic operations
    // add, subtract, multiply, divide (all take a double parameter)
    // Write your code here:
    inline void add(double a)
    {
        value += a;
    }
    inline void subtract(double a)
    {
        value -= a;
    }
    inline void multiply(double a)
    {
        value *= a;
    }
    // TODO 4d: Create an inline getter function to get current value
    // Write your code here:
    inline double getter()
    {
        return value;
    }
};

// TODO 5: Create an inline function outside the class for distance calculation
// Function should calculate distance between two 2D points
// Parameters: (x1, y1, x2, y2) all of type double
// Formula: sqrt((x2-x1)^2 + (y2-y1)^2)
// Write your code here:
inline double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

int main()
{
    cout << "=== Testing Inline Functions ===" << endl;

    // TODO 6: Test the square function
    cout << "--- Testing square function ---" << endl;
    int num = 8;
    // Use your square function and print result
    // Write your code here:
    cout << "square(8): " << square(8);

    cout << endl;

    // TODO 7: Test the max function with different types
    cout << "--- Testing max function ---" << endl;
    int a = 15, b = 20;
    double x = 3.7, y = 3.5;
    // Test max function with both int and double
    // Write your code here:
    cout << "max(15,20): " << my_max<int>(a,b) << endl;
    cout << "max(3.7,3.5): " << my_max<double>(x,y) << endl;

    cout << endl;

    // TODO 8: Test the isEven function
    cout << "--- Testing isEven function ---" << endl;
    // Test with numbers 4, 7, 0, -3
    // Write your code here:
    cout << "isEven(4): " << isEven(4) << endl;
    cout << "isEven(7): " << isEven(7) << endl;
    cout << "isEven(0): " << isEven(0) << endl;
    cout << "isEven(-3): " << isEven(-3) << endl;
    cout << endl;

    // TODO 9: Test the Calculator class
    cout << "--- Testing Calculator class ---" << endl;
    // Create calculator with initial value 10.0
    // Perform: add 5, subtract 3, multiply by 2, divide by 4
    // Print result after each operation
    // Write your code here:
    Calculator calc(10);
    cout << "Initial value: " << calc.getter() << endl;
    calc.add(5);
    cout << "After adding 5: " << calc.getter() << endl;
    calc.subtract(3);
    cout << "After subtracting 3: " << calc.getter() << endl;
    calc.multiply(2);
    cout << "After multiplying by 2: " << calc.getter() << endl;

    cout << endl;

    // TODO 10: Test the distance function
    cout << "--- Testing distance function ---" << endl;
    // Calculate distance between points (0,0) and (3,4)
    // Expected result: 5.0
    // Write your code here:
    cout << "Distance between (0,0) and (3,4): " << distance(0,0,3,4) << endl;

    cout << endl;

    // TODO 11: Compare inline function with macro behavior
    cout << "--- Comparing with macro behavior ---" << endl;
    int test_val = 5;

    // Test square function with ++test_val
    cout << "Before: test_val = " << test_val << endl;
    // Call square(++test_val) and observe the difference with macros
    // Write your code here:
    cout << "Square of incremented value: " << square(++test_val) << endl;
    
    cout << "After: test_val = " << test_val << endl;

    return 0;
}

/*
Expected Output (after completing all TODos):
=== Testing Inline Functions ===
--- Testing square function ---
Square of 8: 64

--- Testing max function ---
Max of 15 and 20: 20
Max of 3.7 and 3.5: 3.7

--- Testing isEven function ---
4 is even: true
7 is even: false
0 is even: true
-3 is even: false

--- Testing Calculator class ---
Initial value: 10
After adding 5: 15
After subtracting 3: 12
After multiplying by 2: 24
After dividing by 4: 6

--- Testing distance function ---
Distance between (0,0) and (3,4): 5

--- Comparing with macro behavior ---
Before: test_val = 5
Square of incremented value: 36
After: test_val = 6
*/