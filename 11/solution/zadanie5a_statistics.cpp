// Задание 5, часть А. Статистика чисел: сортировка, медиана, уникальные,
// самый частый элемент, разворот.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6, 2, 5, 8, 3, 9, 1};

    cout << "Вектор: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // 1. Сортировка
    sort(v.begin(), v.end());
    cout << "Отсортированный: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // 2. Медиана (средний элемент отсортированного вектора)
    double median;
    size_t n = v.size();
    if (n % 2 == 0) median = (v[n / 2 - 1] + v[n / 2]) / 2.0;
    else median = v[n / 2];
    cout << "Медиана: " << median << endl;

    // 3. Количество уникальных элементов (unique переставляет дубликаты в
    // конец и возвращает итератор на новый логический конец диапазона)
    vector<int> vUnique = v;
    auto lastUnique = unique(vUnique.begin(), vUnique.end());
    int uniqueCount = distance(vUnique.begin(), lastUnique);
    cout << "Количество уникальных элементов: " << uniqueCount << endl;

    // 4. Самый часто встречающийся элемент (вектор уже отсортирован,
    // поэтому одинаковые элементы стоят подряд — считаем длину каждой серии)
    int mostFrequent = v[0], bestCount = 0, curCount = 0, curValue = v[0];
    for (int x : v) {
        if (x == curValue) {
            ++curCount;
        } else {
            curValue = x;
            curCount = 1;
        }
        if (curCount > bestCount) {
            bestCount = curCount;
            mostFrequent = curValue;
        }
    }
    cout << "Самый частый элемент: " << mostFrequent << " (встречается " << bestCount << " раз)" << endl;

    // 5. Разворот
    reverse(v.begin(), v.end());
    cout << "После разворота: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
