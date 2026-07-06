// Задание 1. Базовые операции с vector.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v1;
    vector<int> v2(5, 10);
    vector<int> v3 = {1, 2, 3, 4, 5};
    vector<int> v4(v3.begin(), v3.end());

    cout << "v3: ";
    for (int x : v3) cout << x << " ";
    cout << endl;

    vector<int> v5;
    for (int i = 1; i <= 10; ++i) v5.push_back(i);
    cout << "v5: ";
    for (int x : v5) cout << x << " ";
    cout << endl;

    v5.pop_back();
    cout << "После pop_back(): ";
    for (int x : v5) cout << x << " ";
    cout << endl;

    cout << "Размер v5: " << v5.size() << endl;
    cout << "Вместимость v5: " << v5.capacity() << endl;
    cout << "Первый элемент: " << v5.front() << endl;
    cout << "Последний элемент: " << v5.back() << endl;

    v5.insert(v5.begin() + 3, 99);
    cout << "После вставки 99 на позицию 3: ";
    for (int x : v5) cout << x << " ";
    cout << endl;

    v5.erase(v5.begin() + 5);
    cout << "После удаления позиции 5: ";
    for (int x : v5) cout << x << " ";
    cout << endl;

    return 0;
}
