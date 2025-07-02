/*
 * Static Function Demo
 *
 * This file demonstrates the use of static keyword with functions.
 * Complete the TODOs to understand function linkage and visibility.
 *
 * Estimated time: 5-7 minutes
 */

#include <iostream>
using namespace std;

// TODO 1: Declare a regular (non-static) function called 'public_function'
// that takes no parameters and prints "This is a public function"
// Write your declaration here:
void public_function();

// TODO 2: Declare a static function called 'private_helper'
// that takes two integers and returns their sum
// Write your declaration here:
static int private_helper(int a, int b);

// TODO 3: Implement the public_function that:
// - Prints "This is a public function"
// - Calls private_helper with values 10 and 20
// - Prints the result returned by private_helper
// Write your code here:
void public_function()
{
    cout << "This is a public function" << endl;
    cout << "call static function private_helper: " << endl;
    int result = private_helper(10, 20);
    cout << "---" << endl;
}

// TODO 4: Implement the private_helper function that:
// - Takes two integer parameters 'a' and 'b'
// - Returns their sum
// - Prints "Helper function called with a=%d, b=%d"
// Write your code here:
static int private_helper(int a, int b)
{
    cout << "Helper function called with a=" << a << ", b=" << b << endl;
    return a + b;
}

// TODO 5: Create another static function called 'internal_utility'
// that takes a string parameter and prints it with a prefix "[INTERNAL]"
// Write your code here:
static void internal_utility(string str)
{
    cout << "[INTERNAL]" << "str is: " << str << endl;
}

// TODO 6: Create a regular function called 'use_utilities' that:
// - Calls internal_utility with the message "Testing internal function"
// - Demonstrates that static functions can be called within the same file
// Write your code here:
void use_utilities()
{
    internal_utility("Testing internal function by use_utilities");
}

// int main()
// {
//     cout << "=== Static Function Demo ===" << endl;

//     cout << "\n1. Calling public function:" << endl;
//     // TODO 7: Call public_function()
//     // Write your code here:
//     public_function();

//     cout << "\n2. Using utility functions:" << endl;
//     // TODO 8: Call use_utilities()
//     // Write your code here:
//     use_utilities();

//     cout << "\n3. Direct access test:" << endl;
//     // TODO 9: Try to call private_helper directly from main
//     // What do you expect to happen?
//     // Write your code here:
//     private_helper(10, 20);

//     // TODO 10: Try to call internal_utility directly from main
//     // Write your code here:
//     internal_utility("Testing internal function directly from main");

//     return 0;
// }

/*
 * Experiment:
 * 1. Try to call private_helper and internal_utility from another .cpp file
 * 2. Compare this with calling public_function from another file
 * 3. Observe the linker behavior
 *
 * Questions to think about:
 * 1. What is the difference between static functions and functions in anonymous namespaces?
 * 2. When would you choose static functions over private member functions?
 * 3. How do static functions help with encapsulation at the file level?
 */