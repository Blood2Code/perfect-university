// Задание 4. Копирование последовательностей: copy, copy_if, copy_n, transform.
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

void partA() {
    vector<int> src = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> dest(10);

    cout << "Исходный вектор: ";
    for (int x : src) cout << x << " ";
    cout << endl;

    copy(src.begin(), src.end(), dest.begin());
    cout << "После copy: ";
    for (int x : dest) cout << x << " ";
    cout << endl;

    vector<int> destEven;
    copy_if(src.begin(), src.end(), back_inserter(destEven), [](int x) { return x % 2 == 0; });
    cout << "Чётные числа: ";
    for (int x : destEven) cout << x << " ";
    cout << endl;

    vector<int> firstFive(5);
    copy_n(src.begin(), 5, firstFive.begin());
    cout << "Первые 5 элементов: ";
    for (int x : firstFive) cout << x << " ";
    cout << endl;

    vector<int> greaterThan50;
    copy_if(src.begin(), src.end(), back_inserter(greaterThan50), [](int x) { return x > 50; });
    cout << "Числа > 50: ";
    for (int x : greaterThan50) cout << x << " ";
    cout << endl;
}

void partB() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> squares(5);

    transform(numbers.begin(), numbers.end(), squares.begin(), [](int x) { return x * x; });
    cout << "\nКвадраты чисел: ";
    for (int x : squares) cout << x << " ";
    cout << endl;

    vector<string> names = {"Alice", "Bob", "Charlie", "David"};
    vector<string> upperNames(names.size());

    transform(names.begin(), names.end(), upperNames.begin(), [](string s) {
        for (char& c : s) c = toupper(c);
        return s;
    });
    cout << "Имена в верхнем регистре: ";
    for (const auto& name : upperNames) cout << name << " ";
    cout << endl;

    vector<int> src = {1, 2, 3, 4, 5};
    list<int> destList;
    copy(src.begin(), src.end(), back_inserter(destList));
    cout << "Список из вектора: ";
    for (int x : destList) cout << x << " ";
    cout << endl;
}

int main() {
    partA();
    partB();
    return 0;
}
