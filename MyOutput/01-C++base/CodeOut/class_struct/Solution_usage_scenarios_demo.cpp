#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Point结构体 - 简单的数据容器，成员通常是public的
struct Point {
    double x, y;  // 默认public
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double distanceToOrigin() {
        return sqrt(x*x + y*y);
    }
};

// Student结构体 - 简单的数据记录
struct Student {
    string name;
    int id;
    double gpa;
    
    Student(string n, int i, double g) : name(n), id(i), gpa(g) {}
    
    void display() {
        cout << "Student: " << name << " (ID: " << id << ", GPA: " << gpa << ")" << endl;
    }
};

// BankAccount类 - 需要封装和数据保护
class BankAccount {
private:
    double balance;           // 私有！不能直接修改
    string accountNumber;     // 私有！账号信息要保护
    
public:
    BankAccount(string accNum, double initialBalance = 0) 
        : accountNumber(accNum), balance(initialBalance) {
        if (initialBalance < 0) {
            balance = 0;  // 防止负余额
        }
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ", new balance: " << balance << endl;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ", new balance: " << balance << endl;
            return true;
        }
        cout << "Insufficient funds!" << endl;
        return false;
    }
    
    double getBalance() const {
        return balance;
    }
};

// Calculator类 - 有状态的计算器
class Calculator {
private:
    double result;  // 当前计算结果，需要保护
    
public:
    Calculator() : result(0) {}
    
    void add(double value) {
        result += value;
        cout << "Added " << value << ", result: " << result << endl;
    }
    
    void multiply(double value) {
        result *= value;
        cout << "Multiplied by " << value << ", result: " << result << endl;
    }
    
    double getResult() const {
        return result;
    }
    
    void reset() {
        result = 0;
        cout << "Calculator reset" << endl;
    }
};

int main() {
    // 测试Point结构体
    cout << "=== Point测试 ===" << endl;
    Point p1(3, 4);
    cout << "Point: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Distance to origin: " << p1.distanceToOrigin() << endl;
    
    p1.x = 5;  // 可以直接修改，因为是public
    p1.y = 12;
    cout << "Modified point: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "New distance: " << p1.distanceToOrigin() << endl;
    
    // 测试Student结构体
    cout << "\n=== Student测试 ===" << endl;
    Student s1("张三", 2024001, 3.8);
    s1.display();
    s1.gpa = 3.9;  // 可以直接修改
    s1.display();
    
    // 测试BankAccount类
    cout << "\n=== BankAccount测试 ===" << endl;
    BankAccount account("ACC001", 1000);
    cout << "Initial balance: " << account.getBalance() << endl;
    
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(2000);  // 余额不足
    
    // account.balance = 999999;  // 编译错误！balance是private的
    
    // 测试Calculator类
    cout << "\n=== Calculator测试 ===" << endl;
    Calculator calc;
    calc.add(10);
    calc.multiply(2);
    calc.add(5);
    cout << "Final result: " << calc.getResult() << endl;
    calc.reset();
    
    // calc.result = 100;  // 编译错误！result是private的
    
    cout << "\n=== 思考题答案 ===" << endl;
    cout << "1. struct适合：简单数据容器，成员主要是public" << endl;
    cout << "   class适合：需要封装、有复杂逻辑、需要保护数据完整性" << endl;
    cout << "2. 可以用class实现Point和Student，但习惯上用struct更合适" << endl;
    cout << "3. 可以用struct实现BankAccount，但需要显式写private，违背了struct的简单性" << endl;
    cout << "4. 默认访问权限影响代码的封装性和使用便利性" << endl;
    
    return 0;
} 