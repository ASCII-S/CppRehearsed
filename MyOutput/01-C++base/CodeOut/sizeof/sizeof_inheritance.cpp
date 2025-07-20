/**
 * @file sizeof_inheritance.cpp
 * @brief 演示C++类继承在内存中的表现
 * 包括空类继承、单继承、多继承、虚继承等情况
 */
#include <iostream>
using namespace std;

// === 空类相关 ===
class EmptyBase
{
    // 空基类
};

class EmptyDerived : public EmptyBase
{
    // 空派生类
};

// === 单继承 ===
class BaseWithInt
{
    int base_value;

public:
    BaseWithInt(int val = 0) : base_value(val) {}
};

class DerivedWithInt : public BaseWithInt
{
    int derived_value;

public:
    DerivedWithInt(int base_val = 0, int derived_val = 0)
        : BaseWithInt(base_val), derived_value(derived_val) {}
};

// === 虚函数影响 ===
class BaseWithVirtual
{
    int base_value;
    virtual void foo() {}

public:
    BaseWithVirtual(int val = 0) : base_value(val) {}
};

class DerivedWithVirtual : public BaseWithVirtual
{
    int derived_value;

public:
    DerivedWithVirtual(int base_val = 0, int derived_val = 0)
        : BaseWithVirtual(base_val), derived_value(derived_val) {}
    void foo() override {}
};

// === 多继承 ===
class BaseA
{
    int a;

public:
    BaseA(int val = 0) : a(val) {}
};

class BaseB
{
    char b;

public:
    BaseB(char val = 0) : b(val) {}
};

class MultiDerived : public BaseA, public BaseB
{
    double c;

public:
    MultiDerived(int a_val = 0, char b_val = 0, double c_val = 0.0)
        : BaseA(a_val), BaseB(b_val), c(c_val) {}
};

// === 多个虚函数表指针的例子 ===
class BaseAVirtual
{
    int a;
    virtual void funcA() {}

public:
    BaseAVirtual(int val = 0) : a(val) {}
};

class BaseBVirtual
{
    char b;
    virtual void funcB() {}

public:
    BaseBVirtual(char val = 0) : b(val) {}
};

class MultiVirtualDerived : public BaseAVirtual, public BaseBVirtual
{
    double c;

public:
    MultiVirtualDerived(int a_val = 0, char b_val = 0, double c_val = 0.0)
        : BaseAVirtual(a_val), BaseBVirtual(b_val), c(c_val) {}
    void funcA() override {}
    void funcB() override {}
};

// === 虚继承 ===
class VirtualBase
{
    int virtual_base_value;

public:
    VirtualBase(int val = 0) : virtual_base_value(val) {}
};

class VirtualDerivedA : virtual public VirtualBase
{
    int a_value;

public:
    VirtualDerivedA(int base_val = 0, int a_val = 0)
        : VirtualBase(base_val), a_value(a_val) {}
};

class VirtualDerivedB : virtual public VirtualBase
{
    int b_value;

public:
    VirtualDerivedB(int base_val = 0, int b_val = 0)
        : VirtualBase(base_val), b_value(b_val) {}
};

class DiamondDerived : public VirtualDerivedA, public VirtualDerivedB
{
    int diamond_value;

public:
    DiamondDerived(int base_val = 0, int a_val = 0, int b_val = 0, int diamond_val = 0)
        : VirtualBase(base_val), VirtualDerivedA(base_val, a_val),
          VirtualDerivedB(base_val, b_val), diamond_value(diamond_val) {}
};

// === 虚继承 + 虚函数的组合 ===
/**
 * 4 Bytes vptr + 4 Bytes int = 8 Bytes
 */
class VirtualBaseWithVirtual
{
    int virtual_base_value;
    virtual void baseFunc() {}

public:
    VirtualBaseWithVirtual(int val = 0) : virtual_base_value(val) {}
};
/**
 * 4 Bytes vptr_base + 4 Bytes vbptr + 4 Bytes int +4 Bytes vptr_drived = 16 Bytes
 */
class VirtualDerivedAWithVirtual : virtual public VirtualBaseWithVirtual
{
    int a_value;
    virtual void funcA() {}

public:
    VirtualDerivedAWithVirtual(int base_val = 0, int a_val = 0)
        : VirtualBaseWithVirtual(base_val), a_value(a_val) {}
};

/**
 * same as VirtualDerivedAWithVirtual
 */
class VirtualDerivedBWithVirtual : virtual public VirtualBaseWithVirtual
{
    int b_value;
    virtual void funcB() {}

public:
    VirtualDerivedBWithVirtual(int base_val = 0, int b_val = 0)
        : VirtualBaseWithVirtual(base_val), b_value(b_val) {}
};

/**
 * s
 */
class DiamondDerivedWithVirtual : public VirtualDerivedAWithVirtual, public VirtualDerivedBWithVirtual
{
    int diamond_value;

public:
    DiamondDerivedWithVirtual(int base_val = 0, int a_val = 0, int b_val = 0, int diamond_val = 0)
        : VirtualBaseWithVirtual(base_val), VirtualDerivedAWithVirtual(base_val, a_val),
          VirtualDerivedBWithVirtual(base_val, b_val), diamond_value(diamond_val) {}
    void baseFunc() override {}
    void funcA() override {}
    void funcB() override {}
};

void printSizeAndExplanation(const char *name, size_t size, const char *explanation)
{
    cout << "sizeof(" << name << "): " << size << " bytes - " << explanation << endl;
}

int main()
{
    cout << "=== C++ Class Inheritance Memory Layout Analysis ===" << endl
         << endl;

    // 1. Empty class inheritance
    cout << "1. Empty Class Inheritance:" << endl;
    printSizeAndExplanation("EmptyBase", sizeof(EmptyBase),
                            "Empty base class takes 1 byte to ensure unique object address");
    cout << "   Memory layout: [1 byte placeholder] = Expected: 1 byte" << endl;
    printSizeAndExplanation("EmptyDerived", sizeof(EmptyDerived),
                            "Empty derived class inherits from empty base, compiler applies EBO optimization, still 1 byte");
    cout << "   Memory layout: [1 byte placeholder] (EBO applied, no additional space for empty base) = Expected: 1 byte" << endl;
    cout << endl;

    // 2. Single inheritance
    cout << "2. Single Inheritance:" << endl;
    printSizeAndExplanation("BaseWithInt", sizeof(BaseWithInt),
                            "Contains one int member");
    cout << "   Memory layout:  Expected: 4 bytes = [int base_value: 4 bytes]" << endl;
    printSizeAndExplanation("DerivedWithInt", sizeof(DerivedWithInt),
                            "Base members + derived members, memory layout: [base members][derived members]");
    cout << "   Memory layout:  Expected: 8 bytes = [int base_value: 4 bytes][int derived_value: 4 bytes]" << endl;
    cout << endl;

    // 3. Virtual functions impact
    cout << "3. Virtual Functions Impact:" << endl;
    printSizeAndExplanation("BaseWithVirtual", sizeof(BaseWithVirtual),
                            "Contains virtual function, int member");
    cout << "   Memory layout:  Expected: 8 bytes = [vptr: 4 bytes][int base_value: 4 bytes]" << endl;
    printSizeAndExplanation("DerivedWithVirtual", sizeof(DerivedWithVirtual),
                            "Contains virtual function override, int member");
    cout << "   Memory layout:  Expected: 12 bytes = [vptr: 4 bytes][int base_value: 4 bytes][int derived_value: 4 bytes]" << endl;
    cout << "   Note: override virtual function will not add new vptr, but replace the original vptr" << endl;
    cout << endl;

    // 4. Multiple inheritance
    cout << "4. Multiple Inheritance:" << endl;
    printSizeAndExplanation("BaseA", sizeof(BaseA), "Contains int member");
    cout << "   Memory layout:  Expected: 4 bytes = [int a: 4 bytes]" << endl;
    printSizeAndExplanation("BaseB", sizeof(BaseB), "Contains char member");
    cout << "   Memory layout:  Expected: 1 byte = [char b: 1 byte]" << endl;
    printSizeAndExplanation("MultiDerived", sizeof(MultiDerived), "Contains double members");
    cout << "   Memory layout:  Expected: 16 bytes = [int a: 4 bytes][char b: 1 byte][padding: 3 bytes][double c: 8 bytes]" << endl;
    cout << endl;

    // 4.1. Multiple inheritance with virtual functions (Multiple vptr)
    cout << "4.1. Multiple Inheritance with Virtual Functions (Multiple vptr):" << endl;
    printSizeAndExplanation("BaseAVirtual", sizeof(BaseAVirtual), "Contains int member and virtual function");
    cout << "   Memory layout:  Expected: 8 bytes = [vptr_A: 4 bytes][int a: 4 bytes]" << endl;
    printSizeAndExplanation("BaseBVirtual", sizeof(BaseBVirtual), "Contains char member and virtual function");
    cout << "   Memory layout:  Expected: 8 bytes = [vptr_B: 4 bytes][char b: 1 byte][padding: 3 bytes]" << endl;
    printSizeAndExplanation("MultiVirtualDerived", sizeof(MultiVirtualDerived), "Contains double member and override virtual function");
    cout << "   Memory layout:  Expected: 24 bytes = [vptr_A: 4 bytes][int a: 4 bytes][vptr_B: 4 bytes][char b: 1 byte][padding: 3 bytes][double c: 8 bytes]" << endl;
    cout << "   Note: This object contains TWO virtual function table pointers!" << endl;
    cout << endl;

    // 5. Virtual inheritance
    cout << "5. Virtual Inheritance (solving diamond inheritance problem):" << endl;
    printSizeAndExplanation("VirtualBase", sizeof(VirtualBase), "Contains int member");
    cout << "   Memory layout:  Expected: 4 bytes = [int virtual_base_value: 4 bytes]" << endl;
    printSizeAndExplanation("VirtualDerivedA", sizeof(VirtualDerivedA), "Contains int member");
    cout << "   Memory layout:  Expected: 12 bytes = [vbptr: 4 bytes][int a_value: 4 bytes][VirtualBase: 4 bytes]" << endl;
    printSizeAndExplanation("VirtualDerivedB", sizeof(VirtualDerivedB), "Contains int member");
    cout << "   Memory layout:  Expected: 12 bytes = [vbptr: 4 bytes][int b_value: 4 bytes][VirtualBase: 4 bytes]" << endl;
    printSizeAndExplanation("DiamondDerived", sizeof(DiamondDerived), "Contains int member");
    cout << "   Memory layout:  Expected: ~24 bytes = [VirtualDerivedA part: ~8 bytes][VirtualDerivedB part: ~8 bytes][int diamond_value: 4 bytes][VirtualBase: 4 bytes (shared)]" << endl;
    cout << endl;

    // 5.1. Virtual inheritance + Virtual functions
    cout << "5.1. Virtual Inheritance + Virtual Functions (vbptr + vptr):" << endl;
    printSizeAndExplanation("VirtualBaseWithVirtual", sizeof(VirtualBaseWithVirtual), "Contains int member and virtual function");
    cout << "   Memory layout:  Expected: 8 bytes = [vptr: 4 bytes][int virtual_base_value: 4 bytes]" << endl;
    printSizeAndExplanation("VirtualDerivedAWithVirtual", sizeof(VirtualDerivedAWithVirtual), "Contains int member and new virtual function");
    cout << "   Memory layout:  Expected: 16 bytes = [vptr: 4 bytes][vbptr: 4 bytes][int a_value: 4 bytes][padding: 4 bytes]" << endl;
    printSizeAndExplanation("DiamondDerivedWithVirtual", sizeof(DiamondDerivedWithVirtual), "Contains int member and override virtual function");
    cout << "   Memory layout:  [VirtualDerivedAWithVirtual part: ~8 bytes][VirtualDerivedBWithVirtual part: ~8 bytes][int diamond_value: 4 bytes][VirtualBaseWithVirtual: 4 bytes (shared)]" << endl;
    cout << "   Note: Contains BOTH virtual function table pointers (vptr) AND virtual base table pointers (vbptr)" << endl;
    cout << endl;

    // 6. Memory address analysis
    cout << "6. Memory Address Analysis Example:" << endl;
    DerivedWithInt obj(10, 20);
    cout << "Object address: " << &obj << endl;
    cout << "Base class part address: " << static_cast<BaseWithInt *>(&obj) << endl;
    cout << "Base and derived classes share the same starting address, derived members follow base members" << endl;

    return 0;
}