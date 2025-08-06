# 重载、重写和隐藏的区别详解

## 重载

面试官：我们先聊聊C++的重载。你能说说什么是重载吗？

候选人：重载其实就是同一个作用域下，函数名相同但参数列表不同（参数个数、类型或顺序不同），编译器会根据调用时的参数自动选择合适的函数实现。常见的有函数重载和运算符重载。

面试官：那重载发生在什么阶段？

候选人：重载是编译期多态，编译器在编译时就决定了调用哪个函数。

面试官：能举个例子吗？

候选人：比如：

```cpp
int add(int a, int b);
double add(double a, double b);
```

调用`add(1,2)`和`add(1.0,2.0)`会自动匹配不同的实现。

> 代码引导：[重载练习](../../MyOutput/02-C++object/CodeOut/overload_and_override/overload_demo.cpp)

---

## 重写

面试官：那你能说说什么是重写（Override）吗？

候选人：重写是指子类中重新实现了父类的虚函数，函数签名必须完全一致。这样通过父类指针或引用调用虚函数时，会执行子类的实现。

面试官：重写和重载有什么区别？

候选人：重写是运行期多态，依赖虚函数和继承，重载是编译期多态。

面试官：能举个代码例子吗？

候选人：比如：

```cpp
class Base { public: virtual void show(); };
class Derived : public Base { public: void show() override; };
```

> 代码引导：[重写练习](../../MyOutput/02-C++object/CodeOut/overload_and_override/override_demo.cpp)

---

## 隐藏

面试官：那C++里还有个容易混淆的叫“隐藏”，你了解吗？

候选人：隐藏主要发生在继承关系中，子类定义了与父类同名的成员（不管参数是否相同），会把父类的同名成员全部隐藏。即使参数不同，也会隐藏父类的所有同名函数。

面试官：那怎么访问被隐藏的父类成员？

候选人：可以用作用域限定符，比如`Base::func()`。

面试官：能举个例子吗？

候选人：

```cpp
class Base { public: void func(int); };
class Derived : public Base { public: void func(double); };
```

此时`Derived`对象只能直接调用`func(double)`，`func(int)`被隐藏了。

> 代码引导：[隐藏练习](../../MyOutput/02-C++object/CodeOut/overload_and_override/hide_demo.cpp)

---

## 区别

面试官：你能总结一下重载、重写和隐藏的本质区别吗？

候选人：
- **重载**：同一作用域，函数名相同，参数不同，编译期决定。
- **重写**：继承体系，子类重写父类虚函数，签名完全一致，运行期多态。
- **隐藏**：继承体系，子类同名成员（参数可不同）会隐藏父类所有同名成员。

面试官：实际开发中要注意什么？

候选人：要注意隐藏容易导致父类的重载函数无法访问，需要用`using`或作用域限定符显式引入。

---

动手练习安排：
- 请在`MyOutput/02-C++object/CodeOut/overload_and_override/overload_demo.cpp`中，按TODO序号完成重载相关练习。
- 在`MyOutput/02-C++object/CodeOut/overload_and_override/override_demo.cpp`中，按TODO序号完成重写相关练习。
- 在`MyOutput/02-C++object/CodeOut/overload_and_override/hide_demo.cpp`中，按TODO序号完成隐藏相关练习。

每个TODO建议10分钟内完成，遇到不会的地方可以先写伪代码。

完成后可参考答案：
- [overload_demo.cpp答案](../../MyOutput/02-C++object/CodeOut/overload_and_override/Solution/overload_demo.cpp)
- [override_demo.cpp答案](../../MyOutput/02-C++object/CodeOut/overload_and_override/Solution/override_demo.cpp)
- [hide_demo.cpp答案](../../MyOutput/02-C++object/CodeOut/overload_and_override/Solution/hide_demo.cpp)

---

## 自测练习

完成代码练习后，建议进行以下自测：

### 书面自测
- [重载、重写和隐藏自测题](../../MyOutput/02-C++object/WriteOut/overload_override/overload_override_self_test.md)

### 口语练习
- [面试对话练习](../../MyOutput/02-C++object/SpeakOut/overload_override/overload_override_interview_questions.md)

建议先完成书面自测，然后进行口语练习，录制视频来检验自己的理解程度。
