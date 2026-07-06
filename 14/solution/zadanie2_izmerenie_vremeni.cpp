// Задание 2. Измерение времени выполнения алгоритмов разной сложности.
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace chrono;

template<typename Func>
long long measureTime(Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

// O(n) — линейный поиск
int linearSearch(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// O(n^2) — пузырьковая сортировка
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// O(n log n) — быстрая сортировка
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    quickSort(arr, left, i);
    quickSort(arr, i + 2, right);
}

int main() {
    vector<int> sizes = {1000, 2000, 5000, 10000};

    cout << "=== Измерение времени выполнения ===" << endl;
    cout << "Размер\tЛинейный поиск (мкс)\tПузырьковая (мкс)\tБыстрая (мкс)" << endl;

    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % n;
        }

        long long timeLinear = measureTime([&]() {
            linearSearch(arr, n + 1);
        });

        vector<int> arrCopy = arr;
        long long timeBubble = measureTime([&]() {
            bubbleSort(arrCopy);
        });

        arrCopy = arr;
        long long timeQuick = measureTime([&]() {
            quickSort(arrCopy, 0, n - 1);
        });

        cout << n << "\t" << timeLinear << "\t\t" << timeBubble << "\t\t" << timeQuick << endl;
    }

    return 0;
}

// Ответы на вопросы части Б смотрите в файле tushuntirish.md — там
// приведена таблица с реальными результатами замеров на этой машине и
// анализ роста времени выполнения относительно теоретической сложности.
