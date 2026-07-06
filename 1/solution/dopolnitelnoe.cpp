// Дополнительное задание.
// Вводим два числа с клавиатуры, меняем их местами через указатели.
#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    cout << "Введите первое число: ";
    cin >> x;
    cout << "Введите второе число: ";
    cin >> y;

    cout << "До обмена: x = " << x << ", y = " << y << endl;

    swap(&x, &y);

    cout << "После обмена: x = " << x << ", y = " << y << endl;

    return 0;
}
