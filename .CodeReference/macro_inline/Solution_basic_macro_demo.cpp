/**
 * Solution: Basic Macro Demo - Understanding #define fundamentals
 * 
 * This file contains the complete solutions for all TODOs in basic_macro_demo.cpp
 */

#include <iostream>
#include <string>
using namespace std;

// Solution 1: Define PI macro
#define PI 3.14159

// Solution 2: Define SQUARE macro (improved version)
#define SQUARE(x) ((x)*(x))

// Solution 3: Define MAX macro
#define MAX(a,b) ((a) > (b) ? (a) : (b))

// Solution 4: Define PRINT_VAR macro using stringification
#define PRINT_VAR(var) cout << #var << " = " << var << endl

int main() {
    // Solution 5: Test PI macro
    cout << "=== Testing PI Macro ===" << endl;
    int radius = 5;
    double area = PI * radius * radius;
    cout << "Area of circle with radius " << radius << ": " << area << endl;
    
    cout << endl;
    
    // Solution 6: Test SQUARE macro
    cout << "=== Testing SQUARE Macro ===" << endl;
    int num = 7;
    int square_result = SQUARE(num);
    cout << "Square of " << num << ": " << square_result << endl;
    
    cout << endl;
    
    // Solution 7: Test MAX macro
    cout << "=== Testing MAX Macro ===" << endl;
    int a = 15, b = 23;
    int max_result = MAX(a, b);
    cout << "Maximum of " << a << " and " << b << ": " << max_result << endl;
    
    cout << endl;
    
    // Solution 8: Test PRINT_VAR macro
    cout << "=== Testing PRINT_VAR Macro ===" << endl;
    int test_value = 42;
    string name = "Alice";
    PRINT_VAR(test_value);
    PRINT_VAR(name);
    
    cout << endl;
    
    // Solution 9: Understanding macro expansion
    cout << "=== Understanding Macro Expansion ===" << endl;
    cout << "SQUARE(3+2) = " << SQUARE(3+2) << endl;
    
    return 0;
}

/*
Key Learning Points:

1. Basic macro syntax: #define NAME value
2. Function-like macros: #define NAME(params) definition
3. Always use parentheses around:
   - The entire macro definition
   - Each parameter usage
4. Stringification operator (#) converts parameter to string literal
5. Proper macro design prevents operator precedence issues

Common mistakes to avoid:
- #define SQUARE(x) x*x  // Wrong: precedence issues
- #define MAX(a,b) a > b ? a : b  // Wrong: missing parentheses

Correct versions:
- #define SQUARE(x) ((x)*(x))
- #define MAX(a,b) ((a) > (b) ? (a) : (b))
*/ 