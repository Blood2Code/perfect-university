#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;

    int max = (a > b) ? a : b;
    cout << "Большее число: " << max;

    return 0;
}
