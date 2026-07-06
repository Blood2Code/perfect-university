// Задание 1. Сортировка и поиск в векторе.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};

    cout << "Исходный вектор: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end());
    cout << "После сортировки по возрастанию: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    auto it = find(v.begin(), v.end(), 7);
    if (it != v.end()) {
        cout << "Элемент 7 найден на позиции " << (it - v.begin()) << endl;
    } else {
        cout << "Элемент 7 не найден" << endl;
    }

    sort(v.begin(), v.end(), greater<int>());
    cout << "После сортировки по убыванию: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    auto it10 = find(v.begin(), v.end(), 10);
    if (it10 != v.end()) {
        cout << "Число 10 найдено" << endl;
    } else {
        cout << "Число 10 не найдено" << endl;
    }

    return 0;
}
