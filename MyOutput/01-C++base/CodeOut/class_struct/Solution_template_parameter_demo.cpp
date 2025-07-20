#include <iostream>
#include <string>
using namespace std;

// 用class关键字定义模板函数
template<class T>
void printValue(T value) {
    cout << "printValue (class): " << value << endl;
}

// 用typename关键字定义模板函数
template<typename T>
void printValue2(T value) {
    cout << "printValue2 (typename): " << value << endl;
}

// 这行代码会导致编译错误！
// template<struct T>
// void printValue3(T value) {
//     cout << "Value: " << value << endl;
// }

// 用class定义模板类
template<class T>
class Container1 {
private:
    T data;
public:
    Container1(T value) : data(value) {}
    T getData() const { return data; }
    void setData(T value) { data = value; }
};

// 用typename定义模板类
template<typename T>
class Container2 {
private:
    T data;
public:
    Container2(T value) : data(value) {}
    T getData() const { return data; }
    void setData(T value) { data = value; }
};

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

ostream& operator<<(ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

class Student {
public:
    string name;
    int age;
    Student(string n, int a) : name(n), age(a) {}
};

ostream& operator<<(ostream& os, const Student& s) {
    return os << s.name << "(" << s.age << ")";
}

int main() {
    cout << "=== 测试模板函数 ===" << endl;
    
    // 测试基本类型
    printValue(42);              // int
    printValue2(42);
    
    printValue(3.14);            // double
    printValue2(3.14);
    
    printValue(string("Hello")); // string
    printValue2(string("World"));
    
    // 测试自定义类型
    Point p(3, 4);
    printValue(p);               // struct Point
    printValue2(p);
    
    Student s("张三", 20);
    printValue(s);               // class Student
    printValue2(s);
    
    cout << "\n=== 测试模板类 ===" << endl;
    
    // 测试Container1 (用class定义的)
    Container1<int> c1(100);
    cout << "Container1 data: " << c1.getData() << endl;
    
    Container1<string> c1_str("Hello");
    cout << "Container1 string: " << c1_str.getData() << endl;
    
    // 测试Container2 (用typename定义的)
    Container2<double> c2(3.14159);
    cout << "Container2 data: " << c2.getData() << endl;
    
    Container2<Point> c2_point(Point(5, 6));
    cout << "Container2 point: " << c2_point.getData() << endl;
    
    cout << "\n=== 思考题答案 ===" << endl;
    cout << "1. template<class T>中的class并不表示T必须是类，它可以是任何类型" << endl;
    cout << "2. 不能写template<struct T>是因为C++语法不支持，只支持class和typename" << endl;
    cout << "3. class和typename在模板参数声明中功能完全一样，没有区别" << endl;
    cout << "4. 现在更推荐用typename，因为它更准确地表达了'类型参数'的含义" << endl;
    cout << "5. class是历史遗留，typename是后来为了更清晰而添加的" << endl;
    
    return 0;
}

/*
重要知识点总结：
1. 在模板参数声明中，只能用class或typename，不能用struct
2. template<class T>和template<typename T>功能完全相同
3. 这里的class不意味着T必须是类，可以是任何类型
4. typename更语义化，现在更推荐使用
5. 这是class和struct的一个重要区别
*/ 