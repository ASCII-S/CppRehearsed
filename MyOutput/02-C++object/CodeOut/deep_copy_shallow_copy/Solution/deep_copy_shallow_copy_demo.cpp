// Solution: deep_copy_shallow_copy_demo.cpp
// Demonstrates the difference between deep copy and shallow copy in C++
#include <iostream>
#include <cstring>
using namespace std;

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
    // Shallow copy (default):
    // String(const String& other) = default;
    // String& operator=(const String& other) = default;

    // Deep copy:
    String(const String &other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    ~String()
    {
        delete[] data;
    }
    void print() const
    {
        cout << data << endl;
    }
    // For demo: expose data pointer (not recommended in real code)
    char *getData() { return data; }
};

int main()
{
    cout << "=== Deep Copy vs Shallow Copy Demo ===" << endl;
    // Shallow copy demo (uncomment to test):
    /*
    String s1("hello");
    String s2 = s1; // Shallow copy by default
    s1.print();
    s2.print();
    // Modify s2's data
    s2.getData()[0] = 'H';
    cout << "After modifying s2:" << endl;
    s1.print(); // s1 is also changed! (dangerous)
    s2.print();
    // Both s1 and s2 will call delete[] on the same pointer when destroyed (double free!)
    */

    // Deep copy demo:
    String s3("world");
    String s4 = s3; // Deep copy
    s3.print();
    s4.print();
    s4.getData()[0] = 'W';
    cout << "After modifying s4:" << endl;
    s3.print(); // s3 is NOT changed
    s4.print();
    // No double free, each object manages its own memory

    // Assignment operator deep copy
    String s5("cpp");
    s5 = s4;
    cout << "After assignment s5 = s4:" << endl;
    s5.print();
    s4.print();

    // Self-assignment safety
    s5 = s5;
    cout << "After self-assignment s5 = s5:" << endl;
    s5.print();

    /*
    Summary:
    - Shallow copy copies pointer values, leading to shared memory, double free, and data corruption.
    - Deep copy allocates new memory and copies content, ensuring each object is independent.
    - Always implement deep copy for classes managing resources (Rule of Three).
    - Handle self-assignment and exception safety in assignment operator.
    */
    return 0;
}