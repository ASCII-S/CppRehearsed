#include <iostream>
using namespace std;
// TODO1: 定义一个模板函数，实现两个参数的加法，支持int、double、string等类型
// 提示：使用template<typename T> T add(T a, T b);
template <typename T>
T add (T a, T b)
{
    return a+b;
}

// TODO2: 在main函数中，分别用int、double、string类型调用模板函数，观察多态效果
int main()
{
    cout << "add(1,1): " << add(1,1)<< endl;
    cout << "add(1.1,1.1): " << add(1.1,1.1)<< endl;
    cout << "add(1s,1a): " << add(string("1s"),string("1a"))<< endl;
    
}
// TODO3: 可选：尝试用模板类实现类似的多态效果

// 参考：完成后可对照Solution/template_demo.cpp中的标准答案