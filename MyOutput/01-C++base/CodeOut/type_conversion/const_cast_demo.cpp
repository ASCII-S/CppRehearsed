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
class DataContainer
{
    int data;

public:
    DataContainer(int d) : data(d)
    {
    }

    int getData() const
    {
        return data;
    }

    void setData(int d)
    {
        data = d;
    }

    void doubleData()
    {
        data *= 2;
    }
};

// TODO 2: Create a function named printData
// Requirements:
// - Take a const DataContainer& parameter
// - Print the data value using getData()
void printData(const DataContainer &dc)
{
    std::cout << "data is: " << dc.getData() << std::endl;
}

// TODO 3: Create a function named modifyData
// Requirements:
// - Take a const DataContainer& parameter
// - Use const_cast to remove const and call doubleData()
// - Print a message indicating the data was modified
void modifyData(const DataContainer &dc)
{
    DataContainer &dc_non_const = const_cast<DataContainer &>(dc);
    dc_non_const.doubleData();
    std::cout << "after modify const Data is: " << dc.getData() << std::endl;
    std::cout << "after modify non const Data is: " << dc_non_const.getData() << std::endl;
}

// TODO 4: Create a function named processString
// Requirements:
// - Take a const char* parameter
// - Use const_cast to remove const
// - Modify the first character to uppercase (if it's a letter)
// - Print the modified string
void processString(const char *cc)
{
    char *c = const_cast<char *>(cc);
    c[0] = c[0] - 'a' + 'A';
    std::cout << "after upper first character: " << *cc << std::endl;
}

int main()
{
    cout << "=== const_cast Demo ===" << endl;

    // TODO 5: Safe const_cast example
    // Requirements:
    // - Create a non-const DataContainer object with value 10
    // - Create a const reference to it
    // - Use const_cast to remove const and call setData(20)
    // - Print the value to show it was modified

    cout << "\n=== Safe const_cast (original object is non-const) ===" << endl;
    DataContainer dc1(10);
    const DataContainer &dc1_const = dc1;
    const_cast<DataContainer &>(dc1_const).setData(20);
    std::cout << "data of dc1 after setData(20): " << dc1.getData() << std::endl;

    // TODO 6: const_cast with const object (undefined behavior)
    // Requirements:
    // - Create a const DataContainer object with value 30
    // - Use const_cast to remove const and try to modify it
    // - Add a comment explaining why this is undefined behavior
    // - Note: Do not actually execute this part, just write the code as comment

    cout << "\n=== Dangerous const_cast (original object is const) ===" << endl;
    // const DataContainer dc2(30);
    // DataContainer &dc2_non_const = const_cast<DataContainer &>(dc2);
    // const_cast<DataContainer &>(dc2_non_const).doubleData();
    // std::cout << "data of dc2 after doubleData(): " << dc2.getData() << std::endl;

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
    // const char *cptr = "Hello const_cast!";
    // char *cptr_nonconst = const_cast<char *>(cptr);
    // cptr_nonconst[4] = '6';
    // std::cout << "cptr is: " << cptr << std::endl;
    cout << "这里发生段错误是因为试图修改字符串字面量。\n"
         << " \"Hello const_cast!\" 是一个字符串字面量，它存储在程序的只读内存区域（通常是代码段）。即使使用 const_cast 移除了 const 属性，底层的内存区域仍然是只读的。\n"
         << " 当执行 cptr_nonconst[4] = '6' 时，程序试图写入只读内存，操作系统检测到这个非法操作并终止程序，导致段错误。"
         << endl;

    // TODO 9: Practical use case - calling non-const function from const context
    // Requirements:
    // - Create a non-const DataContainer object
    // - Call the modifyData function with it
    // - Observe how const_cast enables calling non-const functions

    cout
        << "\n=== Practical Use Case ===" << endl;
    DataContainer dc9(9);
    const DataContainer &dc9_const = dc9;
    modifyData(dc9_const);

    // TODO 10: const_cast with char array (safe)
    // Requirements:
    // - Create a non-const char array with "hello"
    // - Pass it to processString function
    // - Print the result

    cout << "\n=== const_cast with char array ===" << endl;
    char cstr[] = "hello";
    processString(cstr);
    cout << "cstr is: " << cstr << endl;

    return 0;
}

// Note: This exercise should take approximately 8-10 minutes to complete
// Focus on understanding when const_cast is safe and when it leads to undefined behavior