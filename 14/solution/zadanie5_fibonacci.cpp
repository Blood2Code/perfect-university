// Задание 5. Пространственная vs временная сложность: числа Фибоначчи.
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// 1. Рекурсивный (экспоненциальный)
// Сложность: O(2^n) по времени, O(n) по памяти (глубина стека рекурсии).
long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// 2. Итеративный (линейный)
// Сложность: O(n) по времени, O(1) по памяти (три переменные).
long long fibIterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// 3. Динамическое программирование с массивом
// Сложность: O(n) по времени, O(n) по памяти (весь массив dp).
long long fibDP(int n) {
    if (n <= 1) return n;
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    cout << "Метод\t\tВременная сложность\tПространственная сложность" << endl;
    cout << "Рекурсивный\tO(2^n)\t\t\tO(n)" << endl;
    cout << "Итеративный\tO(n)\t\t\tO(1)" << endl;
    cout << "DP с массивом\tO(n)\t\t\tO(n)" << endl;

    // volatile мешает компилятору вычислить fibRecursive(n) на этапе
    // компиляции (constant folding при -O2) — иначе результат был бы
    // просто "вшит" в бинарник, и замер показал бы 0 мкс.
    volatile int nRuntime = 30;
    int n = nRuntime;

    auto t0 = high_resolution_clock::now();
    long long r1 = fibRecursive(n);
    auto t1 = high_resolution_clock::now();
    long long r2 = fibIterative(n);
    auto t2 = high_resolution_clock::now();
    long long r3 = fibDP(n);
    auto t3 = high_resolution_clock::now();

    cout << "\nfib(" << n << "):" << endl;
    cout << "Рекурсивный:  " << r1 << ", время: " << duration_cast<microseconds>(t1 - t0).count() << " мкс" << endl;
    cout << "Итеративный:  " << r2 << ", время: " << duration_cast<microseconds>(t2 - t1).count() << " мкс" << endl;
    cout << "DP с массивом: " << r3 << ", время: " << duration_cast<microseconds>(t3 - t2).count() << " мкс" << endl;

    cout << "\nЛучший по времени: итеративный и DP (одинаково O(n), рекурсивный на порядки медленнее)." << endl;
    cout << "Лучший по памяти: итеративный (O(1), в отличие от O(n) у DP и рекурсии)." << endl;
    cout << "Оптимален по времени И памяти одновременно: итеративный метод." << endl;

    return 0;
}
