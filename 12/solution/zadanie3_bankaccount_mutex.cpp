// Задание 3, часть А. Защита разделяемого ресурса (BankAccount) мьютексом.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

class BankAccount {
private:
    double balance;
    mutable mutex mtx;

public:
    BankAccount(double initial) : balance(initial) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма пополнения должна быть положительной!" << endl;
            return;
        }

        lock_guard<mutex> lock(mtx);

        balance += amount;
        cout << "Пополнение на " << amount << ", новый баланс: " << balance << endl;

        this_thread::sleep_for(chrono::milliseconds(10));
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть положительной!" << endl;
            return false;
        }

        lock_guard<mutex> lock(mtx);

        if (balance >= amount) {
            balance -= amount;
            cout << "Снятие " << amount << ", новый баланс: " << balance << endl;
            return true;
        } else {
            cout << "Недостаточно средств! Баланс: " << balance << ", запрошено: " << amount << endl;
            return false;
        }
    }

    double getBalance() const {
        lock_guard<mutex> lock(mtx);
        return balance;
    }
};

void task3a() {
    BankAccount account(1000);
    vector<thread> threads;

    threads.emplace_back([&account]() { account.deposit(500); });
    threads.emplace_back([&account]() { account.deposit(300); });
    threads.emplace_back([&account]() { account.withdraw(200); });
    threads.emplace_back([&account]() { account.withdraw(700); });
    threads.emplace_back([&account]() { account.deposit(100); });

    for (auto& t : threads) t.join();

    cout << "Итоговый баланс: " << account.getBalance() << endl;
}

int main() {
    task3a();
    return 0;
}
