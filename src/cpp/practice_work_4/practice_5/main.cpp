#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Меню:\n";
    cout << "1 - Приветствие\n";
    cout << "2 - Текущий год\n";
    cout << "3 - Выход\n";
    cout << "Введите номер: ";
    cin >> choice;

    switch (choice) {
        case 1: cout << "Здравствуйте!"; break;
        case 2: cout << "Текущий год: 2025"; break;
        case 3: cout << "Выход из программы"; break;
        default: cout << "Ошибка: нет такого пункта";
    }

    return 0;
}
