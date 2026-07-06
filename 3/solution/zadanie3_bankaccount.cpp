// Задание 3. Класс BankAccount — инкапсуляция и валидация данных.
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(const string& number, const string& name, double initialBalance)
        : accountNumber(number), ownerName(name) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Ошибка: начальный баланс не может быть отрицательным. Установлен 0." << endl;
        }
        cout << "Создан счет: " << accountNumber << " (" << ownerName << ")" << endl;
    }

    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Пополнение на " << amount << ". Новый баланс: " << balance << endl;
        } else {
            cout << "Ошибка: сумма пополнения должна быть положительной!" << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть положительной!" << endl;
            return false;
        }
        if (amount <= balance) {
            balance -= amount;
            cout << "Снятие " << amount << ". Новый баланс: " << balance << endl;
            return true;
        }
        cout << "Ошибка: недостаточно средств! Баланс: " << balance
             << ", запрошено: " << amount << endl;
        return false;
    }

    void display() const {
        cout << "Счет: " << accountNumber
             << ", владелец: " << ownerName
             << ", баланс: " << balance << endl;
    }
};

int main() {
    cout << "=== Создание счетов ===" << endl;
    BankAccount acc1("1234567890", "Иванов Иван", 1000);
    BankAccount acc2("0987654321", "Петрова Мария", 500);

    cout << "\n=== Информация о счетах ===" << endl;
    acc1.display();
    acc2.display();

    cout << "\n=== Операции со счетом acc1 ===" << endl;
    acc1.deposit(500);
    acc1.withdraw(200);
    acc1.withdraw(2000);
    acc1.deposit(-100);

    cout << "\n=== Перевод между счетами ===" << endl;
    double transferAmount = 300;
    if (acc1.withdraw(transferAmount)) {
        acc2.deposit(transferAmount);
        cout << "Переведено " << transferAmount << " от "
             << acc1.getOwnerName() << " к " << acc2.getOwnerName() << endl;
    }

    cout << "\n=== Итоговое состояние счетов ===" << endl;
    acc1.display();
    acc2.display();

    return 0;
}
