// Задание 5, часть В. Обработка массива оценок.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
    vector<int> grades = {85, 92, 78, 90, 88, 76, 95, 89, 84, 91, 87, 93, 79, 82};

    cout << "Оценки: ";
    for (int g : grades) cout << g << " ";
    cout << endl;

    // 1. Сортировка по убыванию
    sort(grades.begin(), grades.end(), greater<int>());
    cout << "Отсортированные по убыванию: ";
    for (int g : grades) cout << g << " ";
    cout << endl;

    // 2. Количество отличников (>= 90)
    int excellentCount = count_if(grades.begin(), grades.end(), [](int g) { return g >= 90; });
    cout << "Количество отличников (>=90): " << excellentCount << endl;

    // 3. Средний балл через accumulate
    double average = accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
    cout << "Средний балл: " << average << endl;

    // 4. Первая неудовлетворительная оценка (< 60)
    auto it = find_if(grades.begin(), grades.end(), [](int g) { return g < 60; });
    if (it != grades.end()) {
        cout << "Найдена неудовлетворительная оценка: " << *it << endl;
    } else {
        cout << "Все оценки удовлетворительные" << endl;
    }

    // 5. Оценки выше среднего
    vector<int> aboveAverage;
    copy_if(grades.begin(), grades.end(), back_inserter(aboveAverage),
            [average](int g) { return g > average; });

    cout << "Оценки выше среднего: ";
    for (int g : aboveAverage) cout << g << " ";
    cout << endl;

    return 0;
}
