/*
 * External Test File
 *
 * This file demonstrates how static functions and variables
 * behave when accessed from another file.
 *
 * Try to compile this file together with the other demo files
 * to see the linker errors.
 */

#include <iostream>
using namespace std;

// TODO 1: Try to declare external references to static variables from other files
// Uncomment the lines below and see what happens:

extern int static_global; // from global_static_demo.cpp
extern int debug_mode;    // from static_comprehensive_demo.cpp

// TODO 2: Try to declare external references to static functions from other files
// Uncomment the lines below and see what happens:

extern void private_helper(int a, int b); // from static_function_demo.cpp
extern void internal_utility(string msg); // from static_function_demo.cpp

// TODO 3: Try to declare external references to regular (non-static) functions
// These should work fine:

extern void public_function(); // from static_function_demo.cpp
extern void use_utilities();   // from static_function_demo.cpp

void test_external_access()
{
    cout << "=== Testing External Access ===" << endl;

    // TODO 4: Try to access static variables
    // Uncomment and see the compilation errors:

    // cout << "Static global: " << static_global << endl; // Error: external_test.cpp:(.text+0x51): undefined reference to `static_global'
    // cout << "Debug mode: " << debug_mode << endl;

    // TODO 5: Try to call static functions
    // Uncomment and see the compilation errors:

    // private_helper(5, 10); // Error: external_test.cpp:(.text+0x52): undefined reference to `private_helper(int, int)'
    // internal_utility("Testing from external file"); // Error: undefined reference to `internal_utility(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)'

    // TODO 6: Try to call regular functions
    // These should work (if properly declared):

    public_function();
    use_utilities();

    cout << "External access test completed." << endl;
}

int main()
{
    test_external_access();
    return 0;
}

/*
 * Instructions for testing:
 *
 * 1. Compile individual files:
 *    g++ -c global_static_demo.cpp
 *    g++ -c static_function_demo.cpp
 *    g++ -c external_test.cpp
 *
 * 2. Try to link them together:
 *    g++ global_static_demo.o static_function_demo.o external_test.o -o test
 *
 * 3. Uncomment the extern declarations and function calls one by one
 *    to see different types of linker errors
 *
 * 4. Notice which symbols are found and which are not
 *
 * Expected Results:
 * - Static functions and variables should cause "undefined reference" errors
 * - Regular functions should link successfully
 * - This demonstrates the "internal linkage" property of static symbols
 */