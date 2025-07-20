/**
 * Solution: Performance Comparison Demo - Macro vs Inline vs Regular Functions
 * 
 * This file contains the complete solutions for all TODOs in performance_comparison_demo.cpp
 */

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

// Performance test data
const int ITERATIONS = 1000000;

// Solution 1: Macro for simple arithmetic operation
#define MACRO_ADD(a, b) ((a) + (b))

// Solution 2: Inline function for the same operation
inline int inline_add(int a, int b) {
    return a + b;
}

// Solution 3: Regular function for the same operation
int regular_add(int a, int b) {
    return a + b;
}

// Solution 4: Complex macro for mathematical calculation
#define MACRO_COMPLEX(a, b, c) (((a) * (b)) + ((c) / 2) - 1)

// Solution 5: Inline version of the complex calculation
inline double inline_complex(double a, double b, double c) {
    return (a * b) + (c / 2.0) - 1;
}

// Solution 6: Regular function version of the complex calculation
double regular_complex(double a, double b, double c) {
    return (a * b) + (c / 2.0) - 1;
}

// Solution 7: Class with inline member functions
class MathOperations {
public:
    // Solution 7a: Inline member function for multiplication (defined in class)
    inline double multiply(double a, double b) {
        return a * b;
    }
    
    // Solution 7b: Inline member function for power calculation
    inline double square(double x) {
        return x * x;
    }
};

// Solution 8: External inline member function
inline double MathOperations::power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Add the power function declaration to the class
// (This would normally be in the class definition above)

// Performance measurement helper
template<typename Func>
double measureTime(Func func, const string& description) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start);
    cout << description << ": " << duration.count() << " microseconds" << endl;
    return duration.count();
}

int main() {
    cout << "=== Performance Comparison Demo ===" << endl;
    cout << "Iterations: " << ITERATIONS << endl << endl;
    
    // Test data
    vector<int> data_a(ITERATIONS), data_b(ITERATIONS);
    vector<double> results(ITERATIONS);
    
    // Initialize test data
    for (int i = 0; i < ITERATIONS; ++i) {
        data_a[i] = i % 100;
        data_b[i] = (i + 1) % 100;
    }
    
    // Solution 9: Performance test 1 - Simple Addition
    cout << "--- Test 1: Simple Addition ---" << endl;
    
    // Test macro performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = MACRO_ADD(data_a[i], data_b[i]);
        }
    }, "Macro ADD");
    
    // Solution 10: Test inline function performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = inline_add(data_a[i], data_b[i]);
        }
    }, "Inline ADD");
    
    // Solution 11: Test regular function performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = regular_add(data_a[i], data_b[i]);
        }
    }, "Regular ADD");
    
    cout << endl;
    
    // Solution 12: Performance test 2 - Complex Calculation
    cout << "--- Test 2: Complex Calculation ---" << endl;
    
    // Test macro performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = MACRO_COMPLEX(data_a[i], data_b[i], i);
        }
    }, "Macro COMPLEX");
    
    // Solution 13: Test inline function complex calculation
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = inline_complex(data_a[i], data_b[i], i);
        }
    }, "Inline COMPLEX");
    
    // Solution 14: Test regular function complex calculation
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = regular_complex(data_a[i], data_b[i], i);
        }
    }, "Regular COMPLEX");
    
    cout << endl;
    
    // Solution 15: Performance test 3 - Class Member Functions
    cout << "--- Test 3: Class Member Functions ---" << endl;
    MathOperations math;
    
    // Solution 16: Test inline member function performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = math.multiply(data_a[i], data_b[i]);
        }
    }, "Inline Member Function");
    
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = math.square(data_a[i]);
        }
    }, "Inline Square Function");
    
    cout << endl;
    
    // Solution 17: Compiler optimization demonstration
    cout << "--- Compiler Optimization Effects ---" << endl;
    cout << "Note: Results may vary based on compiler flags:" << endl;
    cout << "- Debug mode: -O0 (no optimization)" << endl;
    cout << "- Release mode: -O2 or -O3 (heavy optimization)" << endl;
    cout << "In release mode, differences might be minimal!" << endl;
    
    // Solution 18: Memory usage comparison
    cout << "\n--- Memory Usage Analysis ---" << endl;
    cout << "Macro: No function call overhead, but code duplication" << endl;
    cout << "Inline: May increase code size if used frequently" << endl;
    cout << "Regular: Constant memory, but function call overhead" << endl;
    
    // Solution 19: Test with different data sizes
    cout << "\n--- Scalability Test ---" << endl;
    vector<int> test_sizes = {1000, 10000, 100000, 1000000};
    
    for (int size : test_sizes) {
        cout << "\nTesting with " << size << " elements:" << endl;
        
        // Solution 20: Implement scalability test
        vector<int> test_data_a(size), test_data_b(size);
        vector<double> test_results(size);
        
        // Initialize test data
        for (int i = 0; i < size; ++i) {
            test_data_a[i] = i % 100;
            test_data_b[i] = (i + 1) % 100;
        }
        
        // Test macro
        auto macro_time = measureTime([&]() {
            for (int i = 0; i < size; ++i) {
                test_results[i] = MACRO_ADD(test_data_a[i], test_data_b[i]);
            }
        }, "  Macro");
        
        // Test inline function
        auto inline_time = measureTime([&]() {
            for (int i = 0; i < size; ++i) {
                test_results[i] = inline_add(test_data_a[i], test_data_b[i]);
            }
        }, "  Inline");
        
        // Test regular function
        auto regular_time = measureTime([&]() {
            for (int i = 0; i < size; ++i) {
                test_results[i] = regular_add(test_data_a[i], test_data_b[i]);
            }
        }, "  Regular");
        
        // Calculate ratios
        cout << "  Inline/Macro ratio: " << (double)inline_time / macro_time << endl;
        cout << "  Regular/Macro ratio: " << (double)regular_time / macro_time << endl;
    }
    
    // Additional analysis
    cout << "\n--- Key Insights ---" << endl;
    cout << "1. Performance differences are often minimal with modern compilers" << endl;
    cout << "2. Compiler optimizations can make inline/regular functions as fast as macros" << endl;
    cout << "3. Choose based on safety and maintainability, not just performance" << endl;
    cout << "4. Profile real applications, not micro-benchmarks" << endl;
    cout << "5. Consider code size impact of excessive inlining" << endl;
    
    return 0;
}

/*
Performance Analysis Results (Typical Observations):

Debug Mode (-O0):
- Macros: Usually fastest (no function call overhead)
- Inline functions: May be slower (compiler might not inline)
- Regular functions: Slowest (function call overhead)

Release Mode (-O2/-O3):
- All three approaches often have similar performance
- Compiler optimizations eliminate most differences
- Sometimes regular functions are optimized better

Key Takeaways:
1. Modern compilers are very good at optimization
2. Performance differences are often negligible
3. Safety and maintainability matter more than micro-optimizations
4. Profile actual applications, not isolated tests
5. Premature optimization is the root of all evil

When to Use Each:
- Macros: Only when necessary (conditional compilation, etc.)
- Inline functions: Small, frequently called functions
- Regular functions: Default choice for most cases

Remember: Write clear, safe code first. Optimize only when profiling shows it's necessary.
*/ 