# 重载、重写和隐藏自测题

## 基础概念自测

### 1. 重载相关
1. 什么是函数重载？重载的条件是什么？
2. 重载发生在编译期还是运行期？为什么？
3. 以下哪些是有效的重载？
   ```cpp
   int func(int a);
   int func(int a, int b);
   int func(int a, double b);
   double func(int a, double b);
   int func(double a, int b);
   ```
4. 运算符重载和函数重载有什么区别？

### 2. 重写相关
1. 什么是虚函数重写？重写的条件是什么？
2. 重写发生在编译期还是运行期？为什么？
3. `override`关键字的作用是什么？
4. 以下代码是否正确？
   ```cpp
   class Base {
   public:
       virtual void func(int a) { }
   };
   
   class Derived : public Base {
   public:
       void func(int a) override { }
   };
   ```

### 3. 隐藏相关
1. 什么是成员隐藏？隐藏的条件是什么？
2. 隐藏和重载有什么区别？
3. 如何访问被隐藏的父类成员？
4. 以下代码的输出是什么？
   ```cpp
   class Base {
   public:
       void func(int a) { cout << "Base::func(int)" << endl; }
   };
   
   class Derived : public Base {
   public:
       void func(double a) { cout << "Derived::func(double)" << endl; }
   };
   
   Derived d;
   d.func(1);  // 输出什么？
   ```

## 综合应用自测

### 1. 代码分析题
分析以下代码，回答相关问题：

```cpp
class Animal {
public:
    virtual void makeSound() { cout << "Animal sound" << endl; }
    void eat() { cout << "Animal eating" << endl; }
    void eat(int amount) { cout << "Animal eating " << amount << " food" << endl; }
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Woof!" << endl; }
    void eat() { cout << "Dog eating" << endl; }
    void play() { cout << "Dog playing" << endl; }
};

class Cat : public Animal {
public:
    void makeSound() override { cout << "Meow!" << endl; }
    void eat(double amount) { cout << "Cat eating " << amount << " food" << endl; }
};
```

问题：
1. 在`Dog`类中，`eat()`函数是重载、重写还是隐藏？
2. 在`Cat`类中，`eat(double)`函数是重载、重写还是隐藏？
3. 如何让`Cat`对象能够调用父类的`eat(int)`函数？
4. 以下代码的输出是什么？
   ```cpp
   Animal* animal = new Dog();
   animal->makeSound();
   animal->eat();
   animal->eat(5);
   ```

### 2. 实际开发场景
1. 在什么情况下应该使用重载？
2. 在什么情况下应该使用重写？
3. 如何避免隐藏带来的问题？
4. 使用`using`声明的作用是什么？

### 3. 面试常见问题
1. 重载和重写的区别是什么？
2. 虚函数表（vtable）的作用是什么？
3. 为什么C++不支持函数重载的返回类型？
4. 如何实现编译期多态和运行期多态？

## 编程实践题

### 1. 设计题
设计一个简单的图形类层次结构：
- 基类`Shape`包含虚函数`draw()`和`area()`
- 派生类`Circle`和`Rectangle`重写这些函数
- 实现函数重载来处理不同的参数类型

### 2. 调试题
找出以下代码中的问题并修复：

```cpp
class Base {
public:
    virtual void process(int x) { }
    void helper() { }
};

class Derived : public Base {
public:
    void process(double x) { }  // 问题1：这是什么？
    void helper(int x) { }      // 问题2：这是什么？
};
```

### 3. 扩展题
实现一个简单的容器类，支持：
- 重载的构造函数
- 重载的插入函数
- 虚函数用于不同类型的元素处理 