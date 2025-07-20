#include <iostream>
#include <cstdint>

// TODO 1: 完善这个函数，用来检测当前系统是否为大端序
bool isBigEndian() {
    // 提示：创建一个多字节数值，然后检查第一个字节的值
    // 可以使用 uint16_t 类型的数值 0x0001
    // 使用 reinterpret_cast 将其转换为 uint8_t 指针
    // 检查第一个字节是否为 0 来判断大端序
    
    // 你的代码在这里

        // 为什么使用 uint？
        // uint16_t: 无符号16位整数，确保数据类型的大小和符号位不会影响字节序检测
        // uint8_t: 无符号8位整数（1字节），用于逐字节访问内存
        
        // 为什么使用 reinterpret_cast？
        // reinterpret_cast 可以将一个指针类型强制转换为另一个指针类型
        // 这里将 uint16_t* 转换为 uint8_t*，让我们能够按字节访问同一块内存
    
    uint16_t data = 0x0001;  // 16位数据：二进制为 0000000000000001
    uint8_t* test = reinterpret_cast<uint8_t*>(&data);  // 将16位数据的地址转换为字节指针
    
        // test[0] 表示什么？
        // test[0]: 访问内存中的第一个字节（最低地址）
        // test[1]: 访问内存中的第二个字节（较高地址）
        
        // 在小端序系统中：0x0001 在内存中存储为 [01][00]，所以 test[0] = 0x01
        // 在大端序系统中：0x0001 在内存中存储为 [00][01]，所以 test[0] = 0x00
        // 打印指针地址和指针指向的值
        // 为什么要转换为 void*？
        // &data 的类型是 uint16_t*，如果直接输出会被解释为指向数据的指针
        // 某些编译器可能不会直接打印指针地址，而是尝试解引用
        // 转换为 void* 确保输出的是指针的地址值，而不是指针指向的内容
        // void* 是通用指针类型，std::cout 知道如何正确输出其地址
    std::cout << "数据地址: " << static_cast<void*>(&data) << std::endl;
    std::cout << "指针地址: " << static_cast<void*>(test) << std::endl;
        // 为什么要转换为 int？
        // test[0] 的类型是 uint8_t，当直接输出到 std::cout 时：
        // uint8_t 本质上是 unsigned char，会被当作字符输出，而不是数值
        // 例如：如果 test[0] = 1，直接输出会显示字符 '\1'（不可见字符）
        // 转换为 int 后，确保按数值形式输出，这样我们能看到实际的数字值
    std::cout << "第一个字节值: 0x" << std::hex << static_cast<int>(test[0]) << std::endl;
    std::cout << "第二个字节值: 0x" << std::hex << static_cast<int>(test[1]) << std::endl;
    std::cout << std::dec; // 恢复十进制输出
    return test[0] == 0x00;  // 如果第一个字节是0，说明是大端序
    return false; // 暂时返回false，请替换为正确的逻辑
}

// TODO 2: 完善这个函数，使用union方法检测大端序
bool isBigEndianUnion() {
    // 提示：创建一个包含 uint32_t 和 uint8_t 的联合体
    // 给 uint32_t 赋值为 1
    // 检查 uint8_t 的值来判断字节序
    
        // 联合体(union)是什么？
        // 联合体是一种特殊的数据结构，它允许在同一块内存位置存储不同类型的数据
        // 与结构体(struct)不同，联合体的所有成员共享同一块内存空间
        // 联合体的大小等于其最大成员的大小
        
        // 在这个例子中：
        // - uint32_t i 占用4个字节
        // - uint8_t c 占用1个字节
        // 整个联合体占用4个字节，i和c共享这4个字节的内存
    
    // 当我们给i赋值时，c会访问i的最低字节（在小端序系统中）或最高字节（在大端序系统中）
    union {
        uint32_t i;  // 32位整数（4字节）
        uint8_t c;   // 8位整数（1字节），与i共享内存
    } test;
    
    // 你的代码在这里
    test.i = 1;
    return test.c==0;
    
    return false; // 暂时返回false，请替换为正确的逻辑
}

// TODO 3: 实现字节序转换函数 - 16位
uint16_t swap16(uint16_t& value) {
    // 提示：使用位移操作来交换高低字节
    // (value >> 8) | (value << 8)
    
    // 位移操作详解：
    // 假设 value = 0x1234 (十进制4660)
    // 二进制表示：0001 0010 0011 0100
    
    // value >> 8：右移8位
    // 0001 0010 0011 0100 >> 8 = 0000 0000 0001 0010 (0x0012)
    // 这将高字节移到低字节位置
    
    // value << 8：左移8位  
    // 0001 0010 0011 0100 << 8 = 0011 0100 0000 0000 (0x3400)
    // 这将低字节移到高字节位置
    
    // 按位或操作 |：
    // 0000 0000 0001 0010 (value >> 8)
    // 0011 0100 0000 0000 (value << 8)
    // =====================
    // 0011 0100 0001 0010 (结果：0x3412)
    
    // 因此 0x1234 交换字节序后变成 0x3412
    
    // 关于运算顺序的说明：
    // 1. 位移运算符 >> 和 << 的优先级高于按位或运算符 |
    // 2. 所以实际执行顺序是：先计算 (value >> 8)，再计算 (value << 8)，最后执行 |
    // 3. 不会丢失高位，因为：
    //    - value >> 8：右移后高位补0，低8位变成新的低8位
    //    - value << 8：左移后低位补0，高8位变成新的高8位
    //    - 两个结果进行 | 运算，正好组合成交换后的结果
    
    // 例如：value = 0x1234
    // 注意：这两个操作是基于原始value值分别计算的，不是依次执行
    // value >> 8 = 0x0012  (基于原始value=0x1234，高字节0x12移到低位，高位补0)
    // value << 8 = 0x3400  (基于原始value=0x1234，低字节0x34移到高位，低位补0)
    // 因为C++中表达式 (value >> 8) | (value << 8) 会先分别计算两个操作数，再进行|运算
    // 所以两个位移操作都是基于原始的value值，互不影响
    // 0x0012 | 0x3400 = 0x3412  (两个结果组合)
    
    return (value >> 8) | (value << 8);
    // 你的代码在这里
    
    return value; // 暂时直接返回，请替换为正确的逻辑
}

// TODO 4: 实现字节序转换函数 - 32位
uint32_t swap32(uint32_t value) {
    // 提示：需要交换4个字节的位置
    // 可以分别处理每个字节，然后组合
    
    // 你的代码在这里
    return (((value >> 24) & 0xff)      |
            ((value >> 8) & 0xff00)     |
            ((value << 8) & 0xff0000)   |
            ((value << 24) & 0xff000000));
    return value; // 暂时直接返回，请替换为正确的逻辑
}

int main() {
    std::cout << "=== 大端小端检测练习 ===" << std::endl;
    
    // TODO 5: 调用你实现的函数，输出当前系统的字节序
    std::cout << "当前系统字节序检测：" << std::endl;
    std::cout << "appoach1: " << (isBigEndian() ? "BigEndian!" : "LittleEndian") << std::endl;
    std::cout << "approach2: " << (isBigEndianUnion() ? "BigEngian" : "LittleEndian") << std::endl;
    
    // 测试数据
    uint32_t testValue = 0x12345678;
    std::cout << "原始值：0x" << std::hex << testValue << std::endl;
    
    // TODO 6: 使用你实现的swap32函数转换字节序并输出
    uint32_t swapped32 = swap32(testValue);
    std::cout << "交换后值：0x" << std::hex << swapped32 << std::endl;
    
    // TODO 7: 演示16位数值的字节序转换
    uint16_t test16 = 0x1234;
    std::cout << "原始值：0x" << std::hex << test16 << std::endl;
    uint16_t swapped16 = swap16(test16);
    std::cout << "交换后值：0x" << std::hex << swapped16 << std::endl;
    
    return 0;
} 