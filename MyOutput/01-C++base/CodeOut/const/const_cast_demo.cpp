/*
 * const_cast_demo.cpp
 * Demonstration of const_cast in C++
 *
 * ⚠️  WARNING: const_cast is a powerful but dangerous feature!
 * This file demonstrates both safe and unsafe usage patterns.
 *
 * This file demonstrates:
 * - Basic const_cast syntax
 * - Safe usage scenarios
 * - Dangerous usage scenarios (AVOID!)
 * - Interaction with C library functions
 * - Code reuse between const/non-const functions
 *
 * TODO: Complete the code by following the instructions
 */

#include <iostream>
#include <string>
#include <cstring> // For C-style string functions
using namespace std;

// ===== Scenario 1: Safe const_cast - Original object is non-const =====

void demonstrate_safe_const_cast()
{
    cout << "=== Safe const_cast Examples ===" << endl;

    // TODO: Create a non-const variable
    // int original_value = 42;
    int original_value = 42;

    // TODO: Create a const pointer to the non-const variable
    // const int* const_ptr = &???;
    const int *const_ptr = &original_value;

    cout << "Original value: " << *const_ptr << endl;

    // TODO: Use const_cast to remove const and modify
    // This is safe because the original object is not const
    // int* non_const_ptr = const_cast<int*>(???);
    // *??? = 100;
    int *non_const_ptr = const_cast<int *>(const_ptr);
    *non_const_ptr = 100;

    cout << "After const_cast modification: " << *const_ptr << endl;
    cout << "Original variable: " << original_value << endl;
}

// ===== Scenario 2: DANGEROUS const_cast - Original object is const =====

void demonstrate_dangerous_const_cast()
{
    cout << "\n=== DANGEROUS const_cast Examples (AVOID!) ===" << endl;

    // TODO: Create a truly const variable
    // const int truly_const = 50;
    const int truly_const = 50;

    cout << "Truly const value: " << truly_const << endl;

    // TODO: This is DANGEROUS - undefined behavior!
    // int* dangerous_ptr = const_cast<int*>(&???);
    // TODO: Uncomment the next line to see undefined behavior
    // *dangerous_ptr = 200;  // ⚠️ UNDEFINED BEHAVIOR!
    int *dangerous_ptr = const_cast<int *>(&truly_const);
    *dangerous_ptr = 200;

    cout << "dangerous_ptr: " << *dangerous_ptr << endl;
    cout << "After dangerous modification attempt: " << truly_const << endl;
    // The value might not change due to compiler optimizations!
}

// ===== Scenario 3: Interacting with C library functions =====

void demonstrate_c_library_interaction()
{
    cout << "\n=== C Library Function Interaction ===" << endl;

    // C library function that should be const but isn't
    // (strchr is actually overloaded in C++, but let's pretend it's not)
    // signature of strchr in C: char* strchr(char* str, int ch);
    // signature of strchr in C++: const char* strchr(const char* str, int ch);

    // TODO: Create a const string
    // const char* text = "Hello, World!";
    const char *text = "Hello,World!";

    cout << "Original text: " << text << endl;

    // TODO: Some old C functions don't have const-correct signatures
    // We need const_cast to call them, but we promise not to modify

    // Example: finding a character (read-only operation)
    // char* found = const_cast<char*>(strchr(const_cast<char*>(???), 'W'));
    char *found = const_cast<char *>(strchr(const_cast<char *>(text), 'W'));
    if (found)
    {
        cout << "Found 'W' at position: " << (found - text) << endl;
        cout << "Character found: " << *found << endl;
    }
}

// ===== Scenario 4: Code reuse between const and non-const functions =====

class DataProcessor
{
private:
    string data;

public:
    DataProcessor(const string &d) : data(d) {}

    // TODO: Non-const version that does the actual work
    // string& get_data_impl() {
    //     // Imagine some complex processing here
    //     return ???;
    // }
    string &get_data_impl()
    {
        cout << "call non-const impl" << endl;
        return data;
    }
    // TODO: Const version that reuses the non-const version
    // const string& get_data_impl() const {
    //     // Remove const, call non-const version, add const back
    //     return const_cast<DataProcessor*>(this)->get_data_impl();
    // }
    const string &get_data_impl() const
    {
        cout << "call const impl" << endl;
        return data;
    }

    // Public interface
    string &get_data() { return get_data_impl(); }
    const string &get_data() const { return get_data_impl(); }

    void set_data(const string &new_data) { data = new_data; }
};

// ===== Scenario 5: const_cast limitations =====

void demonstrate_const_cast_limitations()
{
    cout << "\n=== const_cast Limitations ===" << endl;

    int value = 100;

    // TODO: const_cast can only change const-ness, not types
    // const int* int_ptr = &value;
    const int *int_ptr = &value;

    // TODO: This works - removing const
    // int* non_const_ptr = const_cast<int*>(???);
    int *non_const_ptr = const_cast<int *>(int_ptr);

    // TODO: Try invalid const_cast (should cause compile error)
    // Uncomment to see the error:
    // double *double_ptr = const_cast<double *>(int_ptr); // Error: a const_cast can only adjust type qualifiers; it cannot change the underlying type

    // TODO: const_cast cannot cast away volatile
    // volatile int vol_value = 200;
    // const volatile int* cv_ptr = &vol_value;
    volatile int vol_value = 200;
    const volatile int *cv_ptr = &vol_value;

    // TODO: This won't compile:
    // int *plain_ptr = const_cast<int *>(cv_ptr); // Error! volatile remains

    cout << "const_cast can only modify const/volatile qualifiers" << endl;
}

// ===== Helper function to show compiler behavior =====

void compiler_optimization_demo()
{
    cout << "\n=== Compiler Optimization Issues ===" << endl;

    // TODO: Show how compiler optimizations can cause issues
    const int optimized_const = 42;

    cout << "Const value (compiler may optimize): " << optimized_const << endl;

    // TODO: Compiler might replace all uses of optimized_const with 42
    // int* hack_ptr = const_cast<int*>(&optimized_const);
    // *hack_ptr = 999;
    int *hack_ptr = const_cast<int *>(&optimized_const);
    *hack_ptr = 999;

    cout << "After const_cast hack: " << optimized_const << endl;
    // This might still print 42 due to compiler optimizations!

    cout << "Value through hacked pointer: " << *hack_ptr << endl;
    // This might print 999, showing the memory was actually changed
}

int main()
{
    cout << "⚠️  const_cast Demonstration - Use with EXTREME CAUTION! ⚠️" << endl;
    cout << "================================================================" << endl;

    // Step 1: Safe usage
    demonstrate_safe_const_cast();

    // Step 2: Dangerous usage (educational purposes only!)
    demonstrate_dangerous_const_cast();

    // Step 3: C library interaction
    demonstrate_c_library_interaction();

    // Step 4: Code reuse pattern
    cout << "\n=== Code Reuse with const_cast ===" << endl;
    DataProcessor processor("Important Data");
    const DataProcessor &const_ref = processor;

    // Both should work and call appropriate versions
    cout << "Non-const access: " << processor.get_data() << endl;
    cout << "Const access: " << const_ref.get_data() << endl;

    // Step 5: Limitations
    demonstrate_const_cast_limitations();

    // Step 6: Compiler behavior
    compiler_optimization_demo();

    // Summary
    cout << "\n=== IMPORTANT RULES FOR const_cast ===" << endl;
    cout << "DO: Remove const when original object is non-const" << endl;
    cout << "DO: Use for C library compatibility (carefully)" << endl;
    cout << "DO: Use for const/non-const code reuse (advanced)" << endl;
    cout << "DON'T: Modify truly const objects (undefined behavior)" << endl;
    cout << "DON'T: Use to 'fix' design problems" << endl;
    cout << "DON'T: Assume it can change types" << endl;
    cout << "REMEMBER: const_cast is often a code smell!" << endl;

    return 0;
}

/*
 * CRITICAL SAFETY RULES:
 *
 * 1. ONLY use const_cast when you're 100% sure the original object is not const
 * 2. NEVER modify data through const_cast if the original was const
 * 3. Be aware of compiler optimizations that assume const data won't change
 * 4. Consider if const_cast indicates a design problem in your code
 * 5. Document WHY you're using const_cast - it should be exceptional
 *
 * ALTERNATIVE SOLUTIONS (prefer these):
 * - Fix the API to be const-correct
 * - Use proper function overloading
 * - Redesign to avoid const violations
 * - Use mutable for logically const but physically mutable data
 *
 * INTERVIEW TAKEAWAY:
 * const_cast exists for rare edge cases, not regular programming.
 * If you find yourself using it often, reconsider your design!
 */