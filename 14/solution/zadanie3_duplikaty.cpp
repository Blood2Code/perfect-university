// Задание 3. Поиск дубликатов в массиве: три версии разной сложности.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// Версия 1: O(n^2) — перебор всех пар
bool hasDuplicatesNaive(const vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

// Версия 2: O(n log n) — сортировка + линейный проход по соседним элементам
bool hasDuplicatesSort(vector<int> arr) {
    sort(arr.begin(), arr.end());
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) return true;
    }
    return false;
}

// Версия 3: O(n) в среднем — хэш-таблица unordered_set
bool hasDuplicatesHash(const vector<int>& arr) {
    unordered_set<int> seen;
    seen.reserve(arr.size());
    for (int x : arr) {
        if (!seen.insert(x).second) return true;  // insert вернул false — уже было
    }
    return false;
}

int main() {
    vector<int> arr(10000);
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 5000;  // высокая вероятность дубликатов
    }

    auto t0 = high_resolution_clock::now();
    bool r1 = hasDuplicatesNaive(arr);
    auto t1 = high_resolution_clock::now();
    bool r2 = hasDuplicatesSort(arr);
    auto t2 = high_resolution_clock::now();
    bool r3 = hasDuplicatesHash(arr);
    auto t3 = high_resolution_clock::now();

    auto timeNaive = duration_cast<microseconds>(t1 - t0).count();
    auto timeSort  = duration_cast<microseconds>(t2 - t1).count();
    auto timeHash  = duration_cast<microseconds>(t3 - t2).count();

    cout << "Наивная (O(n^2)):      " << (r1 ? "найдены" : "не найдены") << ", время: " << timeNaive << " мкс" << endl;
    cout << "Сортировка (O(n log n)): " << (r2 ? "найдены" : "не найдены") << ", время: " << timeSort << " мкс" << endl;
    cout << "Хэш-таблица (O(n)):    " << (r3 ? "найдены" : "не найдены") << ", время: " << timeHash << " мкс" << endl;

    return 0;
}
