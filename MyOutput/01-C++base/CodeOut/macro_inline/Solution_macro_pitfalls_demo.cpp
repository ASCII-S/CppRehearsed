/**
 * Solution: Macro Pitfalls Demo - Understanding common macro problems
 * 
 * This file contains the complete solutions for all TODOs in macro_pitfalls_demo.cpp
 */

#include <iostream>
using namespace std;

// Problematic macros - DO NOT USE THESE IN REAL CODE!
#define BAD_SQUARE(x) x*x
#define BAD_MAX(a,b) a > b ? a : b
#define BAD_INCREMENT(x) ++x
#define BAD_SWAP(a,b) \
    int temp = a; \
    a = b; \
    b = temp;
#define UNSAFE_ABS(x) ((x) < 0 ? -(x) : (x))

// Solution 2: Safer version of SQUARE macro
#define SAFE_SQUARE(x) ((x) * (x))

// Solution 4: Safer version of MAX macro
#define SAFE_MAX(a,b) ((a) > (b) ? (a) : (b))

// Solution 7: Safer version of SWAP macro using do-while(0)
#define SAFE_SWAP(a,b) do { \
    int temp = (a); \
    (a) = (b); \
    (b) = temp; \
} while(0)

// Alternative using statement expression (GCC extension)
#define SAFE_SWAP_EXPR(a,b) ({ \
    int temp = (a); \
    (a) = (b); \
    (b) = temp; \
})

// Solution 9: Inline function alternatives
inline int safe_square(int x) {
    return x * x;
}

template<typename T>
inline T safe_max(T a, T b) {
    return (a > b) ? a : b;
}

inline void safe_swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

template<typename T>
inline T safe_abs(T x) {
    return (x < 0) ? -x : x;
}

int main() {
    cout << "=== Macro Pitfalls Demonstration ===" << endl;
    
    // Solution 10: Demonstrate BAD_SQUARE pitfall
    cout << "--- Pitfall 1: Operator Precedence ---" << endl;
    cout << "Testing BAD_SQUARE(3+2):" << endl;
    cout << "Expected: 25, Actual: " << BAD_SQUARE(3+2) << endl;
    
    // Solution 11: Test safer SQUARE macro
    cout << "Testing SAFE_SQUARE(3+2):" << endl;
    cout << "Expected: 25, Actual: " << SAFE_SQUARE(3+2) << endl;
    
    cout << endl;
    
    // Solution 12: Demonstrate BAD_MAX pitfall
    cout << "--- Pitfall 2: Missing Parentheses ---" << endl;
    int result1 = BAD_MAX(2+3, 4);
    cout << "BAD_MAX(2+3, 4) = " << result1 << " (wrong!)" << endl;
    
    // Solution 13: Test safer MAX macro
    int result2 = SAFE_MAX(2+3, 4);
    cout << "SAFE_MAX(2+3, 4) = " << result2 << " (correct!)" << endl;
    
    cout << endl;
    
    // Solution 14: Demonstrate multiple evaluation pitfall
    cout << "--- Pitfall 3: Multiple Evaluation ---" << endl;
    int x = 5;
    cout << "Before: x = " << x << endl;
    int square_result = BAD_SQUARE(++x);
    cout << "BAD_SQUARE(++x) = " << square_result << endl;
    cout << "After: x = " << x << " (x was incremented twice!)" << endl;
    
    // Solution 15: Compare with inline function
    cout << "\nComparing with inline function:" << endl;
    int y = 5;
    cout << "Before: y = " << y << endl;
    int safe_result = safe_square(++y);
    cout << "safe_square(++y) = " << safe_result << endl;
    cout << "After: y = " << y << " (y incremented only once)" << endl;
    
    cout << endl;
    
    // Solution 16: Demonstrate BAD_SWAP pitfall
    cout << "--- Pitfall 4: Multi-statement Macro ---" << endl;
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    // This will cause problems in if statement without braces
    if (a > b)
        BAD_SWAP(a, b);
    cout << "After conditional swap: a = " << a << ", b = " << b << endl;
    
    // Solution 17: Test safer SWAP macro
    cout << "\nTesting safer SWAP:" << endl;
    a = 5; b = 15;
    cout << "Before: a = " << a << ", b = " << b << endl;
    if (a < b)
        SAFE_SWAP(a, b);
    cout << "After: a = " << a << ", b = " << b << endl;
    
    cout << endl;
    
    // Solution 18: Demonstrate type safety issue
    cout << "--- Pitfall 5: No Type Checking ---" << endl;
    // The macro will "work" with wrong types but may give unexpected results
    cout << "UNSAFE_ABS with string pointer comparison:" << endl;
    // This compiles but produces meaningless result
    
    // Solution 19: Try using inline function with wrong type
    cout << "Inline function with wrong type:" << endl;
    cout << "safe_abs(-5): " << safe_abs(-5) << endl;
    cout << "safe_abs(-3.14): " << safe_abs(-3.14) << endl;
    // This would give a compile error:
    // cout << safe_abs("hello") << endl;
    
    cout << endl;
    
    // Solution 20: Side effects demonstration
    cout << "--- Pitfall 6: Side Effects ---" << endl;
    int counter = 0;
    auto increment_counter = [&counter]() { return ++counter; };
    
    cout << "Using BAD_MAX with function calls:" << endl;
    counter = 0;
    int max_result = BAD_MAX(increment_counter(), 10);
    cout << "Result: " << max_result << ", Counter: " << counter << " (function called multiple times)" << endl;
    
    // Solution 21: Compare with inline function
    cout << "Using inline max with function calls:" << endl;
    counter = 0;
    int safe_max_result = safe_max(increment_counter(), 10);
    cout << "Result: " << safe_max_result << ", Counter: " << counter << " (function called once)" << endl;
    
    return 0;
}

/*
Key Takeaways from Solutions:

1. ALWAYS use parentheses in macros:
   - Around the entire macro definition
   - Around each parameter usage
   
2. Be aware of multiple evaluation:
   - Macros expand parameters multiple times
   - Side effects occur multiple times
   - Inline functions evaluate parameters once
   
3. Multi-statement macros need protection:
   - Use do-while(0) pattern
   - Or use statement expressions (GCC extension)
   
4. Type safety:
   - Macros have no type checking
   - Inline functions provide compile-time type safety
   - Templates can provide type genericity safely
   
5. Debugging:
   - You can step through inline functions
   - Macros are hard to debug (expanded before compilation)
   
Best practices:
- Prefer inline functions over macros when possible
- Use macros only when necessary (conditional compilation, etc.)
- If you must use macros, follow safety guidelines
- Consider templates for type-generic solutions
*/ 