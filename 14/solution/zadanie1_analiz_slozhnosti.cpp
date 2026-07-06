// Задание 1. Определение сложности алгоритмов (с ответами в комментариях).
#include <iostream>
using namespace std;

// Фрагмент 1
void fragment1(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
    // Сложность: O(n) — один цикл, n итераций.
    cout << "fragment1: sum = " << sum << endl;
}

// Фрагмент 2
void fragment2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Тело O(1)
        }
    }
    // Сложность: O(n^2) — два независимых вложенных цикла по n (умножение сложностей).
    cout << "fragment2: обработано " << n << "x" << n << " пар" << endl;
}

// Фрагмент 3
void fragment3(int n) {
    long long pairs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            pairs++;
        }
    }
    // Сложность: O(n^2) — внутренний цикл укорачивается с ростом i, но
    // суммарное число итераций n + (n-1) + ... + 1 = n(n+1)/2, что всё
    // ещё квадратичный порядок роста (константа 1/2 отбрасывается в O-нотации).
    cout << "fragment3: пар = " << pairs << endl;
}

// Фрагмент 4
void fragment4(int n) {
    int i = 1;
    int steps = 0;
    while (i < n) {
        i = i * 2;
        steps++;
    }
    // Сложность: O(log n) — i растёт геометрически (удваивается), поэтому
    // число шагов до превышения n равно log2(n).
    cout << "fragment4: шагов = " << steps << endl;
}

// Фрагмент 5
void fragment5(int n) {
    long long triples = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                triples++;
            }
        }
    }
    // Сложность: O(n^3) — три вложенных независимых цикла по n.
    cout << "fragment5: троек = " << triples << endl;
}

// Фрагмент 6
long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
// Сложность: O(n) — n последовательных рекурсивных вызовов
// (не путать с экспоненциальной рекурсией Фибоначчи из Задания 5:
// здесь каждый вызов порождает ровно один следующий вызов, а не два).

// ---- Часть Б. Сравнение алгоритмов поиска максимума ----

int findMaxA(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}
// Сложность findMaxA: O(n) — один проход по массиву.

int findMaxB(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > maxVal) maxVal = arr[j];
        }
    }
    return maxVal;
}
// Сложность findMaxB: O(n^2) — вложенные циклы, избыточное сравнение
// всех пар, хотя для поиска максимума это не нужно.
//
// Вывод: Алгоритм A строго лучше алгоритма B — они решают одну и ту же
// задачу (найти максимум), но A делает это за линейное время, а B —
// за квадратичное, не давая взамен никакой дополнительной информации.
// Это пример того, что более сложный код не всегда эффективнее: B просто
// избыточен.

int main() {
    int arr[] = {5, 3, 9, 1, 7, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    fragment1(n);
    fragment2(n);
    fragment3(n);
    fragment4(20);
    fragment5(n);

    cout << "factorial(6) = " << factorial(6) << endl;

    cout << "findMaxA = " << findMaxA(arr, n) << endl;
    cout << "findMaxB = " << findMaxB(arr, n) << endl;

    return 0;
}
