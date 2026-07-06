// Задание 6. Поиск двух чисел с заданной суммой: три версии разной сложности.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Версия 1: O(n^2)
pair<int, int> findSumNaive(const vector<int>& arr, int target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return {arr[i], arr[j]};
        }
    }
    return {-1, -1};
}

// Версия 2: O(n) с использованием хэш-таблицы
pair<int, int> findSumHash(const vector<int>& arr, int target) {
    unordered_map<int, bool> seen;
    for (int x : arr) {
        int complement = target - x;
        if (seen.count(complement)) return {complement, x};
        seen[x] = true;
    }
    return {-1, -1};
}

// Версия 3: O(n log n) с использованием сортировки и двух указателей
pair<int, int> findSumTwoPointers(vector<int> arr, int target) {  // передаём копию для сортировки
    sort(arr.begin(), arr.end());
    int left = 0, right = (int)arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return {arr[left], arr[right]};
        if (sum < target) ++left;
        else --right;
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {2, 7, 11, 15, 3, 6, 8, 1};
    int target = 9;

    auto result1 = findSumNaive(arr, target);
    cout << "Наивный метод: " << result1.first << " + " << result1.second << " = " << target << endl;

    auto result2 = findSumHash(arr, target);
    cout << "Хэш-таблица:   " << result2.first << " + " << result2.second << " = " << target << endl;

    auto result3 = findSumTwoPointers(arr, target);
    cout << "Два указателя: " << result3.first << " + " << result3.second << " = " << target << endl;

    return 0;
}
