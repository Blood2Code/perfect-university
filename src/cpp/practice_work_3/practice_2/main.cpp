#include <iostream>
using namespace std;

int main() {
    int year;
    cout << "Введите год рождения: ";
    cin >> year;

    int age = 2025 - year;
    cout << "Ваш возраст: " << age;
    return 0;
}
