#include <iostream>
#include <string>
using namespace std;

// TODO 1: 创建一个Person类来演示this指针的各种用法
class Person {
private:
    string name;
    int age;
    string address;

public:
    // TODO 2: 实现构造函数，当参数名与成员变量名相同时，使用this指针区分
    // 构造函数参数：string name, int age, string address
    Person(/* 补充参数列表 */string name, int age, string address) {
        // 使用this指针来区分参数和成员变量
        // this->name = name;
        // this->age = age;  
        // this->address = address;
        this->name = name;
        this->age = age;
        this->address = address;
    }

    // TODO 3: 实现setName函数，返回*this以支持链式调用
    Person& setName(const string& name) {
        // 使用this指针设置name
        // 返回*this支持链式调用
        this->name = name;
        return *this;
    }

    // TODO 4: 实现setAge函数，返回*this以支持链式调用
    Person& setAge(int age) {
        // 使用this指针设置age
        // 返回*this支持链式调用
        this->age = age;
        return *this;
    }

    // TODO 5: 实现setAddress函数，返回*this以支持链式调用
    Person& setAddress(const string& address) {
        // 使用this指针设置address
        // 返回*this支持链式调用
        this->address = address;
        return *this;
    }

    // TODO 6: 实现拷贝赋值运算符，演示自赋值检查
    Person& operator=(const Person& other) {
        // 检查自赋值：if (this == &other)
        // 如果不是自赋值，则复制数据
        // 返回*this
        if(this == &other)
        {
            return *this;
        }
        this->name = other.name;
        this->age = other.age;
        this->address = other.address;
        return *this;
    }

    // TODO 7: 实现compare函数，比较当前对象与另一个对象
    bool compare(const Person& other) const {
        // 可以通过this指针访问当前对象的成员
        // 比较name, age, address是否都相等
        if(this->name == other.name && this->age == other.age && this->address == other.address)
        {
            return true;
        }
        return false;
    }

    // TODO 8: 实现display函数显示对象信息
    void display() const {
        // 输出格式：Name: xxx, Age: xxx, Address: xxx
        // 可以隐式使用this指针访问成员变量
        cout << "Name: " << this->name << ", Age: " << this->age << ", Address: " << this->address << endl;
    }

    // TODO 9: 实现一个static函数，验证static函数没有this指针
    static void showClassName() {
        cout << "This is Person class" << endl;
        // 注意：在static函数中不能使用this指针
        // 也不能直接访问非static成员变量
    }

    // TODO 10: 实现getThis函数，返回this指针
    Person* getThis() {
        // 返回this指针
        return this;
    }
};

// TODO 11: 创建一个回调函数场景，演示传递this指针
void processPersonCallback(Person* p) {
    cout << "Processing person via callback: ";
    p->display();
}

class PersonManager {
public:
    void processCurrentPerson(Person& person) {
        // TODO 12: 调用回调函数，传入person的this指针
        // processPersonCallback(person.getThis());
        processPersonCallback(&person);
    }
};

int main() {
    cout << "=== this指针演示程序 ===" << endl;

    // TODO 13: 测试构造函数中的this指针使用
    cout << "\n1. 测试构造函数中的this指针：" << endl;
    Person person1("张三", 25, "北京");
    person1.display();

    // TODO 14: 测试链式调用
    cout << "\n2. 测试链式调用：" << endl;
    Person person2("", 0, "");
    person2.setName("李四").setAge(30).setAddress("上海").display();

    // TODO 15: 测试自赋值
    cout << "\n3. 测试自赋值：" << endl;
    person1 = person1;  // 自赋值
    person1.display();

    // TODO 16: 测试compare函数
    cout << "\n4. 测试compare函数：" << endl;
    Person person3("张三", 25, "北京");
    cout << "person1与person3是否相等: " << (person1.compare(person3) ? "是" : "否") << endl;
    cout << "person1与person2是否相等: " << (person1.compare(person2) ? "是" : "否") << endl;

    // TODO 17: 测试static函数（没有this指针）
    cout << "\n5. 测试static函数：" << endl;
    Person::showClassName();

    // TODO 18: 测试回调函数场景
    cout << "\n6. 测试回调函数场景：" << endl;
    PersonManager manager;
    manager.processCurrentPerson(person1);

    // TODO 19: 演示this指针的地址
    cout << "\n7. this指针地址演示：" << endl;
    cout << "person1对象地址: " << &person1 << endl;
    cout << "person1.getThis()返回地址: " << person1.getThis() << endl;
    cout << "两个地址是否相同: " << (&person1 == person1.getThis() ? "是" : "否") << endl;

    return 0;
}

/*
预期输出：
=== this指针演示程序 ===

1. 测试构造函数中的this指针：
Name: 张三, Age: 25, Address: 北京

2. 测试链式调用：
Name: 李四, Age: 30, Address: 上海

3. 测试自赋值：
Name: 张三, Age: 25, Address: 北京

4. 测试compare函数：
person1与person3是否相等: 是
person1与person2是否相等: 否

5. 测试static函数：
This is Person class

6. 测试回调函数场景：
Processing person via callback: Name: 张三, Age: 25, Address: 北京

7. this指针地址演示：
person1对象地址: 0x7fff5fbff730
person1.getThis()返回地址: 0x7fff5fbff730
两个地址是否相同: 是
*/ 