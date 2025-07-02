/**
 * @file array_to_pointer.cpp
 *
 * @brief demonstrate the process of array to pointer
 *
 */

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

void fun(char carray[])
{
    cout << "===========array to pointer=============" << endl;
    cout << "sizeof(carray) in fun: " << sizeof(carray) << endl;
    cout << "strlen(carray) in fun: " << strlen(carray) << endl;
}

// 专门为char数组设计的模板函数
template <size_t N>
void fun2(const char (&arr)[N])
{
    cout << "===========keep array type by template=============" << endl;
    cout << "sizeof(arr) in fun2: " << sizeof(arr) << endl;
    cout << "strlen(arr) in fun2: " << strlen(arr) << endl;
}

void fun3(char (&carray)[12])
{
    cout << "===========keep array type by reference=============" << endl;
    cout << "sizeof(carray) in fun3: " << sizeof(carray) << endl;
    cout << "strlen(carray) in fun3: " << strlen(carray) << endl;
}

void multi_dim_array(char arr[][4])
{
    cout << "===========array to pointer in multi-dim array=============" << endl;
    cout << "sizeof(arr) in multi_dim_array: " << sizeof(arr) << endl;
    cout << "strlen(arr[0]) in multi_dim_array: " << strlen(arr[0]) << endl;
}

int main()
{
    char carray[] = "hello world";
    char(&carray2)[12] = carray;
    cout << "===========array=============" << endl;
    cout << "sizeof(carray): " << sizeof(carray) << endl;
    cout << "strlen(carray): " << strlen(carray) << endl;
    cout << "sizeof(carray2): " << sizeof(carray2) << endl;
    cout << "strlen(carray2): " << strlen(carray2) << endl;
    fun(carray);
    fun2(carray);
    fun3(carray);

    char mdarray[2][4] = {"m1", "m2"};
    cout << "===========multi-dim array=============" << endl;
    cout << "sizeof(mdarray): " << sizeof(mdarray) << endl;
    cout << "strlen(mdarray[0]): " << strlen(mdarray[0]) << endl;
    multi_dim_array(mdarray);

    return 0;
}