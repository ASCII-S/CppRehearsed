#include <iostream>
#include <string>
using namespace std;

// TODO 1: 尝试用class关键字定义模板函数
// 要求：定义一个函数模板printValue，使用template<class T>
// 功能：接受任意类型的参数并打印
template <class T>
void printValue(T msg)
{
    std::cout << "print: " << msg << std::endl;
}

// TODO 2: 尝试用typename关键字定义模板函数
// 要求：定义一个函数模板printValue2，使用template<typename T>
// 功能：同样接受任意类型的参数并打印
template <typename T>
void printValue2(T msg)
{
    std::cout << "print: " << msg << std::endl;
}

// TODO 3: 尝试用struct关键字定义模板函数（这会出错！）
// 要求：将下面这行代码取消注释，看看编译器的反应
// template<struct T>
// void printValue3(T value) {
//     cout << "Value: " << value << endl;
// }

// TODO 4: 定义一个模板类，测试class和typename的使用
// 要求：定义Container类模板，分别用class和typename试试
template <class T>
class Container
{
    T a;
    string b;

public:
    Container(T a, string b) : a(a), b(b) {}

    friend ostream &operator<<(ostream &os, Container<T> &c)
    {
        return os << c.a << " " << c.b;
    }
};

template <typename T>
class Container2
{
    T a;
    string b;

public:
    Container2(T a, string b) : a(a), b(b) {}

    friend ostream &operator<<(ostream &os, Container2<T> &c)
    {
        return os << c.a << " " << c.b;
    }
};

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

// 重载<<操作符，方便打印Point
ostream &operator<<(ostream &os, const Point &p)
{
    return os << "(" << p.x << ", " << p.y << ")";
}

class Student
{
public:
    string name;
    int age;
    Student(string n, int a) : name(n), age(a) {}
};

ostream &operator<<(ostream &os, const Student &s)
{
    return os << s.name << "(" << s.age << ")";
}

int main()
{
    // TODO 5: 测试模板函数
    // 用不同类型测试你定义的模板函数：int, string, Point, Student
    int i = 1;
    double d = 2.01;
    char c = 'c';
    char *cptr = &c;

    printValue(1);
    printValue2(1);
    printValue(i);
    printValue2(i);
    printValue(d);
    printValue2(d);
    printValue(c);
    printValue2(c);
    printValue(&cptr);
    printValue2(&cptr);
    
    Point p(1, 2);
    Student s("John", 20);
    printValue(p);
    printValue2(p);
    printValue(s);
    printValue2(s);

    Container<int> c1(100, "Hello");
    cout << "Container1 data: " << c1 << endl;
    Container2<int> c2(100, "Hello");
    cout << "Container2 data: " << c2 << endl;

    Container<string> c3("Hello", "World");
    cout << "Container3 data: " << c3 << endl;
    Container2<string> c4("Hello", "World");
    cout << "Container4 data: " << c4 << endl;

    // TODO 6: 思考题
    // 1. template<class T>中的class是什么意思？
    // 2. 为什么不能写template<struct T>？
    // 3. class和typename在模板中有什么区别？
    // 4. 现在更推荐用哪个关键字？为什么？

    return 0;
}

// 编译提示：
// 1. 正常代码应该能编译通过
// 2. 如果取消注释TODO 3，会看到编译错误
// 3. 观察class和typename在功能上是完全一样的