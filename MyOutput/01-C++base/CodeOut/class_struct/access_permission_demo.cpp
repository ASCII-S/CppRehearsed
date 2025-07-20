#include <iostream>
#include <string>
using namespace std;

// TODO 1: 定义一个名为PersonClass的class
// 要求：
// - 有两个成员变量：name (string) 和 age (int)
// - 注意：不要写任何访问权限关键字，观察默认权限
// - 添加一个构造函数：PersonClass(string n, int a)
// - 添加一个public的成员函数：void introduce()
class PersonClass
{
    string name;
    int age;

public:
    PersonClass(string n, int a) : name(n), age(a) {}

    void introduce()
    {
        std::cout << "name: " << name << std::endl;
        std::cout << "age: " << age << std::endl;
    }
};

// TODO 2: 定义一个名为PersonStruct的struct
// 要求：
// - 有两个成员变量：name (string) 和 age (int)
// - 注意：同样不要写任何访问权限关键字，观察默认权限
// - 添加一个构造函数：PersonStruct(string n, int a)
// - 添加一个private的成员函数：void secretInfo()
struct PersonStruct
{
    string name;
    int age;
    PersonStruct(string n, int a)
    {
        name = n;
        age = a;
    }

private:
    void secretInfo()
    {
    }
};

int main()
{
    // TODO 3: 创建PersonClass对象
    // 尝试直接访问name和age成员，看看会发生什么？
    PersonClass pc1("John", 20);
    // pc1.name = "Bob";
    // pc1.age = 30;
    pc1.introduce();

    // TODO 4: 创建PersonStruct对象
    // 尝试直接访问name和age成员，对比与class的区别
    PersonStruct ps1("John", 20); 
    ps1.name = "Bob";
    ps1.age = 30;
    // ps1.secretInfo();

    // TODO 5: 思考题
    // 为什么PersonClass的成员无法直接访问？
    // 为什么PersonStruct的成员可以直接访问？
    // 这说明了什么问题？

    return 0;
}

// 完成练习后，编译程序观察编译错误，理解默认访问权限的区别