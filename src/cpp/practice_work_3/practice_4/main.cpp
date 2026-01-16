#include <iostream>
using namespace std;

int main() {
    double c;
    cout << "Введите температуру в Цельсиях: ";
    cin >> c;

    double f = c * 9.0 / 5.0 + 32;
    cout << "Температура в Фаренгейтах: " << f;
    return 0;
}
