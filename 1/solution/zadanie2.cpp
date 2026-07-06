// Задание 2. Изменение значения переменной через указатель
#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int *p;

    p = &a;
    *p = 20;

    cout << "Новое значение переменной a: " << a << endl;

    return 0;
}
