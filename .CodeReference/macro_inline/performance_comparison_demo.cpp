/**
 * Performance Comparison Demo - Macro vs Inline vs Regular Functions
 * Estimated completion time: 10 minutes
 * 
 * Learning objectives:
 * - Compare performance of macros, inline functions, and regular functions
 * - Understand when performance differences matter
 * - Learn about compiler optimizations
 * - Practice measuring execution time
 */

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

// Performance test data
const int ITERATIONS = 1000000;

// TODO 1: Define a macro for simple arithmetic operation
#define MACRO_ADD(a, b) ((a) + (b))

// TODO 2: Create an inline function for the same operation
// Write your code here:


// TODO 3: Create a regular function for the same operation
// Write your code here:


// TODO 4: Define a more complex macro for mathematical calculation
// Calculate: (a * b) + (c / 2) - 1
#define MACRO_COMPLEX(a, b, c) (((a) * (b)) + ((c) / 2) - 1)

// TODO 5: Create inline version of the complex calculation
// Write your code here:


// TODO 6: Create regular function version of the complex calculation
// Write your code here:


// TODO 7: Create a class with inline member functions
class MathOperations {
public:
    // TODO 7a: Inline member function for multiplication
    // Define it inside the class body
    // Write your code here:
    
    
    // TODO 7b: Inline member function for power calculation (x^2)
    // Write your code here:
    
};

// TODO 8: Create external inline member function
// Define a member function outside the class with inline keyword
// Write your code here:


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
    
    // TODO 9: Performance test 1 - Simple Addition
    cout << "--- Test 1: Simple Addition ---" << endl;
    
    // Test macro performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = MACRO_ADD(data_a[i], data_b[i]);
        }
    }, "Macro ADD");
    
    // TODO 10: Test your inline function performance
    // Write your performance test here:
    
    
    // TODO 11: Test regular function performance
    // Write your performance test here:
    
    
    cout << endl;
    
    // TODO 12: Performance test 2 - Complex Calculation
    cout << "--- Test 2: Complex Calculation ---" << endl;
    
    // Test macro performance
    measureTime([&]() {
        for (int i = 0; i < ITERATIONS; ++i) {
            results[i] = MACRO_COMPLEX(data_a[i], data_b[i], i);
        }
    }, "Macro COMPLEX");
    
    // TODO 13: Test inline function complex calculation
    // Write your performance test here:
    
    
    // TODO 14: Test regular function complex calculation
    // Write your performance test here:
    
    
    cout << endl;
    
    // TODO 15: Performance test 3 - Class Member Functions
    cout << "--- Test 3: Class Member Functions ---" << endl;
    MathOperations math;
    
    // TODO 16: Test inline member function performance
    // Write your performance test here:
    
    
    cout << endl;
    
    // TODO 17: Compiler optimization demonstration
    cout << "--- Compiler Optimization Effects ---" << endl;
    cout << "Note: Results may vary based on compiler flags:" << endl;
    cout << "- Debug mode: -O0 (no optimization)" << endl;
    cout << "- Release mode: -O2 or -O3 (heavy optimization)" << endl;
    cout << "In release mode, differences might be minimal!" << endl;
    
    // TODO 18: Memory usage comparison
    cout << "\n--- Memory Usage Analysis ---" << endl;
    cout << "Macro: No function call overhead, but code duplication" << endl;
    cout << "Inline: May increase code size if used frequently" << endl;
    cout << "Regular: Constant memory, but function call overhead" << endl;
    
    // TODO 19: Test with different data sizes
    cout << "\n--- Scalability Test ---" << endl;
    vector<int> small_test_sizes = {1000, 10000, 100000, 1000000};
    
    for (int size : small_test_sizes) {
        cout << "\nTesting with " << size << " elements:" << endl;
        
        // TODO 20: Implement scalability test
        // Test how performance scales with data size
        // Write your code here:
        
    }
    
    return 0;
}

/*
Compilation instructions for different optimization levels:

Debug mode (no optimization):
g++ -O0 performance_comparison_demo.cpp -o perf_debug

Release mode (optimization):
g++ -O2 performance_comparison_demo.cpp -o perf_release

Performance analysis tips:
1. Run tests multiple times for consistent results
2. Compare relative performance, not absolute numbers
3. Consider compiler optimizations in real-world scenarios
4. Profile real applications, not micro-benchmarks
5. Remember: premature optimization is the root of all evil!

Expected observations:
- In debug mode: noticeable differences between approaches
- In release mode: minimal differences due to optimization
- Code size may increase with heavy inline usage
- Performance gains are often negligible for simple operations
*/ 