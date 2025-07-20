# C++中类（class）和结构（struct）的区别

你知道吗，很多人刚开始学C++的时候都会困惑：class和struct到底有什么区别？其实说白了，在C++中它们几乎是一模一样的！

## 定义

从C语言过来的同学可能会想，struct不就是用来定义数据结构的吗？但在C++里面，struct可比C语言中的强大多了。

在C++中：

- **class**: 用`class`关键字定义的类
- **struct**: 用`struct`关键字定义的结构体

但这里有个关键点：**在C++中，struct实际上就是一个class！** 它们可以有构造函数、析构函数、成员函数、继承、虚函数，什么都能做。

## 默认访问权限

这是它们的**第一个区别**！

你想想看，当你写一个class的时候：

```cpp
class MyClass {
    int data;  // 这个默认是什么权限？
public:
    void func();
};
```

这个`data`默认是`private`的，对吧？

但如果用struct：

```cpp
struct MyStruct {
    int data;  // 这个默认是什么权限？
private:
    void func();
};
```

这个`data`默认就是`public`的！

说白了：

- **class的成员默认是private**
- **struct的成员默认是public**

就这么简单！这是最主要的区别。

想要亲自验证一下吗？我给你准备了一个小练习：[默认访问权限练习](../../MyOutput/01-C++语言基础篇/CodeOut/class_struct/access_permission_demo.cpp)

## class可以用于定义模板参数

这里有个很有意思的地方！在定义模板的时候，你可以这样写：

```cpp
template<class T>        // 可以用class
void myFunction(T value) {
    // ...
}

template<typename T>     // 也可以用typename
void myFunction2(T value) {
    // ...
}
```

但你**不能**这样写：

```cpp
template<struct T>       // 编译错误！不能用struct
void myFunction3(T value) {
    // ...
}
```

所以说，在模板参数声明中：

- `template<class T>` ✅ 正确
- `template<typename T>` ✅ 正确  
- `template<struct T>` ❌ 错误

这里的`class`关键字并不表示T必须是一个class，它可以是任何类型（包括基本类型、struct、class等）。这只是历史原因，早期C++只有`class`这个关键字，后来才加入了`typename`。

所以现在大家更倾向于用`typename`，因为它更准确地表达了"这是一个类型参数"的含义。

想试试这个区别吗？我给你准备了一个练习：[模板参数练习](../../MyOutput/01-C++语言基础篇/CodeOut/class_struct/template_parameter_demo.cpp)

## 使用习惯

虽然技术上它们几乎一样，但大家在实际开发中还是有一些不成文的习惯：

**什么时候用struct？**

- 当你想表示一个简单的数据容器时
- 成员主要是public的数据时
- 类似C语言中struct的使用场景

```cpp
struct Point {
    int x, y;  // 默认public，直接访问
};

struct Student {
    string name;
    int age;
    double score;
};
```

**什么时候用class？**

- 当你需要封装，隐藏内部实现时
- 有复杂的业务逻辑时
- 需要保护数据完整性时

```cpp
class BankAccount {
private:
    double balance;  // 隐藏余额，不能直接修改
public:
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};
```

**面试常问：你觉得什么时候用class，什么时候用struct？**

答案其实很灵活，但核心思想是：

- 如果主要是存储数据，成员大多是public的，用struct
- 如果需要封装和隐藏实现细节，用class

记住，这只是习惯和约定，不是硬性规定。你完全可以用struct写出和class一样复杂的功能。

## 动手练习

理论说完了，来动手试试吧！我给你准备了三个练习：

1. **默认访问权限实验**: [access_permission_demo.cpp](../../MyOutput/01-C++语言基础篇/CodeOut/class_struct/access_permission_demo.cpp)
   - 亲自验证class和struct的默认访问权限区别
   - 通过编译错误来理解这个重要区别

2. **模板参数练习**: [template_parameter_demo.cpp](../../MyOutput/01-C++语言基础篇/CodeOut/class_struct/template_parameter_demo.cpp)
   - 体验template<class T>和template<typename T>的区别
   - 尝试template<struct T>看看编译错误
   - 理解为什么只有class和typename能用于模板参数

3. **使用场景练习**: [usage_scenarios_demo.cpp](../../MyOutput/01-C++语言基础篇/CodeOut/class_struct/usage_scenarios_demo.cpp)
   - 实现Point、Student、BankAccount、Calculator
   - 体会什么时候用struct，什么时候用class
   - 理解封装和数据保护的重要性

每个练习大概10分钟就能完成，做完你就彻底明白class和struct的区别了！

记住：**技术上几乎一样，习惯上有区分，主要区别是：**

1. **默认访问权限不同**（class默认private，struct默认public）
2. **模板参数声明时只能用class/typename，不能用struct**
