# C++ 中 explicit 的作用

**面试官：** 我看你简历上写熟悉C++，那我问你一个比较基础但容易犯错的问题。你知道explicit关键字的作用吗？

**求职者：** explicit主要是用来防止构造函数进行隐式类型转换的。比如说我们有一个只接受一个参数的构造函数，C++编译器默认会允许这种构造函数进行隐式转换，但有时候这不是我们想要的。

**面试官：** 不错，你说的对。那你能举个具体的例子吗？什么情况下隐式转换会出问题？

**求职者：** 好的。比如我们有一个Vector2D类，构造函数接受一个float参数：

```cpp
class Vector2D {
public:
    Vector2D(float magnitude) : x(magnitude), y(magnitude) {}
private:
    float x, y;
};
```

然后我们有个函数：

```cpp
void process(Vector2D vec) { /* 处理向量 */ }
```

这时候如果我们调用`process(5.0f)`，编译器会自动把float转换成Vector2D对象。

**面试官：** 对，这就是隐式转换。那你觉得这有什么问题吗？

**求职者：** 主要有几个问题：首先是代码可读性差，看到`process(5.0f)`很难理解这里发生了什么转换；其次是容易产生逻辑错误，如果我们本意是传入Vector2D对象但意外传了个数字，编译器不会报错，可能导致运行时的bug；最后是性能问题，每次隐式转换都会创建临时对象。

**面试官：** 分析得很好！那explicit关键字怎么解决这个问题？

**求职者：** 当我们把构造函数声明为explicit后：

```cpp
class Vector2D {
public:
    explicit Vector2D(float magnitude) : x(magnitude), y(magnitude) {}
private:
    float x, y;
};
```

这样`process(5.0f)`就会编译错误，必须显式转换：`process(Vector2D(5.0f))`。

**面试官：** 很好。那你知道explicit除了用在构造函数上，还能用在哪里吗？

**求职者：** 从C++11开始，explicit还可以用在类型转换操作符上。比如：

```cpp
class MyClass {
public:
    explicit operator bool() const { return some_condition; }
};
```

这样就防止了意外的bool转换。

**面试官：** 不错。那你在什么情况下会选择使用explicit？有什么经验法则吗？

**求职者：** 我觉得有几个原则：

1. 对于单参数构造函数，除非确实需要隐式转换的便利性，否则都应该加explicit
2. 对于表示"包装"或"拥有"关系的类（比如智能指针），通常需要explicit
3. 对于数值类型或字符串类型，可能允许隐式转换，但要谨慎考虑
4. 当不确定时，倾向于使用explicit，因为显式总比隐式安全

**面试官：** 总结得很好。最后一个问题，C++20对explicit有什么新特性吗？

**求职者：** C++20引入了条件explicit，可以根据编译时条件决定是否explicit：

```cpp
template<typename T>
class Optional {
public:
    template<typename U>
    explicit(!std::is_convertible_v<U, T>) Optional(U&& value);
};
```

这样可以在模板中更灵活地控制转换行为。

## 实战练习

为了加深理解，建议完成以下代码练习：

1. [基础implicit转换示例](../../MyOutput/01-C++语言基础篇/CodeOut/explicit/implicit_conversion_demo.cpp)
2. [explicit关键字使用](../../MyOutput/01-C++语言基础篇/CodeOut/explicit/explicit_demo.cpp)  
3. [转换操作符的explicit使用(选做)](../../MyOutput/01-C++语言基础篇/CodeOut/explicit/explicit_operator_demo.cpp)

练习答案：

1. [基础示例答案](../../MyOutput/01-C++语言基础篇/CodeOut/explicit/Solution_implicit_conversion_demo.cpp)
2. [explicit使用答案](../../MyOutput/01-C++语言基础篇/CodeOut/explicit/Solution_explicit_demo.cpp)
3. [转换操作符答案](../../MyOutput/01-C++语言基础篇/CodeOut/explicit/Solution_explicit_operator_demo.cpp)
