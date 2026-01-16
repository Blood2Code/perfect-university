#include <iostream>
using namespace std;

int main() {
    int hour;
    cout << "Введите час (0-23): ";
    cin >> hour;

    if (hour >= 0 && hour <= 5)
        cout << "Ночь";
    else if (hour <= 11)
        cout << "Утро";
    else if (hour <= 17)
        cout << "День";
    else if (hour <= 23)
        cout << "Вечер";
    else
        cout << "Неверный ввод";

    return 0;
}
