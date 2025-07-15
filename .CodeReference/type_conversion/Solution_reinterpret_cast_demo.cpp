#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Solution for TODO 1: Define a struct named Point
struct Point
{
    int x;
    int y;

    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
};

// Solution for TODO 2: Define a struct named Data
struct Data
{
    int value;

    Data(int val) : value(val) {}
};

// Solution for TODO 3: Create a function named simpleHash
uintptr_t simpleHash(void *ptr)
{
    // Convert pointer to integer for hashing
    // This is a common use case for reinterpret_cast
    return reinterpret_cast<uintptr_t>(ptr);
}

int main()
{
    cout << "=== reinterpret_cast Demo ===" << endl;
    cout << "WARNING: reinterpret_cast is dangerous and should be used with extreme caution!" << endl;

    // Solution for TODO 4: Pointer to integer conversion
    cout << "\n=== Pointer to Integer Conversion ===" << endl;

    int value = 42;
    int *intPtr = &value;

    cout << "Original value: " << *intPtr << endl;
    cout << "Pointer address: " << intPtr << endl;

    uintptr_t addressValue = reinterpret_cast<uintptr_t>(intPtr);
    cout << "Address as integer: " << addressValue << endl;
    cout << "Address as hex: 0x" << hex << addressValue << dec << endl;

    // Solution for TODO 5: Integer to pointer conversion
    cout << "\n=== Integer to Pointer Conversion ===" << endl;

    int *recoveredPtr = reinterpret_cast<int *>(addressValue);
    cout << "Recovered pointer: " << recoveredPtr << endl;
    cout << "Recovered value: " << *recoveredPtr << endl;
    cout << "Verification: " << (intPtr == recoveredPtr ? "SUCCESS" : "FAILED") << endl;

    // Solution for TODO 6: Unrelated pointer type conversion
    cout << "\n=== Unrelated Pointer Type Conversion ===" << endl;

    Point point(10, 20);
    Point *pointPtr = &point;

    cout << "Original Point: (" << point.x << ", " << point.y << ")" << endl;

    // DANGEROUS: Convert Point* to int* to access raw memory
    int *intArrayPtr = reinterpret_cast<int *>(pointPtr);

    cout << "First int (x): " << intArrayPtr[0] << endl;
    cout << "Second int (y): " << intArrayPtr[1] << endl;

    // This is dangerous because:
    // 1. It assumes the memory layout of Point
    // 2. It's not portable across different systems
    // 3. It bypasses type safety

    // Solution for TODO 7: Array reinterpretation
    cout << "\n=== Array Reinterpretation ===" << endl;

    int intArray[2] = {0x12345678, static_cast<int>(0x9ABCDEF0)};
    cout << "Integer array: 0x" << hex << intArray[0] << ", 0x" << intArray[1] << dec << endl;

    char *charPtr = reinterpret_cast<char *>(intArray);

    cout << "As bytes: ";
    for (int i = 0; i < 8; ++i)
    {
        cout << "0x" << hex << setw(2) << setfill('0') << (static_cast<unsigned char>(charPtr[i]) & 0xFF) << " ";
    }
    cout << dec << endl;

    // This demonstrates how reinterpret_cast reinterprets the bit pattern

    // Solution for TODO 8: Function pointer conversion (dangerous)
    cout << "\n=== Function Pointer Conversion (dangerous) ===" << endl;

    // Function pointer to simpleHash
    uintptr_t (*hashFunc)(void *) = simpleHash;

    cout << "Original function pointer: " << reinterpret_cast<void *>(hashFunc) << endl;

    // EXTREMELY DANGEROUS: Convert to a different function pointer type
    void (*voidFunc)() = reinterpret_cast<void (*)()>(hashFunc);

    cout << "Reinterpreted function pointer: " << reinterpret_cast<void *>(voidFunc) << endl;

    // DO NOT call voidFunc() - this would be undefined behavior!
    // The function signature is completely different

    cout << "Note: DO NOT call the reinterpreted function pointer!" << endl;

    // Solution for TODO 9: Use the simpleHash function
    cout << "\n=== Using simpleHash Function ===" << endl;

    Point testPoint(100, 200);
    uintptr_t hash = simpleHash(&testPoint);

    cout << "Point address: " << &testPoint << endl;
    cout << "Hash value: " << hash << endl;
    cout << "Hash as hex: 0x" << hex << hash << dec << endl;

    // Solution for TODO 10: Demonstrate non-portable behavior
    cout << "\n=== Non-portable Behavior ===" << endl;

    double doubleValue = 3.14;
    cout << "Double value: " << doubleValue << endl;

    // View the bit pattern of double as long long
    long long bitPattern = reinterpret_cast<long long &>(doubleValue);

    cout << "Bit pattern as long long: " << bitPattern << endl;
    cout << "Bit pattern as hex: 0x" << hex << bitPattern << dec << endl;

    // This is platform-dependent because:
    // 1. sizeof(double) and sizeof(long long) may differ on different systems
    // 2. Endianness affects the bit representation
    // 3. Floating-point representation may vary

    cout << "Note: This bit pattern may differ on different platforms!" << endl;

    return 0;
}

// Note: This solution demonstrates dangerous uses of reinterpret_cast
// Key learning points:
// 1. reinterpret_cast performs no type checking
// 2. It directly reinterprets the bit pattern
// 3. Results are platform-dependent and non-portable
// 4. Should only be used in low-level system programming
// 5. Always ensure the reinterpretation is safe and meaningful
// 6. Common valid use: converting pointers to integers for hashing