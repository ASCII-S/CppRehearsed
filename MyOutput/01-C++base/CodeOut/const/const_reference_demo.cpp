/*
 * const_reference_demo.cpp
 * Demonstration of const references in C++
 *
 * This file demonstrates:
 * - const reference to variables
 * - binding to temporary objects
 * - const reference vs regular reference
 *
 * TODO: Complete the code by following the instructions
 */

#include <iostream>
#include <string>
using namespace std;

// Function that takes const reference (we'll use this later)
void print_string(const string &str)
{
    cout << "String: " << str << endl;
    // TODO: Try to modify str here - what happens?
    // str += " modified";  // Uncomment to see error
}

// Function that takes non-const rference
void print_string_nonconst(string &str)
{
    str += " modified";
    cout << "string: " << str << endl;
}

int main()
{
    // Step 1: Basic const reference
    cout << "=== Basic const reference ===" << endl;

    // TODO: Declare an integer variable: value = 42
    int value = 42;
    // TODO: Create a const reference to the variable
    // const int& ref = ?;
    const int &ref = value;
    cout << "Original value: " << value << endl;
    cout << "Reference value: " << ref << endl;

    // TODO: Try to modify through the reference (should cause error)
    // Uncomment to see the error:
    // ref = 100;  // Error: cannot modify const reference (expression must be a modifiable lvalue)

    // TODO: Modify the original variable - what happens to the reference?
    value = 100;
    cout << "After modification - value: " << value << ", ref: " << ref << endl;

    // Step 2: const reference can bind to temporary objects
    cout << "\n=== Binding to temporary objects ===" << endl;

    // TODO: Create a const reference that binds to a temporary int
    // const int& temp_ref = ?;  // Use a Literal like 100
    const int &temp_ref = 100;
    cout << "Temporary reference: " << temp_ref << endl;

    // TODO: Try creating a non-const reference to a temporary (should fail)
    // Uncomment to see the error:
    // int& bad_ref = 200;  // Error: cannot bind non-const reference to temporary

    // Step 3: const reference vs regular reference with const variables
    cout << "\n=== const variables and references ===" << endl;

    // TODO: Declare a const variable: const_val = 99
    const int const_val = 99;
    // TODO: Try to create a regular reference to the const variable (should fail)
    // Uncomment to see the error:
    // int& bad_ref2 = const_val;  // Error: cannot bind non-const ref to const variable

    // TODO: Create a const reference to the const variable (should work)
    // const int& good_ref = ?;
    const int &good_ref = const_val;
    cout << "const variable through const reference: " << good_ref << endl;

    // Step 4: Function parameters with const references
    cout << "\n=== Function parameters with const references===" << endl;

    string my_string = "Hello";
    const string my_const_string = "Hello Const!";
    print_string(my_string);
    print_string(my_const_string);

    // TODO: Call print_string with a temporary string literal
    print_string("Hello World!");

    cout << "\n=== Function parameters with non-const references===" << endl;
    // TODO: Create a function that takes a non-const reference
    // What happens when you try to pass a const variable or temporary?
    print_string_nonconst(my_string);

    // print_string_nonconst(my_const_string); // Error: cannot pass const string to non-const string
    // Step 5: Benefits of const references
    cout << "\n=== Benefits of const references ===" << endl;
    cout << "1. No copying overhead for large objects" << endl;
    cout << "2. Can bind to temporaries" << endl;
    cout << "3. Prevents accidental modification" << endl;
    cout << "4. Can accept both const and non-const arguments" << endl;

    return 0;
}

/*
 * TODO: Create additional functions to test:
 */

// TODO: Function that takes non-const reference
// void modify_value(int& val) {
//     val *= 2;
// }

// TODO: Function that demonstrates why const ref is better than value for large objects
// void process_large_object(const vector<int>& data) {
//     // Process without copying
// }

/*
 * EXERCISE:
 * 1. Complete all the TODO items above
 * 2. Compile and run the program
 * 3. Try the error scenarios to understand the rules
 * 4. Create examples with different types (string, vector, custom classes)
 *
 * KEY TAKEAWAY:
 * const references are essential for:
 * - Efficient parameter passing
 * - Binding to temporaries
 * - Type safety and const-correctness
 */