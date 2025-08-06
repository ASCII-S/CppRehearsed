#include <iostream>
#include <cstring>
#include <stdint.h>
#include <iomanip>
using namespace std;

// TODO 1: Define a struct named Point
// Requirements:
// - Add members x and y of type int
// - Add a constructor that takes x and y parameters
struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y)
    {
    }
};

// TODO 2: Define a struct named Data
// Requirements:
// - Add member value of type int
// - Add a constructor that takes value parameter
struct Data
{
    int value;
    Data(int v) : value(v) {}
};

// TODO 3: Create a function named simpleHash
// Requirements:
// - Take a void* parameter
// - Use reinterpret_cast to convert void* to uintptr_t
// - Return the hash value (can be the address value itself)
// - Note: This is a common use case for reinterpret_cast
uintptr_t simpleHash(void *vptr)
{
    uintptr_t up = reinterpret_cast<uintptr_t>(vptr); // uintptr_p专门用于存储地址值
    return up;
}

int main()
{
    cout << "=== reinterpret_cast Demo ===" << endl;
    cout << "WARNING: reinterpret_cast is dangerous and should be used with extreme caution!" << endl;

    // TODO 4: Pointer to integer conversion
    // Requirements:
    // - Create an int variable with value 42
    // - Get its address and store in int* pointer
    // - Use reinterpret_cast to convert the pointer to uintptr_t
    // - Print the address value

    cout << "\n=== Pointer to Integer Conversion ===" << endl;
    int i4 = 42;
    int *i4_ptr = &i4;
    uintptr_t i4_uptr = reinterpret_cast<uintptr_t>(i4_ptr);
    std::cout << "address of i4 is: " << &i4 << std::endl;
    std::cout << "i4_ptr is: " << i4_ptr << std::endl;
    std::cout << "i4_uptr is: " << i4_uptr << std::endl;
    std::cout << "value of i4 is: " << i4 << std::endl;
    std::cout << "deference i4_ptr is: " << *i4_ptr << std::endl;
    std::cout << "deference i4_uptr is: " << *reinterpret_cast<int *>(i4_uptr) << std::endl;
    std::cout << "sizeof(int) is: " << sizeof(int) << std::endl;
    std::cout << "sizeof(uintptr_t) is: " << sizeof(uintptr_t) << std::endl;

    // TODO 5: Integer to pointer conversion
    // Requirements:
    // - Take the integer value from TODO 4
    // - Use reinterpret_cast to convert it back to int*
    // - Dereference the pointer to get the original value
    // - Print the value to verify it works

    cout << "\n=== Integer to Pointer Conversion ===" << endl;
    int *i4_ptr_back = reinterpret_cast<int *>(i4_uptr);
    std::cout << "i4_ptr_back is: " << i4_ptr_back << std::endl;
    std::cout << "value of i4_ptr_back is: " << *i4_ptr_back << std::endl;

    // TODO 6: Unrelated pointer type conversion
    // Requirements:
    // - Create a Point object with coordinates (10, 20)
    // - Use reinterpret_cast to convert Point* to int*
    // - Print the first int value (should be x coordinate)
    // - Print the second int value (should be y coordinate)
    // - Add a comment explaining why this is dangerous

    cout << "\n=== Unrelated Pointer Type Conversion ===" << endl;
    Point *p = new Point(10, 20);
    int *i6_ptr = reinterpret_cast<int *>(p);
    std::cout << "i6_ptr is: " << i6_ptr << std::endl;
    std::cout << "value of i6_ptr is: " << *i6_ptr << std::endl;
    std::cout << "value of i6_ptr+1 is: " << *(i6_ptr + 1) << std::endl;
    // 这里打印的值是10和20，但是实际上是p的地址值，因为Point的成员变量是int，所以可以被转换为int*

    // TODO 7: Array reinterpretation
    // Requirements:
    // - Create an int array with values {0x12345678, 0x9ABCDEF0}
    // - Use reinterpret_cast to convert int* to char*
    // - Print the individual bytes (use a loop for 8 bytes)
    // - Note: This demonstrates how reinterpret_cast reinterprets memory

    cout << "\n=== Array Reinterpretation ===" << endl;
    int arr[2] = {0x12345678, static_cast<int>(0x9ABCDEF0)};
    std::cout << "arr is: " << arr << std::endl;
    std::cout << "arr[0] is: " << std::hex << arr[0] << std::endl;
    std::cout << "arr[1] is: " << std::hex << arr[1] << std::endl;
    char *c_ptr = reinterpret_cast<char *>(arr);
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "0x" << std::hex << (static_cast<unsigned char>(c_ptr[i]) & 0xff) << std::dec << " ";
    }

    // TODO 8: Function pointer conversion (dangerous)
    // Requirements:
    // - Create a function pointer to simpleHash
    // - Use reinterpret_cast to convert it to a different function pointer type
    // - Add a comment explaining why this is extremely dangerous
    // - Note: Do not actually call the reinterpreted function pointer

    cout << "\n=== Function Pointer Conversion (dangerous) ===" << endl;
    uintptr_t (*fptr)(void *);
    fptr = simpleHash;
    int (*fptr_2)(void *) = reinterpret_cast<int (*)(void *)>(fptr);
    uintptr_t (*fptr_3)(int *) = reinterpret_cast<uintptr_t (*)(int *)>(fptr);
    std::cout << "address of fptr is: " << reinterpret_cast<void *>(fptr) << std::endl;
    std::cout << "address of fptr_2 is: " << reinterpret_cast<void *>(fptr_2) << std::endl;
    std::cout << "address of fptr_3 is: " << reinterpret_cast<void *>(fptr_3) << std::endl;
    std::cout << "value of fptr(arr) is: " << fptr(arr) << std::endl;
    std::cout << "value of fptr_2(arr) is: " << fptr_2(arr) << std::endl;
    std::cout << "value of fptr_3(arr) is: " << fptr_3(arr) << std::endl;
    std::cout
        << "我将fptr的返回值重解释到宽泛的类型并打印，得到的结果在数值上一致，但是如果有narrowing，则结果是未定义的。"
        << std::endl;

    // TODO 9: Use the simpleHash function
    // Requirements:
    // - Create a Point object
    // - Call simpleHash with the Point object's address
    // - Print the hash value

    cout
        << "\n=== Using simpleHash Function ===" << endl;
    Point p9(10, 20);
    std::cout << "address of p9 is: " << reinterpret_cast<void *>(&p9) << std::endl;
    std::cout << "hash value of simpleHash(p9) is: " << simpleHash(&p9) << std::endl;
    std::cout << "hash value of simpleHash(p9) as hex: 0x" << std::hex << simpleHash(&p9) << std::endl;
    std::cout << std::dec;
    // TODO 10: Demonstrate why reinterpret_cast is non-portable
    // Requirements:
    // - Create a double variable with value 3.14
    // - Use reinterpret_cast to view it as a long long
    // - Print the bit pattern
    // - Add a comment explaining why this is platform-dependent

    cout << "\n=== Non-portable Behavior ===" << endl;
    double d10 = 3.14;
    long long l10 = reinterpret_cast<long long &>(d10);
    std::cout << "address of d10 is: " << reinterpret_cast<void *>(&d10) << std::endl;
    std::cout << "value of l10 is: " << l10 << std::endl;
    std::cout << "value of l10 as hex: 0x" << std::hex << l10 << std::endl;

    return 0;
}

// Note: This exercise should take approximately 10 minutes to complete
// Focus on understanding the dangers of reinterpret_cast and its limited valid use cases
// Remember: reinterpret_cast should only be used in low-level system programming!