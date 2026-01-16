#include <iostream>
using namespace std;

int main() {
    int x;
    do {
        cout << "Введите число (0 для выхода): ";
        cin >> x;
    } while (x != 0);

    cout << "Программа завершена";
    return 0;
}
