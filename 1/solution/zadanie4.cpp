// Задание 4. Передача параметров в функцию по адресу
#include <iostream>
using namespace std;

void change(int *x) {
    *x = 100;
}

int main() {
    int a = 10;

    change(&a);

    cout << "Новое значение a: " << a << endl;

    return 0;
}
