/**
 * Basic Macro Demo - Understanding #define fundamentals
 * Estimated completion time: 8-10 minutes
 * 
 * Learning objectives:
 * - Understand how macros work as text replacement
 * - Practice writing basic macros
 * - See macro expansion in action
 */

#include <iostream>
#include <string>
using namespace std;

// TODO 1: Define a macro called PI with value 3.14159
// Hint: #define MACRO_NAME value
// Write your code here:
#define PI 3.14159

// TODO 2: Define a macro called SQUARE(x) that returns x*x
// Hint: Be careful with parentheses for proper precedence
// Write your code here:
#define SQUARE(x) x*x

// TODO 3: Define a macro called MAX(a,b) that returns the maximum of two values
// Hint: Use conditional operator (a > b) ? a : b
// Remember to wrap parameters in parentheses
// Write your code here:
#define MAX(a,b) ((a>b) ? a : b)

// TODO 4: Define a macro called PRINT_VAR(var) that prints variable name and value
// Example: PRINT_VAR(x) should print "x = 5" if x is 5
// Hint: Use #var to convert parameter to string
// Write your code here:
#define PRINT_VAR(var) std::cout << #var << " = " << var << std::endl

int main() {
    // TODO 5: Test PI macro
    // Calculate area of circle with radius 5
    // Formula: area = PI * radius * radius
    cout << "=== Testing PI Macro ===" << endl;
    int radius = 5;
    // Write your calculation here:
    cout << "PI * radius: " << PI * radius << endl;
    
    cout << endl;
    
    // TODO 6: Test SQUARE macro
    cout << "=== Testing SQUARE Macro ===" << endl;
    int num = 7;
    // Calculate square of num using your SQUARE macro
    // Write your code here:
    cout << "Square of " << num << ": " << SQUARE(num) << endl;
    
    
    cout << endl;
    
    // TODO 7: Test MAX macro
    cout << "=== Testing MAX Macro ===" << endl;
    int a = 15, b = 23;
    // Find maximum of a and b using your MAX macro
    // Write your code here:
    cout << "Maximum of " << a << " and " << b << ": " << MAX(a,b) << endl;
    
    cout << endl;
    
    // TODO 8: Test PRINT_VAR macro
    cout << "=== Testing PRINT_VAR Macro ===" << endl;
    int test_value = 42;
    string name = "Alice";
    // Use PRINT_VAR to print both variables
    // Write your code here:
    PRINT_VAR(test_value);
    PRINT_VAR(name);
    
    cout << endl;
    
    // TODO 9: Understand macro expansion
    cout << "=== Understanding Macro Expansion ===" << endl;
    // What will happen when we use SQUARE(3+2)?
    // First, predict the result, then test it
    cout << "SQUARE(3+2) = ";
    // Write your code here:
    cout << SQUARE(3+2) << endl;
    
    // TODO 10: Fix the above issue
    // Modify your SQUARE macro to handle expressions correctly
    // Test with SQUARE(3+2) again and compare results
    #define SQUARE2(x) (x)*(x)
    cout << "SQUARE2(3+2) = ";
    cout << SQUARE2(3+2) << endl;

    // demostration of the double counting problem of macro
    int i = 10;
    cout << "i = " << i << endl;
    cout << "SQUARE2(++i):" << SQUARE2(++i) << endl;
    cout << "i = " << i << endl;
    
    return 0;
}

/*
Expected Output (after completing all TODOs):
=== Testing PI Macro ===
Area of circle with radius 5: 78.5397

=== Testing SQUARE Macro ===
Square of 7: 49

=== Testing MAX Macro ===
Maximum of 15 and 23: 23

=== Testing PRINT_VAR Macro ===
test_value = 42
name = Alice

=== Understanding Macro Expansion ===
SQUARE(3+2) = 25 (after fixing the macro)
*/ 