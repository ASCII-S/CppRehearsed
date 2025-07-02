/*
 * const_function_params.cpp
 * Demonstration of const in function parameters
 *
 * This file demonstrates:
 * - When to use const with function parameters
 * - Performance implications
 * - Best practices for different data types
 *
 * TODO: Complete the code by following the instructions
 */

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cstring>
using namespace std;

// ===== Functions for small built-in types =====

// TODO: Implement a simple function that takes an int parameter
// Should you use const int or just int? Why?
// int calculate_square(???) {
//     return ??? * ???;
// }

int calculate_square(int x)
{
    return x * x;
}
// TODO: Implement the same function with const int parameter
// int calculate_square_const(???) {
//     return ??? * ???;
// }

int calculate_square_const(const int &x)
{
    return x * x;
}
// ===== Functions for large objects (strings) =====

// TODO: Function that takes string by value (inefficient for large strings)
// void process_string_by_value(???) {
//     cout << "Processing: " << ??? << endl;
//     cout << "Length: " << ???.length() << endl;
// }
void process_string_by_value(string str)
{
    cout << "Processing: " << str << endl;
    cout << "Length: " << str.length() << endl;
}

// TODO: Function that takes string by const reference (efficient)
// void process_string_by_const_ref(???) {
//     cout << "Processing: " << ??? << endl;
//     cout << "Length: " << ???.length() << endl;
//     // TODO: Try to modify the string parameter - what happens?
//     // ??? += " modified";  // Uncomment to see error
// }
void process_string_by_const_ref(const string &str)
{
    cout << "Processing: " << str << endl;
    cout << "Length: " << str.length() << endl;
    // TODO: Try to modify the string parameter - what happens?
    // str += " modified"; // Uncomment to see error
}

// TODO: Function that takes string by non-const reference (can modify)
// void modify_string_by_ref(???) {
//     ??? += " [MODIFIED]";
// }

void modify_string_by_ref(string &str)
{
    str += " [MODIFIED]";
    cout << "Modified string: " << str << endl;
}

// ===== Functions for containers =====

// TODO: Function to find maximum in vector - should take const reference
// int find_max(???) {
//     if (???.empty()) return 0;
//
//     int max_val = ???[0];
//     for (size_t i = 1; i < ???.size(); ++i) {
//         if (???[i] > max_val) {
//             max_val = ???[i];
//         }
//     }
//     return max_val;
// }

int find_max(const vector<int> &vec)
{
    if (vec.empty())
        return 0;
    int max_val = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (vec[i] > max_val)
        {
            max_val = vec[i];
        }
    }
    return max_val;
}

// TODO: Function to double all values in vector - should take non-const reference
// void double_values(???) {
//     for (int& val : ???) {
//         val *= 2;
//     }
// }

void double_values(vector<int> &vec)
{
    for (int &val : vec)
    {
        val *= 2;
    }
}

// ===== Functions for C-style strings =====

// TODO: Function to calculate string length (like strlen)
// Should take const char* - why?
// size_t my_strlen(???) {
//     size_t len = 0;
//     while (???[len] != '\0') {
//         len++;
//     }
//     return len;
// }
size_t my_strlen(const char *str)
{
    size_t len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

// Performance testing function
void performance_test()
{
    cout << "\n=== Performance Test ===" << endl;

    // Create a large string
    string large_string(10000, 'A');

    auto start = chrono::high_resolution_clock::now();

    // TODO: Call the by-value function many times and measure time
    // for (int i = 0; i < 1000; ++i) {
    //     process_string_by_value(large_string);
    // }

    int num = 10;
    for (int i = 0; i < 1000; ++i)
    {
        process_string_by_value(large_string);
    }
    auto mid = chrono::high_resolution_clock::now();

    // TODO: Call the by-const-reference function many times
    // for (int i = 0; i < 1000; ++i) {
    //     process_string_by_const_ref(large_string);
    // }
    for (int i = 0; i < 1000; ++i)
    {
        process_string_by_const_ref(large_string);
    }
    auto end = chrono::high_resolution_clock::now();

    auto time1 = chrono::duration_cast<chrono::microseconds>(mid - start);
    auto time2 = chrono::duration_cast<chrono::microseconds>(end - mid);

    cout << "By value: " << time1.count() << " microseconds" << endl;
    cout << "By const ref: " << time2.count() << " microseconds" << endl;
}

int main()
{
    cout << "=== const Function Parameters Demo ===" << endl;

    // Step 1: Built-in types
    cout << "\n--- Built-in types ---" << endl;
    // TODO: Test your square functions with an integer
    cout << "calculate_square(10): " << calculate_square(10) << endl;
    cout << "calculate_square_const(10): " << calculate_square_const(10) << endl;

    // Step 2: String parameters
    cout << "\n--- String parameters ---" << endl;
    string test_string = "Hello World";

    // TODO: Test all three string functions
    process_string_by_value(test_string);
    process_string_by_const_ref(test_string);
    modify_string_by_ref(test_string);

    // Step 3: Container parameters
    cout << "\n--- Container parameters ---" << endl;
    vector<int> numbers = {1, 5, 3, 9, 2, 7};

    // TODO: Test find_max function
    cout << "Max value: " << find_max(numbers) << endl;

    cout << "Original vector: ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    // TODO: Test double_values function
    double_values(numbers);
    cout << "After doubling: ";
    for (int n : numbers)
        cout << n << " ";
    cout << endl;

    // Step 4: C-style strings
    cout << "\n--- C-style strings ---" << endl;
    const char *c_string = "Hello C++";

    // TODO: Test your strlen function
    cout << "strlen(c_string): " << strlen(c_string) << endl;
    cout << "my_strlen(c_string): " << my_strlen(c_string) << endl;

    cout << "\n--- std string ---" << endl;
    string std_string = "Hello std string";
    cout << "strlen(std_string): " << strlen(std_string.c_str()) << endl;
    cout << "my_strlen(std_string): " << my_strlen(std_string.c_str()) << endl;

    // Step 5: Performance comparison
    // performance_test(); // Uncomment when functions are implemented

    // Step 6: Best practices summary
    cout << "\n=== Best Practices Summary ===" << endl;
    cout << "1. Small built-in types (int, double): pass by value" << endl;
    cout << "2. Large objects (string, vector): pass by const reference" << endl;
    cout << "3. When you need to modify: pass by non-const reference" << endl;
    cout << "4. C-style strings: use const char* for read-only access" << endl;
    cout << "5. When in doubt, prefer const - it's safer!" << endl;

    return 0;
}

/*
 * ADDITIONAL EXERCISES:
 * 1. Implement all the TODO functions above
 * 2. Run performance_test() and observe the difference
 * 3. Create functions that work with custom classes
 * 4. Try passing const objects to non-const parameter functions
 *
 * DISCUSSION QUESTIONS:
 * 1. Why is const important for function parameters?
 * 2. When would you choose const T& over T for parameters?
 * 3. What happens if you try to modify a const parameter?
 * 4. How does const help with function overloading?
 */