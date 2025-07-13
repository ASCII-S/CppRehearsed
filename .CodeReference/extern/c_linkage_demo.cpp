// C/C++ Linkage Practice
// Time: 4 minutes

#include <iostream>

// TODO 1: Create an extern "C" block and declare a C-style function
// The function should be named 'calculate_sum' and take two int parameters
extern "C" {
    int calculate_sum(int a, int b);
}

// TODO 2: Outside the extern "C" block, create a C++ function with the same name
// but different parameter types (double, double) - this demonstrates function overloading
double calculate_sum(double a, double b);

// TODO 3: C-style function implementation is in calculate_sum.c
// 注意：C函数已在 calculate_sum.c 中实现

// TODO 4: Implement the C++ function (double version)
// It should return the sum of two doubles with 2 decimal precision
double calculate_sum(double a, double b){
    return a + b;
}

// TODO 5: Create a function pointer that can point to the C-style function
int (*sum_int_ptr)(int a, int b) =  calculate_sum;

int main() {
    // TODO 6: Call both versions of calculate_sum
    int int_result = calculate_sum(1,2);
    double double_result = calculate_sum(1.5,1.5);

    // TODO 7: Use the function pointer to call the C-style function
    sum_int_ptr(1,2);
    
    // TODO 8: Print the results to verify both functions work correctly
    std::cout << "int_result: " << int_result << std::endl;
    std::cout << "double_result: " << double_result << std::endl;
    std::cout << "sum_int_ptr(1,2): " << sum_int_ptr(1,2) << std::endl;

    return 0;
}

// Note: In a real project, the C function would be in a separate .c file
// This example demonstrates the syntax and concept 

// to run this code, use the following command:
// gcc -c calculate_sum.c -o calculate_sum.o
// g++ -c c_linkage_demo.cpp -o c_linkage_demo.o
// g++ calculate_sum.o c_linkage_demo.o -o c_linkage_demo
// ./c_linkage_demo