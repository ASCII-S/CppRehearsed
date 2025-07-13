# Macro与Typedef的区别

## 面试官：我们来聊聊C++中的宏和typedef，你觉得它们有什么区别吗？

**求职者：** 这是个经典问题！最核心的区别就是处理时机不同。宏是预处理阶段的文本替换，而typedef是编译器识别的类型别名。

## 面试官：能举个具体例子说明吗？

**求职者：** 当然！最常见的陷阱就是指针声明的问题。

比如这样定义：

```cpp
#define PTR_INT int*
typedef int* IntPtr;
```

然后声明多个变量：

```cpp
PTR_INT a, b;  // 展开后：int* a, b; 只有a是指针！
IntPtr c, d;   // c和d都是指针
```

## 面试官：还有其他差异吗？

**求职者：** 有的，const修饰时行为也不同。比如：

```cpp
#define INT_PTR int*
typedef int* IntPtr;

const INT_PTR p1;    // const int* p1 - 指向常量的指针
const IntPtr p2;     // int* const p2 - 常量指针
```

这就导致p1和p2的语义完全不同了！

## 面试官：那你觉得实际开发中应该选择哪个？

**求职者：** 我会优先选择typedef，理由有三：

1. **类型安全**：typedef有真正的类型检查
2. **作用域遵循**：typedef遵循C++的作用域规则
3. **调试友好**：编译器错误信息更清晰

宏主要适合定义常量或简单的代码片段。

## 面试官：说得很好！最后问个进阶的，typename和typedef一起用过吗？

**求职者：** 用过！模板编程中很常见，比如：

```cpp
typedef typename std::vector<T>::iterator iterator_type;
```

这里typename告诉编译器后面是个类型名，不是成员变量，然后typedef给它起个别名。

## 代码练习

想要加深理解，可以动手练习：[宏与typedef对比练习](../.CodeReference/macro_typedef/macro_typedef_demo.cpp)

## 小结

- **宏**：预处理文本替换，无类型概念
- **typedef**：编译期类型别名，有类型安全
- **选择建议**：现代C++推荐typedef/using，宏用于特殊场景
