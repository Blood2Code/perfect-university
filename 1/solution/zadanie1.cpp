// Задание 1. Работа с указателями
// Объявляем переменную и указатель на неё, выводим адрес и значение.
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p;

    p = &a;

    cout << "Значение переменной a: " << a << endl;
    cout << "Адрес переменной a: " << &a << endl;
    cout << "Значение указателя p: " << p << endl;
    cout << "Значение по адресу p: " << *p << endl;

    return 0;
}
