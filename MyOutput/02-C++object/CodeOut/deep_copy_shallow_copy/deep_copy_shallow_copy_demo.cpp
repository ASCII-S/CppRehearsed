// deep_copy_shallow_copy_demo.cpp
// Demo: Deep Copy vs Shallow Copy in C++
// Complete the following TODOs step by step.

#include <iostream>
#include <cstring>
using namespace std;

// TODO 1: Define a simple String class with a char* member
class String
{
private:
    char *data;

public:
    String(const char *str = "")
    {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }
    ~String()
    {
        delete[] data;
    }
    void setData(const char* str = "")
    {
        strcpy(data, str);
    }
    void print() const
    {
        cout << data << endl;
    }
    // TODO 2: Use default copy constructor and assignment operator, observe shallow copy issues
    // String(const String& other) = default;
    // String& operator=(const String& other) = default;
    // String(const String& other) = default;      // shallow copy in default copy constructor
    // String& operator=(const String &other) = default;

    // TODO 3: Manually implement deep copy for copy constructor and assignment operator
    // String(const String& other) { ... }
    // String& operator=(const String& other) { ... }
    String(const String& other) 
    {
        data = new char[strlen(other.data+1)];
        strcpy(this->data, other.data);
    }
    String& operator=(const String &other)
    {
        if(this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data+1)];
            strcpy(data, other.data);
        }
        return *this;
    }
};

int main()
{
    cout << "=== Deep Copy vs Shallow Copy Demo ===" << endl;
    // TODO 2: Create two String objects, copy one to another, and observe what happens when both are destroyed
    String s1("hello");
    String s2 = s1; // Shallow copy by default
    s1.print();
    s1.setData("666");
    s1.print();
    s2.print();
    // TODO: What happens if you modify s2.data? What if both go out of scope?

    // TODO 3: Implement deep copy, repeat the above and observe the difference

    // TODO 4: Show the difference in main between shallow and deep copy

    // TODO 5: Summarize the difference and caveats in comments
    return 0;
}