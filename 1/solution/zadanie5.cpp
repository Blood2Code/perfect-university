// Задание 5. Передача параметров по ссылке
#include <iostream>
using namespace std;

void change(int &x) {
    x = 50;
}

int main() {
    int a = 10;

    change(a);

    cout << "Новое значение a: " << a << endl;

    return 0;
}
