#include <iostream>
#include <cstdint>

// 解答 1: 检测当前系统是否为大端序
bool isBigEndian() {
    uint16_t test = 0x0001;
    uint8_t* byte = reinterpret_cast<uint8_t*>(&test);
    return byte[0] == 0; // 如果第一个字节是0，说明是大端序
}

// 解答 2: 使用union方法检测大端序
bool isBigEndianUnion() {
    union {
        uint32_t i;
        uint8_t c;
    } test;
    
    test.i = 1;
    return test.c == 0; // 如果低字节为0，说明是大端序
}

// 解答 3: 16位字节序转换
uint16_t swap16(uint16_t value) {
    return (value >> 8) | (value << 8);
}

// 解答 4: 32位字节序转换
uint32_t swap32(uint32_t value) {
    return ((value >> 24) & 0xFF) |
           ((value >> 8) & 0xFF00) |
           ((value << 8) & 0xFF0000) |
           ((value << 24) & 0xFF000000);
}

int main() {
    std::cout << "=== 大端小端检测解答 ===" << std::endl;
    
    // 解答 5: 检测系统字节序
    std::cout << "当前系统字节序检测：" << std::endl;
    std::cout << "方法1检测结果：" << (isBigEndian() ? "大端序" : "小端序") << std::endl;
    std::cout << "方法2检测结果：" << (isBigEndianUnion() ? "大端序" : "小端序") << std::endl;
    
    // 测试数据
    uint32_t testValue = 0x12345678;
    std::cout << "\n原始值：0x" << std::hex << testValue << std::endl;
    
    // 解答 6: 32位字节序转换
    uint32_t swapped32 = swap32(testValue);
    std::cout << "32位转换后：0x" << std::hex << swapped32 << std::endl;
    
    // 解答 7: 16位字节序转换
    uint16_t test16 = 0x1234;
    uint16_t swapped16 = swap16(test16);
    std::cout << "\n16位原始值：0x" << std::hex << test16 << std::endl;
    std::cout << "16位转换后：0x" << std::hex << swapped16 << std::endl;
    
    // 额外演示：直接查看内存布局
    std::cout << "\n=== 内存布局演示 ===" << std::endl;
    uint32_t demo = 0x12345678;
    uint8_t* bytes = reinterpret_cast<uint8_t*>(&demo);
    
    std::cout << "0x12345678 在内存中的字节布局：" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "地址[" << i << "]: 0x" << std::hex << static_cast<int>(bytes[i]) << std::endl;
    }
    
    return 0;
} 