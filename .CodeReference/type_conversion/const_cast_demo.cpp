#include <iostream>
#include <cstring>
using namespace std;

// TODO 1: Define a class named DataContainer
// Requirements:
// - Add a private member data of type int
// - Add a constructor that takes an int parameter
// - Add a const member function named getData() that returns data
// - Add a non-const member function named setData(int) that sets data
// - Add a non-const member function named doubleData() that doubles the data value

// TODO 2: Create a function named printData
// Requirements:
// - Take a const DataContainer& parameter
// - Print the data value using getData()

// TODO 3: Create a function named modifyData
// Requirements:
// - Take a const DataContainer& parameter
// - Use const_cast to remove const and call doubleData()
// - Print a message indicating the data was modified

// TODO 4: Create a function named processString
// Requirements:
// - Take a const char* parameter
// - Use const_cast to remove const
// - Modify the first character to uppercase (if it's a letter)
// - Print the modified string

int main() {
    cout << "=== const_cast Demo ===" << endl;
    
    // TODO 5: Safe const_cast example
    // Requirements:
    // - Create a non-const DataContainer object with value 10
    // - Create a const reference to it
    // - Use const_cast to remove const and call setData(20)
    // - Print the value to show it was modified
    
    cout << "\n=== Safe const_cast (original object is non-const) ===" << endl;
    
    // TODO 6: const_cast with const object (undefined behavior)
    // Requirements:
    // - Create a const DataContainer object with value 30
    // - Use const_cast to remove const and try to modify it
    // - Add a comment explaining why this is undefined behavior
    // - Note: Do not actually execute this part, just write the code as comment
    
    cout << "\n=== Dangerous const_cast (original object is const) ===" << endl;
    
    // TODO 7: const_cast with pointers
    // Requirements:
    // - Create a non-const int variable with value 42
    // - Create a const int* pointer to it
    // - Use const_cast to remove const and modify the value
    // - Print the modified value
    
    cout << "\n=== const_cast with Pointers ===" << endl;
    
    // TODO 8: const_cast with string literals (dangerous)
    // Requirements:
    // - Create a const char* pointing to a string literal
    // - Use const_cast to remove const
    // - Add a comment explaining why modifying string literals is undefined behavior
    // - Note: Write this as a comment, don't actually execute
    
    cout << "\n=== const_cast with String Literals (dangerous) ===" << endl;
    
    // TODO 9: Practical use case - calling non-const function from const context
    // Requirements:
    // - Create a non-const DataContainer object
    // - Call the modifyData function with it
    // - Observe how const_cast enables calling non-const functions
    
    cout << "\n=== Practical Use Case ===" << endl;
    
    // TODO 10: const_cast with char array (safe)
    // Requirements:
    // - Create a non-const char array with "hello"
    // - Pass it to processString function
    // - Print the result
    
    cout << "\n=== const_cast with char array ===" << endl;
    
    return 0;
}

// Note: This exercise should take approximately 8-10 minutes to complete
// Focus on understanding when const_cast is safe and when it leads to undefined behavior 