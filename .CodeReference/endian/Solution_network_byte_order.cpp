#include <iostream>
#include <cstdint>
#include <arpa/inet.h>

// 字节序检测函数
bool isBigEndian() {
    uint16_t test = 0x0001;
    uint8_t* byte = reinterpret_cast<uint8_t*>(&test);
    return byte[0] == 0;
}

// 16位字节序转换
uint16_t swap16(uint16_t value) {
    return (value >> 8) | (value << 8);
}

// 32位字节序转换
uint32_t swap32(uint32_t value) {
    return ((value >> 24) & 0xFF) |
           ((value >> 8) & 0xFF00) |
           ((value << 8) & 0xFF0000) |
           ((value << 24) & 0xFF000000);
}

// 解答 1: 手动实现 htons
uint16_t myHtons(uint16_t hostshort) {
    if (isBigEndian()) {
        return hostshort;  // 大端序系统，无需转换
    } else {
        return swap16(hostshort);  // 小端序系统，需要转换
    }
}

// 解答 2: 手动实现 htonl
uint32_t myHtonl(uint32_t hostlong) {
    if (isBigEndian()) {
        return hostlong;  // 大端序系统，无需转换
    } else {
        return swap32(hostlong);  // 小端序系统，需要转换
    }
}

// 解答 3: 手动实现 ntohs  
uint16_t myNtohs(uint16_t netshort) {
    // 实现和 htons 完全一样，因为字节序转换是可逆的
    return myHtons(netshort);
}

// 解答 4: 手动实现 ntohl
uint32_t myNtohl(uint32_t netlong) {
    // 实现和 htonl 完全一样，因为字节序转换是可逆的
    return myHtonl(netlong);
}

// 辅助函数：打印字节
void printBytes(void* data, size_t size, const std::string& label) {
    uint8_t* bytes = static_cast<uint8_t*>(data);
    std::cout << label << ": ";
    for (size_t i = 0; i < size; i++) {
        std::cout << std::hex << "0x" << static_cast<int>(bytes[i]) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== 网络字节序转换解答 ===" << std::endl;
    
    std::cout << "当前系统: " << (isBigEndian() ? "大端序" : "小端序") << std::endl;
    
    // 解答 5: 16位数值测试
    uint16_t hostPort = 8080;
    std::cout << "\n=== 16位测试 ===" << std::endl;
    std::cout << "主机字节序端口号: " << std::dec << hostPort << std::endl;
    
    // 系统函数转换
    uint16_t netPort_sys = htons(hostPort);
    uint16_t backToHost_sys = ntohs(netPort_sys);
    
    // 自实现函数转换
    uint16_t netPort_my = myHtons(hostPort);
    uint16_t backToHost_my = myNtohs(netPort_my);
    
    std::cout << "系统htons结果: " << std::hex << netPort_sys << std::endl;
    std::cout << "自实现htons结果: " << std::hex << netPort_my << std::endl;
    std::cout << "系统ntohs结果: " << std::dec << backToHost_sys << std::endl;
    std::cout << "自实现ntohs结果: " << std::dec << backToHost_my << std::endl;
    
    printBytes(&hostPort, sizeof(hostPort), "原始端口号字节");
    printBytes(&netPort_sys, sizeof(netPort_sys), "网络字节序");
    
    // 解答 6: 32位数值测试
    uint32_t hostIP = 0xC0A80001;  // 192.168.0.1
    std::cout << "\n=== 32位测试 ===" << std::endl;
    std::cout << "主机字节序IP: 0x" << std::hex << hostIP << std::endl;
    
    // 系统函数转换
    uint32_t netIP_sys = htonl(hostIP);
    uint32_t backToHost_IP_sys = ntohl(netIP_sys);
    
    // 自实现函数转换
    uint32_t netIP_my = myHtonl(hostIP);
    uint32_t backToHost_IP_my = myNtohl(netIP_my);
    
    std::cout << "系统htonl结果: 0x" << std::hex << netIP_sys << std::endl;
    std::cout << "自实现htonl结果: 0x" << std::hex << netIP_my << std::endl;
    std::cout << "系统ntohl结果: 0x" << std::hex << backToHost_IP_sys << std::endl;
    std::cout << "自实现ntohl结果: 0x" << std::hex << backToHost_IP_my << std::endl;
    
    printBytes(&hostIP, sizeof(hostIP), "原始IP字节");
    printBytes(&netIP_sys, sizeof(netIP_sys), "网络字节序IP");
    
    // 解答 7: 验证实现正确性
    std::cout << "\n=== 验证实现正确性 ===" << std::endl;
    
    bool correct16 = (netPort_sys == netPort_my) && (backToHost_sys == backToHost_my);
    bool correct32 = (netIP_sys == netIP_my) && (backToHost_IP_sys == backToHost_IP_my);
    
    std::cout << "16位函数实现" << (correct16 ? "正确" : "错误") << std::endl;
    std::cout << "32位函数实现" << (correct32 ? "正确" : "错误") << std::endl;
    
    // 额外测试：展示不同数值在不同字节序下的表现
    std::cout << "\n=== 数值在内存中的表现 ===" << std::endl;
    uint32_t testValues[] = {0x12345678, 0x11223344, 0xAABBCCDD};
    
    for (auto value : testValues) {
        std::cout << "\n原始值: 0x" << std::hex << value << std::endl;
        printBytes(&value, sizeof(value), "主机字节序");
        
        uint32_t converted = myHtonl(value);
        printBytes(&converted, sizeof(converted), "网络字节序");
    }
    
    return 0;
} 