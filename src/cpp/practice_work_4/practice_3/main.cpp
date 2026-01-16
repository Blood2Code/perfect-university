#include <iostream>
using namespace std;

int main() {
    int grade;
    cout << "Введите оценку (1-5): ";
    cin >> grade;

    switch (grade) {
        case 5: cout << "Отлично"; break;
        case 4: cout << "Хорошо"; break;
        case 3: cout << "Удовлетворительно"; break;
        case 2: cout << "Неудовлетворительно"; break;
        case 1: cout << "Очень плохо"; break;
        default: cout << "Неверный ввод";
    }

    return 0;
}
