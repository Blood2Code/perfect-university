#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Введите число: ";
    cin >> x;

    if (x > 0) {
        cout << "Число положительное, ";
    } else {
        cout << "Число отрицательное или равно нулю, ";
    }

    if (x % 2 == 0) {
        cout << "четное";
    } else {
        cout << "нечетное";
    }

    return 0;
}
