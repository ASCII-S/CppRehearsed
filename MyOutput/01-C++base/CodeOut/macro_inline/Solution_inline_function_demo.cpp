/**
 * Solution: Inline Function Demo - Understanding inline keyword
 * 
 * This file contains the complete solutions for all TODOs in inline_function_demo.cpp
 */

#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

// Solution 1: Inline square function
inline int square(int x) {
    return x * x;
}

// Solution 2: Template inline max function
template<typename T>
inline T max(T a, T b) {
    return (a > b) ? a : b;
}

// Solution 3: Inline isEven function
inline bool isEven(int num) {
    return (num % 2) == 0;
}

// Solution 4: Calculator class with inline member functions
class Calculator {
private:
    // Solution 4a: Private member variable
    double value;
    
public:
    // Solution 4b: Inline constructor
    Calculator(double initial_value = 0.0) : value(initial_value) {}
    
    // Solution 4c: Inline member functions for basic operations
    inline Calculator& add(double num) {
        value += num;
        return *this;
    }
    
    inline Calculator& subtract(double num) {
        value -= num;
        return *this;
    }
    
    inline Calculator& multiply(double num) {
        value *= num;
        return *this;
    }
    
    inline Calculator& divide(double num) {
        if (num != 0) {
            value /= num;
        }
        return *this;
    }
    
    // Solution 4d: Inline getter function
    inline double getValue() const {
        return value;
    }
};

// Solution 5: Inline distance calculation function
inline double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    cout << "=== Testing Inline Functions ===" << endl;
    
    // Solution 6: Test the square function
    cout << "--- Testing square function ---" << endl;
    int num = 8;
    cout << "Square of " << num << ": " << square(num) << endl;
    
    cout << endl;
    
    // Solution 7: Test the max function with different types
    cout << "--- Testing max function ---" << endl;
    int a = 15, b = 20;
    double x = 3.7, y = 3.5;
    cout << "Max of " << a << " and " << b << ": " << max(a, b) << endl;
    cout << "Max of " << x << " and " << y << ": " << max(x, y) << endl;
    
    cout << endl;
    
    // Solution 8: Test the isEven function
    cout << "--- Testing isEven function ---" << endl;
    cout << "4 is even: " << boolalpha << isEven(4) << endl;
    cout << "7 is even: " << boolalpha << isEven(7) << endl;
    cout << "0 is even: " << boolalpha << isEven(0) << endl;
    cout << "-3 is even: " << boolalpha << isEven(-3) << endl;
    
    cout << endl;
    
    // Solution 9: Test the Calculator class
    cout << "--- Testing Calculator class ---" << endl;
    Calculator calc(10.0);
    cout << "Initial value: " << calc.getValue() << endl;
    
    calc.add(5);
    cout << "After adding 5: " << calc.getValue() << endl;
    
    calc.subtract(3);
    cout << "After subtracting 3: " << calc.getValue() << endl;
    
    calc.multiply(2);
    cout << "After multiplying by 2: " << calc.getValue() << endl;
    
    calc.divide(4);
    cout << "After dividing by 4: " << calc.getValue() << endl;
    
    cout << endl;
    
    // Solution 10: Test the distance function
    cout << "--- Testing distance function ---" << endl;
    double dist = distance(0, 0, 3, 4);
    cout << "Distance between (0,0) and (3,4): " << dist << endl;
    
    cout << endl;
    
    // Solution 11: Compare inline function with macro behavior
    cout << "--- Comparing with macro behavior ---" << endl;
    int test_val = 5;
    
    cout << "Before: test_val = " << test_val << endl;
    int result = square(++test_val);
    cout << "Square of incremented value: " << result << endl;
    cout << "After: test_val = " << test_val << endl;
    
    return 0;
}

/*
Key Learning Points:

1. Inline functions provide type safety unlike macros
2. Arguments are evaluated only once
3. Template inline functions work with multiple types
4. Member functions can be inline (defined in class or with inline keyword)
5. Inline functions can be debugged
6. Compiler decides whether to actually inline

Benefits over macros:
- Type checking at compile time
- No multiple parameter evaluation
- Proper scoping rules
- Debugging support
- Template compatibility

Performance considerations:
- Reduces function call overhead
- May increase code size if overused
- Compiler optimizations may make differences negligible
- Best for small, frequently called functions
*/ 