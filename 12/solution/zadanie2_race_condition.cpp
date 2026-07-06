// Задание 2. Гонка данных и три способа её устранения: без синхронизации,
// с мьютексом, с атомарной переменной.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
using namespace std;

// ---- Часть А: гонка данных ----
int sharedCounter = 0;

void incrementWithoutSync(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        sharedCounter++;  // НЕ атомарная операция: чтение-изменение-запись из разных потоков
    }
}

void task2a() {
    const int THREADS = 10;
    const int ITERATIONS = 10000;
    vector<thread> threads;

    sharedCounter = 0;

    for (int i = 0; i < THREADS; ++i) {
        threads.emplace_back(incrementWithoutSync, ITERATIONS);
    }
    for (auto& t : threads) t.join();

    int expected = THREADS * ITERATIONS;
    cout << "Ожидаемое значение: " << expected << endl;
    cout << "Фактическое значение: " << sharedCounter << endl;
    cout << "Потеряно: " << expected - sharedCounter << " инкрементов" << endl;
}

// ---- Часть Б: решение с мьютексом ----
mutex mtx;

void incrementWithMutex(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        lock_guard<mutex> lock(mtx);
        sharedCounter++;
    }
}

void task2b() {
    const int THREADS = 10;
    const int ITERATIONS = 10000;
    vector<thread> threads;

    sharedCounter = 0;

    for (int i = 0; i < THREADS; ++i) {
        threads.emplace_back(incrementWithMutex, ITERATIONS);
    }
    for (auto& t : threads) t.join();

    int expected = THREADS * ITERATIONS;
    cout << "Ожидаемое значение: " << expected << endl;
    cout << "Фактическое значение: " << sharedCounter << endl;
}

// ---- Часть В: решение с атомарной переменной ----
atomic<int> atomicCounter{0};

void incrementAtomic(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        atomicCounter++;
    }
}

void task2c() {
    const int THREADS = 10;
    const int ITERATIONS = 10000;
    vector<thread> threads;

    atomicCounter = 0;

    for (int i = 0; i < THREADS; ++i) {
        threads.emplace_back(incrementAtomic, ITERATIONS);
    }
    for (auto& t : threads) t.join();

    int expected = THREADS * ITERATIONS;
    cout << "Ожидаемое значение: " << expected << endl;
    cout << "Фактическое значение: " << atomicCounter << endl;
}

int main() {
    cout << "=== Гонка данных ===" << endl;
    task2a();

    cout << "\n=== Решение с мьютексом ===" << endl;
    task2b();

    cout << "\n=== Решение с атомарной переменной ===" << endl;
    task2c();

    return 0;
}
