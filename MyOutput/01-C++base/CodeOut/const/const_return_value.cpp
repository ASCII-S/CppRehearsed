/*
 * const_return_value.cpp
 * Demonstration of const in function return values
 *
 * This file demonstrates:
 * - const return values for pointers
 * - const return values for references
 * - when const return makes sense vs when it doesn't
 * - preventing unwanted assignments to temporaries
 *
 * TODO: Complete the code by following the instructions
 */

#include <iostream>
#include <string>
using namespace std;

// Global data for demonstration
static const char *global_message = "Hello from global";
static string global_string = "Global String";

// ===== const return values for pointers =====

// TODO: Function returning const char* (can't modify the pointed-to data)
// const char* get_message() {
//     return ???;
// }

// TODO: Function returning char* (can modify the pointed-to data)
// char* get_modifiable_message() {
//     static char buffer[] = "Modifiable message";
//     return ???;
// }

// ===== const return values for references =====

// TODO: Function returning const reference to string
// const string& get_global_string_const() {
//     return ???;
// }

// TODO: Function returning non-const reference to string
// string& get_global_string_non_const() {
//     return ???;
// }

// ===== Class demonstrating const return for assignment operator =====
class MyClass
{
private:
    int value;

public:
    MyClass(int v = 0) : value(v) {}

    // TODO: Assignment operator returning const reference
    // This prevents chains like (a = b) = c;
    // const MyClass& operator=(???) {
    //     if (this != &other) {
    //         value = ???.value;
    //     }
    //     return *this;
    // }
    /**
     * @ToDo: ->和.有什么区别？
     */
    const MyClass &operator=(const MyClass &other)
    {
        if (this != &other)
        {
            this->value = other.value;
        }
        return *this;
    }

    // TODO: Non-const assignment operator (allows unwanted chains)
    // MyClass& operator=(???) {
    //     if (this != &other) {
    //         value = ???.value;
    //     }
    //     return *this;
    // }
    MyClass &operator=(MyClass &other)
    {
        if (this != &other)
        {
            this->value = other.value;
        }
        return *this;
    }

    // Getter functions
    int getValue() const { return value; }
    void setValue(int v) { value = v; }

    // Display function
    void display() const
    {
        cout << "Value: " << value << endl;
    }
};

// ===== Functions returning values (const usually not needed) =====

// TODO: Function returning int by value - should this be const?
// Think: does const make sense here?
// int calculate_sum(int a, int b) {
//     return ??? + ???;
// }

// TODO: Same function with const return - is this meaningful?
// const int calculate_sum_const(int a, int b) {
//     return ??? + ???;
// }

int main()
{
    cout << "=== const Return Values Demo ===" << endl;

    // Step 1: const pointer returns
    cout << "\n--- const pointer returns ---" << endl;

    // TODO: Call get_message() and try to modify the result
    // const char* msg = get_message();
    // cout << "Message: " << ??? << endl;
    // TODO: Try to modify - what happens?
    // msg[0] = 'h';  // Uncomment to see error

    // TODO: Call get_modifiable_message() and modify the result
    // char* mod_msg = get_modifiable_message();
    // cout << "Modifiable message: " << ??? << endl;
    // TODO: Modify the message
    // mod_msg[0] = 'M';
    // cout << "After modification: " << ??? << endl;

    // Step 2: const reference returns
    cout << "\n--- const reference returns ---" << endl;

    // TODO: Get const reference and try to modify
    // const string& const_ref = get_global_string_const();
    // cout << "Global string (const ref): " << ??? << endl;
    // TODO: Try to modify - what happens?
    // const_ref += " modified";  // Uncomment to see error

    // TODO: Get non-const reference and modify
    // string& non_const_ref = get_global_string_non_const();
    // cout << "Global string (non-const ref): " << ??? << endl;
    // TODO: Modify the string
    // ??? += " [MODIFIED]";
    // cout << "After modification: " << ??? << endl;

    // Step 3: Assignment operator with const return
    cout << "\n--- Assignment operator with const return ---" << endl;

    MyClass a(10), b(20), c(30);

    cout << "Initial values:" << endl;
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();
    cout << "c: ";
    c.display();

    // Normal assignment chain
    a = b = c; // This should work: b = c, then a = (result)
    cout << "\nAfter a = b = c:" << endl;
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();

    // TODO: Try problematic assignment if using non-const return
    // With const return, this line should cause a compile error:
    cout << "\nAfter (a = b) = c:" << endl;
    a.setValue(10);
    b.setValue(20);
    c.setValue(30);
    (a = b) = c; // Uncomment to test - should this be allowed?
    cout << "a: ";
    a.display();
    cout << "b: ";
    b.display();
    cout << "c: ";
    c.display();

    // Step 4: Value returns - const vs non-const
    cout << "\n--- Value returns ---" << endl;

    // TODO: Test both sum functions
    // int result1 = calculate_sum(5, 3);
    // const int result2 = calculate_sum_const(5, 3);
    // cout << "Sum 1: " << ??? << endl;
    // cout << "Sum 2: " << ??? << endl;

    // TODO: Can you assign to the return value of these functions?
    // calculate_sum(1, 2) = 100;       // What happens here?
    // calculate_sum_const(1, 2) = 100; // What about here?

    // Step 5: Best practices summary
    cout << "\n=== Best Practices Summary ===" << endl;
    cout << "1. Use const return for pointers when data shouldn't be modified" << endl;
    cout << "2. Use const return for references in assignment operators" << endl;
    cout << "3. const return for values is usually not needed (and ignored)" << endl;
    cout << "4. const return helps prevent logical errors in chained operations" << endl;
    cout << "5. Think about what operations should be allowed on your return values" << endl;

    return 0;
}

/*
 * DEEP DIVE QUESTIONS:
 *
 * 1. Why is const char* common in C-style string functions?
 * 2. When would you return const T& vs T& from a member function?
 * 3. Why doesn't const return value matter for built-in types?
 * 4. How does const return value affect function overloading?
 * 5. What's the difference between:
 *    - const T* func()     (const pointer return)
 *    - T* const func()     (this doesn't make sense - why?)
 *    - const T& func()     (const reference return)
 *
 * EXERCISE:
 * 1. Implement all the TODO functions
 * 2. Test the error cases by uncommenting them
 * 3. Create a class with both const and non-const versions of getters
 * 4. Experiment with const return in your own operator overloads
 */