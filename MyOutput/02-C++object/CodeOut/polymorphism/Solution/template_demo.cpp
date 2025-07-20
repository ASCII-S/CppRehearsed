#include <iostream>
#include <string>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(1, 2) << endl;
    cout << add(1.1, 2.2) << endl;
    cout << add(string("Hello, "), string("World!")) << endl;
    return 0;
}