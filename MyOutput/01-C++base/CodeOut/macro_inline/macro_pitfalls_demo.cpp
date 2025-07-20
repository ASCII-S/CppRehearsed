/**
 * Macro Pitfalls Demo - Understanding common macro problems
 * Estimated completion time: 10 minutes
 * 
 * Learning objectives:
 * - Identify common macro pitfalls
 * - Understand why these problems occur
 * - Learn how to write safer macros
 * - Compare with inline function solutions
 */

#include <iostream>
using namespace std;

// Problematic macros - DO NOT USE THESE IN REAL CODE!

// TODO 1: Analyze this problematic SQUARE macro
#define BAD_SQUARE(x) x*x

// TODO 2: Create a safer version of SQUARE macro
// Hint: Use parentheses around the entire expression and parameters
// Write your code here:
#define SAFE_SQUARE(x) (x)*(x)


// TODO 3: Analyze this problematic MAX macro
#define BAD_MAX(a,b) a > b ? a : b

// TODO 4: Create a safer version of MAX macro
// Write your code here:
#define SAFE_MAX(a,b) ((a>b) ? a : b)


// TODO 5: Analyze this problematic INCREMENT macro
#define BAD_INCREMENT(x) ++x
#define SAFE_INCREMENT(x) (++x)

// TODO 6: Multi-line macro pitfall
#define BAD_SWAP(a,b) \
    int temp = a; \
    a = b; \
    b = temp;

// TODO 7: Create a safer version of SWAP macro
// Hint: Use do-while(0) pattern or statement expression
// Write your code here:
#define SAFE_SWAP(a,b)\
    int (temp) = (a); \
    (a) = (b); \
    (b) = (temp);


// TODO 8: Type-unsafe macro
#define UNSAFE_ABS(x) ((x) < 0 ? -(x) : (x))

// TODO 9: Create inline function alternatives
// Write inline functions that replace the problematic macros above
// Write your code here:




int main() {
    cout << "=== Macro Pitfalls Demonstration ===" << endl;
    
    // TODO 10: Demonstrate BAD_SQUARE pitfall
    cout << "--- Pitfall 1: Operator Precedence ---" << endl;
    cout << "Testing BAD_SQUARE(3+2):" << endl;
    cout << "Expected: 25, Actual: " << BAD_SQUARE(3+2) << endl;
    
    // TODO 11: Test your safer SQUARE macro
    cout << "Testing SAFE_SQUARE(3+2):" << endl;
    // Write your test here:
    
    
    cout << endl;
    
    // TODO 12: Demonstrate BAD_MAX pitfall
    cout << "--- Pitfall 2: Missing Parentheses ---" << endl;
    int result1 = BAD_MAX(2+3, 4);
    cout << "BAD_MAX(2+3, 4) = " << result1 << " (wrong!)" << endl;
    
    // TODO 13: Test your safer MAX macro
    // Write your test here:
    
    
    cout << endl;
    
    // TODO 14: Demonstrate multiple evaluation pitfall
    cout << "--- Pitfall 3: Multiple Evaluation ---" << endl;
    int x = 5;
    cout << "Before: x = " << x << endl;
    int square_result = BAD_SQUARE(++x);
    cout << "BAD_SQUARE(++x) = " << square_result << endl;
    cout << "After: x = " << x << " (x was incremented twice!)" << endl;
    
    // TODO 15: Compare with inline function
    cout << "\nComparing with inline function:" << endl;
    int y = 5;
    cout << "Before: y = " << y << endl;
    // Test your inline square function with ++y
    // Write your code here:
    
    cout << "After: y = " << y << " (y incremented only once)" << endl;
    
    cout << endl;
    
    // TODO 16: Demonstrate BAD_SWAP pitfall
    cout << "--- Pitfall 4: Multi-statement Macro ---" << endl;
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    // This will cause problems in if statement without braces
    if (a > b)
        BAD_SWAP(a, b);
    cout << "After conditional swap: a = " << a << ", b = " << b << endl;
    
    // TODO 17: Test your safer SWAP macro
    cout << "\nTesting safer SWAP:" << endl;
    a = 5; b = 15;
    cout << "Before: a = " << a << ", b = " << b << endl;
    if (a < b)
        // Use your safer SWAP macro here
        
    cout << "After: a = " << a << ", b = " << b << endl;
    
    cout << endl;
    
    // TODO 18: Demonstrate type safety issue
    cout << "--- Pitfall 5: No Type Checking ---" << endl;
    // The macro will "work" with wrong types but may give unexpected results
    cout << "UNSAFE_ABS with string: " << UNSAFE_ABS("hello") << endl;
    
    // TODO 19: Try using your inline function with wrong type
    cout << "Inline function with wrong type:" << endl;
    // This should give a compile error - try uncommenting:
    // cout << safe_abs("hello") << endl;
    
    cout << endl;
    
    // TODO 20: Side effects demonstration
    cout << "--- Pitfall 6: Side Effects ---" << endl;
    int counter = 0;
    auto increment_counter = [&counter]() { return ++counter; };
    
    cout << "Using BAD_MAX with function calls:" << endl;
    counter = 0;
    int max_result = BAD_MAX(increment_counter(), 10);
    cout << "Result: " << max_result << ", Counter: " << counter << endl;
    
    // TODO 21: Compare with inline function
    cout << "Using inline max with function calls:" << endl;
    counter = 0;
    // Test your inline max function
    // Write your code here:
    
    
    return 0;
}

/*
Key Takeaways:
1. Macros are text replacement - no type checking
2. Parameters can be evaluated multiple times
3. Operator precedence can cause unexpected results
4. Multi-statement macros need careful handling
5. Inline functions are almost always safer

Expected issues to observe:
- BAD_SQUARE(3+2) = 11 instead of 25
- Variables incremented multiple times
- Type safety violations
- Side effects with function calls
*/ 