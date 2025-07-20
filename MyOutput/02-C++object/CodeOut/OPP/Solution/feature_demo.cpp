// Solution for 面向对象三大特性综合练习
#include <iostream>
#include <string>
using namespace std;

// 1. Encapsulation
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds" << endl;
    }
    double getBalance() const
    {
        return balance;
    }
};

// 2. Inheritance
class Animal
{
public:
    virtual void makeSound() const
    {
        cout << "Animal sound" << endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() const override
    {
        cout << "Meow!" << endl;
    }
};

int main()
{
    // Encapsulation demo
    BankAccount acc(100.0);
    acc.deposit(50.0);
    acc.withdraw(30.0);
    cout << "Balance: " << acc.getBalance() << endl;
    // acc.balance = 1000; // Uncommenting this line will cause a compile error

    // Inheritance demo
    Dog d;
    Cat c;
    d.makeSound();
    c.makeSound();

    // Polymorphism demo
    Animal *p;
    p = &d;
    p->makeSound(); // Woof!
    p = &c;
    p->makeSound(); // Meow!
    return 0;
}