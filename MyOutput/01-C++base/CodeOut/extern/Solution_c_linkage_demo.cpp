// C/C++ Linkage Practice - Solution
#include <iostream>
#include <iomanip>

// Solution 1: C-style function declaration
extern "C" {
    int calculate_sum(int a, int b);
}

// Solution 2: C++ function with same name but different parameters
double calculate_sum(double a, double b);

// Solution 3: Implement C-style function
extern "C" int calculate_sum(int a, int b) {
    return a + b;
}

// Solution 4: Implement C++ function
double calculate_sum(double a, double b) {
    return a + b;
}

int main() {
    // Solution 5: Function pointer for C-style function
    int (*c_func_ptr)(int, int) = calculate_sum;
    
    // Solution 6: Call both versions
    int int_result = calculate_sum(5, 3);
    double double_result = calculate_sum(5.5, 3.2);
    
    // Solution 7: Use function pointer
    int ptr_result = c_func_ptr(10, 20);
    
    // Solution 8: Print results
    std::cout << "C-style function (int): " << int_result << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "C++ function (double): " << double_result << std::endl;
    std::cout << "Function pointer result: " << ptr_result << std::endl;
    
    return 0;
} 