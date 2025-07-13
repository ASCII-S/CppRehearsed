#include <iostream>
#include <cstring>
using namespace std;

// TODO 1: Define a struct named Point
// Requirements:
// - Add members x and y of type int
// - Add a constructor that takes x and y parameters

// TODO 2: Define a struct named Data
// Requirements:
// - Add member value of type int
// - Add a constructor that takes value parameter

// TODO 3: Create a function named simpleHash
// Requirements:
// - Take a void* parameter
// - Use reinterpret_cast to convert void* to uintptr_t
// - Return the hash value (can be the address value itself)
// - Note: This is a common use case for reinterpret_cast

int main() {
    cout << "=== reinterpret_cast Demo ===" << endl;
    cout << "WARNING: reinterpret_cast is dangerous and should be used with extreme caution!" << endl;
    
    // TODO 4: Pointer to integer conversion
    // Requirements:
    // - Create an int variable with value 42
    // - Get its address and store in int* pointer
    // - Use reinterpret_cast to convert the pointer to uintptr_t
    // - Print the address value
    
    cout << "\n=== Pointer to Integer Conversion ===" << endl;
    
    // TODO 5: Integer to pointer conversion
    // Requirements:
    // - Take the integer value from TODO 4
    // - Use reinterpret_cast to convert it back to int*
    // - Dereference the pointer to get the original value
    // - Print the value to verify it works
    
    cout << "\n=== Integer to Pointer Conversion ===" << endl;
    
    // TODO 6: Unrelated pointer type conversion
    // Requirements:
    // - Create a Point object with coordinates (10, 20)
    // - Use reinterpret_cast to convert Point* to int*
    // - Print the first int value (should be x coordinate)
    // - Print the second int value (should be y coordinate)
    // - Add a comment explaining why this is dangerous
    
    cout << "\n=== Unrelated Pointer Type Conversion ===" << endl;
    
    // TODO 7: Array reinterpretation
    // Requirements:
    // - Create an int array with values {0x12345678, 0x9ABCDEF0}
    // - Use reinterpret_cast to convert int* to char*
    // - Print the individual bytes (use a loop for 8 bytes)
    // - Note: This demonstrates how reinterpret_cast reinterprets memory
    
    cout << "\n=== Array Reinterpretation ===" << endl;
    
    // TODO 8: Function pointer conversion (dangerous)
    // Requirements:
    // - Create a function pointer to simpleHash
    // - Use reinterpret_cast to convert it to a different function pointer type
    // - Add a comment explaining why this is extremely dangerous
    // - Note: Do not actually call the reinterpreted function pointer
    
    cout << "\n=== Function Pointer Conversion (dangerous) ===" << endl;
    
    // TODO 9: Use the simpleHash function
    // Requirements:
    // - Create a Point object
    // - Call simpleHash with the Point object's address
    // - Print the hash value
    
    cout << "\n=== Using simpleHash Function ===" << endl;
    
    // TODO 10: Demonstrate why reinterpret_cast is non-portable
    // Requirements:
    // - Create a double variable with value 3.14
    // - Use reinterpret_cast to view it as a long long
    // - Print the bit pattern
    // - Add a comment explaining why this is platform-dependent
    
    cout << "\n=== Non-portable Behavior ===" << endl;
    
    return 0;
}

// Note: This exercise should take approximately 10 minutes to complete
// Focus on understanding the dangers of reinterpret_cast and its limited valid use cases
// Remember: reinterpret_cast should only be used in low-level system programming! 