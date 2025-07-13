#include <iostream>
#include <string>
using namespace std;

// PersonClass - 默认成员是private的
class PersonClass {
    string name;  // private (默认)
    int age;      // private (默认)
    
public:
    PersonClass(string n, int a) : name(n), age(a) {}
    
    void introduce() {
        cout << "Class: I'm " << name << ", " << age << " years old." << endl;
    }
};

// PersonStruct - 默认成员是public的
struct PersonStruct {
    string name;  // public (默认)
    int age;      // public (默认)
    
    PersonStruct(string n, int a) : name(n), age(a) {}
    
private:
    void secretInfo() {
        cout << "This is secret info" << endl;
    }
};

int main() {
    // 创建PersonClass对象
    PersonClass person1("Alice", 25);
    // person1.name = "Bob";  // 编译错误！name是private的
    // person1.age = 30;      // 编译错误！age是private的
    person1.introduce();      // 可以调用public函数
    
    // 创建PersonStruct对象
    PersonStruct person2("Charlie", 22);
    person2.name = "David";   // 正常！name是public的
    person2.age = 28;         // 正常！age是public的
    cout << "Struct: I'm " << person2.name << ", " << person2.age << " years old." << endl;
    // person2.secretInfo();  // 编译错误！secretInfo是private的
    
    /* 
    答案解析：
    1. class的成员默认是private，所以不能直接访问name和age
    2. struct的成员默认是public，所以可以直接访问name和age
    3. 这是class和struct在C++中的唯一区别
    4. 无论是class还是struct，都可以显式指定访问权限
    */
    
    return 0;
} 