#include <iostream>
#include <cstdint>
#include <arpa/inet.h> // Linux/Unix系统的网络字节序函数

bool isBigEndian()
{
    uint16_t testData = 0x0001;
    uint8_t *bytePtr = reinterpret_cast<uint8_t *>(&testData);
    return (bytePtr == 0x00);
}

uint16_t swap16(uint16_t &src)
{
    return (src >> 8 | src << 8);
}

uint32_t swap32(uint32_t &src)
{
    return ((src >> 24) & 0xff) |
           ((src >> 8) & 0xff00) |
           ((src << 8) & 0xff0000) |
           ((src << 24) & 0xff000000);
}

// TODO 1: 手动实现 htons (host to network short) 函数
uint16_t myHtons(uint16_t hostshort)
{
    // 提示：网络字节序是大端序
    // 如果当前系统是小端序，需要转换；如果是大端序，直接返回
    // 可以复用之前写的字节序检测和转换函数

    // 你的代码在这里
    if (!isBigEndian()) return swap16(hostshort);
    return hostshort; // 暂时直接返回，请替换为正确逻辑
}

// TODO 2: 手动实现 htonl (host to network long) 函数
uint32_t myHtonl(uint32_t hostlong)
{
    // 提示：实现原理和 htons 类似，但处理的是32位数据

    // 你的代码在这里
    if (!isBigEndian()) return swap32(hostlong);
    return hostlong; // 暂时直接返回，请替换为正确逻辑
}

// TODO 3: 手动实现 ntohs (network to host short) 函数
uint16_t myNtohs(uint16_t netshort)
{
    // 提示：这个函数的实现和 htons 完全一样
    // 因为字节序转换是可逆的操作

    // 你的代码在这里
    if (!isBigEndian()) return swap16(netshort);
    return netshort; // 暂时直接返回，请替换为正确逻辑
}

// TODO 4: 手动实现 ntohl (network to host long) 函数
uint32_t myNtohl(uint32_t netlong)
{
    // 提示：这个函数的实现和 htonl 完全一样

    // 你的代码在这里
    if (!isBigEndian()) return swap32(netlong);
    return netlong; // 暂时直接返回，请替换为正确逻辑
}

// 辅助函数：打印字节
void printBytes(void *data, size_t size, const std::string &label)
{
    uint8_t *bytes = static_cast<uint8_t *>(data);
    std::cout << label << ": ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << std::hex << "0x" << static_cast<int>(bytes[i]) << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== 网络字节序转换练习 ===" << std::endl;

    // TODO 5: 测试16位数值的网络字节序转换
    uint16_t hostPort = 8080; // 常见的HTTP端口
    std::cout << "\n=== 16位测试 ===" << std::endl;
    std::cout << "主机字节序端口号: " << std::dec << hostPort << std::endl;

    // 使用系统函数
    uint16_t netPort = htons(hostPort);
    uint16_t backToHost = ntohs(netPort);

    printBytes(&hostPort, 2, "hostPort");
    printBytes(&netPort, 2, "netPort");
    printBytes(&backToHost, 2, "backToHost");
    // TODO: 使用你实现的函数进行相同的转换，并比较结果

    uint16_t mynetPort = myHtons(hostPort);
    uint16_t mybackTohost = myNtohs(mynetPort);

    printBytes(&mynetPort, 2, "mynetPort");
    printBytes(&mybackTohost, 2, "mybackTohost");

    // TODO 6: 测试32位数值的网络字节序转换
    uint32_t hostIP = 0xC0A80001; // 192.168.0.1 的十六进制表示
    std::cout << "\n=== 32位测试 ===" << std::endl;
    std::cout << "主机字节序IP: 0x" << std::hex << hostIP << std::endl;

    // TODO: 分别使用系统函数和你实现的函数进行转换
    uint32_t netIP = htonl(hostIP);
    uint32_t backToHostIP = ntohl(netIP);

    printBytes(&hostIP, 4, "hostIP");
    printBytes(&netIP, 4, "netIP");
    printBytes(&backToHostIP, 4, "backToHostIP");

    uint32_t mynetIP = myHtonl(hostIP);
    uint32_t mybackToHostIP = myNtohl(mynetIP);

    printBytes(&mynetIP, 4, "mynetIP");
    printBytes(&mybackToHostIP, 4, "mybackToHostIP");

    // TODO 7: 验证你的实现是否正确
    std::cout << "\n=== 验证实现正确性 ===" << std::endl;

    std::cout << (netPort == mynetPort ? "Pass htons!" : "Fail htons!") << std::endl;
    std::cout << (backToHost == mybackTohost ? "Pass ntohs!" : "Fail ntohs!") << std::endl;
    std::cout << (netIP == mynetIP ? "Pass htonl!" : "Fail htonl!") << std::endl;
    std::cout << (backToHostIP == mybackToHostIP ? "Pass ntohl!" : "Fail ntohl!") << std::endl;

    return 0;
}