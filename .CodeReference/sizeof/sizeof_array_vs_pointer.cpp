/**
 * @file sizeof_array_vs_pointer.cpp
 *
 * @brief display the difference between sizeof array and sizeof pointer
 *
 *
 */

#include <iostream>

using std::cout;
using std::endl;

void foo(int arr[])
{
    cout << "sizeof arr in foo with arg `int arr[]`: " << sizeof(arr) << " Bytes" << endl;
    cout << "sizeof arr[0] in foo with arg `int arr[]`: " << sizeof(arr[0]) << " Bytes" << endl;
}

void foo2(int *arr)
{
    cout << "sizeof arr in foo with arg `int &arr`: " << sizeof(arr) << " Bytes" << endl;
    // cout << "sizeof arr[0] in foo with arg `int &arr`: " << sizeof(arr[0]) << " Bytes" << endl;
}

int main()
{
    int arr[10];
    cout << "sizeof void*: " << sizeof(void *) << " Bytes" << endl;
    cout << "sizeof arr[0]: " << sizeof(arr[0]) << " Bytes" << endl;
    cout << "sizeof arr: " << sizeof(arr) << " Bytes" << endl;
    cout << "sizeof arr + 1: " << sizeof(arr + 1) << " Bytes" << endl;
    foo(arr);
    foo2(arr);
    return 0;
}