// Задание 3. Использование ссылок для изменения значения переменной
#include <iostream>
using namespace std;

int main() {
    int a = 15;
    int &b = a;

    b = 30;

    cout << "Значение переменной a: " << a << endl;

    return 0;
}
