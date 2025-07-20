# strlen函数原型详解

## 函数原型

```c
size_t strlen(const char* str);
```

## 详细说明

### 函数签名解析

- **返回类型**: `size_t` 
  - 这是一个无符号整数类型，通常定义为 `unsigned int` 或 `unsigned long`
  - 用于表示对象的大小或数组的长度
  - 在64位系统上通常是64位，在32位系统上通常是32位

- **函数名**: `strlen`
  - string length的缩写，表示字符串长度

- **参数**: `const char* str`
  - `const`: 表示函数不会修改指向的字符串内容
  - `char*`: 指向字符的指针，即C风格字符串
  - `str`: 参数名，表示要计算长度的字符串

### 头文件

```c
#include <cstring>  // C++中使用
#include <string.h> // C中使用
```

### 功能描述

strlen函数计算C风格字符串的长度，**不包括结尾的空字符('\0')**。

### 使用示例

```cpp
#include <iostream>
#include <cstring>

int main() {
    // 示例1：字符数组
    char str1[] = "Hello";
    std::cout << "strlen(str1): " << strlen(str1) << std::endl; // 输出: 5
    
    // 示例2：字符指针
    const char* str2 = "World";
    std::cout << "strlen(str2): " << strlen(str2) << std::endl; // 输出: 5
    
    // 示例3：空字符串
    const char* empty = "";
    std::cout << "strlen(empty): " << strlen(empty) << std::endl; // 输出: 0
    
    // 示例4：std::string转换
    std::string s = "C++ String";
    std::cout << "strlen(s.c_str()): " << strlen(s.c_str()) << std::endl; // 输出: 10
    
    return 0;
}
```

### 重要注意事项

1. **空字符终止**: strlen依赖于字符串以'\0'结尾，如果字符串没有正确终止，会导致未定义行为

2. **时间复杂度**: O(n)，其中n是字符串长度，因为需要遍历整个字符串

3. **与sizeof的区别**:

   ```cpp
   char arr[] = "Hello";
   std::cout << sizeof(arr) << std::endl;  // 输出: 6 (包括'\0')
   std::cout << strlen(arr) << std::endl;  // 输出: 5 (不包括'\0')
   ```

4. **空指针检查**: strlen不会检查空指针，传入NULL会导致程序崩溃

### 内部实现原理

strlen的典型实现：

```c
size_t strlen(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
```

### 常见错误

1. **传入空指针**:

   ```cpp
   char* p = nullptr;
   strlen(p); // 错误！会导致程序崩溃
   ```

2. **未初始化的字符数组**:

   ```cpp
   char arr[100]; // 未初始化
   strlen(arr); // 错误！可能读取到随机内存
   ```

3. **混淆sizeof和strlen**:

   ```cpp
   char* p = "Hello";
   sizeof(p); // 指针大小(8字节在64位系统)
   strlen(p); // 字符串长度(5)
   ```

### 替代方案

在C++中，推荐使用std::string：

```cpp
std::string s = "Hello";
s.length(); // 或 s.size()，更安全且高效
```
 