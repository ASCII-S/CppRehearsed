/*
 * const_pointer_demo.cpp
 * Demonstration of different const pointer declarations
 *
 * This file demonstrates the differences between:
 * - const int* (pointer to const)
 * - int* const (const pointer)
 * - const int* const (const pointer to const)
 *
 * TODO: Complete the code by following the instructions
 */

#include <iostream>
using namespace std;

int main()
{
    // Step 1: Declare some variables for testing
    // TODO: Declare two integer variables: a = 10, b = 20
    int a = 10;
    int b = 20;
    // Step 2: Pointer to const (const int*)
    // The value pointed to cannot be changed, but pointer can be reassigned
    cout << "=== Pointer to const (const int*) ===" << endl;

    // TODO: Declare a pointer to const int, pointing to variable 'a'
    // const int* ptr1 = ?;
    const int *ptr1 = &a;

    cout << "ptr1 points to: " << *ptr1 << endl;

    // TODO: Try to change the value through ptr1 (this should cause compile error)
    // Uncomment the next line to see the error:
    // *ptr1 = 30; // Error: cannot modify const

    // TODO: Change ptr1 to point to variable 'b' (this should work)
    ptr1 = &b;
    cout << "ptr1 now points to: " << *ptr1 << endl;

    // Step 3: Const pointer (int* const)
    // The pointer cannot be reassigned, but the value can be changed
    cout << "\n=== Const pointer (int* const) ===" << endl;

    // TODO: Declare a const pointer to int, pointing to variable 'a'
    // int* const ptr2 = ?;
    int *const ptr2 = &a;
    cout << "ptr2 points to: " << *ptr2 << endl;

    // TODO: Change the value through ptr2 (this should work)
    *ptr2 = 6;
    cout << "After modification: " << *ptr2 << endl;

    // TODO: Try to change ptr2 to point to 'b' (this should cause compile error)
    // Uncomment the next line to see the error:
    // ptr2 = &b;  // Error: cannot modify const pointer

    // Step 4: Const pointer to const (const int* const)
    // Neither the pointer nor the value can be changed
    cout << "\n=== Const pointer to const (const int* const) ===" << endl;

    // TODO: Declare a const pointer to const int, pointing to variable 'a'
    // const int* const ptr3 = ?;
    const int *const ptr3 = &a;
    cout << "ptr3 points to: " << *ptr3 << endl;

    // TODO: Try both operations below (both should cause compile errors)
    // Uncomment to see the errors:
    // *ptr3 = 50;   // Error: cannot modify const value
    // ptr3 = &b;    // Error: cannot modify const pointer

    // Step 5: Summary
    cout << "\n=== Summary ===" << endl;
    cout << "const int* ptr     - Pointer to const: value cannot change, pointer can" << endl;
    cout << "int* const ptr     - Const pointer: pointer cannot change, value can" << endl;
    cout << "const int* const   - Both const: neither can change" << endl;

    // TODO: Test your understanding by declaring each type and experimenting
    // Remember: compile errors are your friend - they teach you the rules!

    return 0;
}

/*
 * EXERCISE:
 * 1. Complete all the TODO items above
 * 2. Compile and run the program
 * 3. Uncomment the error lines one by one to see compiler messages
 * 4. Create your own examples with different data types (double, char, etc.)
 *
 * KEY TAKEAWAY:
 * Read const declarations from right to left, or use this rule:
 * "const modifies what comes immediately to its left, or to its right if nothing is to the left"
 */