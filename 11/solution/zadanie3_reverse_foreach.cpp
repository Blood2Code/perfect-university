// Задание 3. Разворот последовательности и применение функции ко всем элементам.
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Исходный вектор: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    reverse(v.begin(), v.end());
    cout << "После reverse: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "Квадраты чисел: ";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x * x << " ";
    });
    cout << endl;

    // Параметр по ссылке: for_each должен изменить сами элементы вектора
    for_each(v.begin(), v.end(), [](int& x) {
        x += 1;
    });

    cout << "После увеличения на 1: ";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    list<int> lst = {10, 20, 30, 40, 50};

    cout << "Список: ";
    for_each(lst.begin(), lst.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    reverse(lst.begin(), lst.end());
    cout << "После разворота списка: ";
    for_each(lst.begin(), lst.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    return 0;
}
