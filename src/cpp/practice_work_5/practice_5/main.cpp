#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;

    if (n == 0) {
        cout << "Количество цифр: 1";
        return 0;
    }

    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }

    cout << "Количество цифр: " << count;
    return 0;
}
