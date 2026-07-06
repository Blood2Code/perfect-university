// Задание 3, часть Б. Сравнение производительности мьютекса и атомарных операций.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <chrono>
using namespace std;
using namespace chrono;

const int THREADS = 4;
const int ITERATIONS = 1000000;

void testMutex() {
    int counter = 0;
    mutex mtx;
    auto start = high_resolution_clock::now();

    vector<thread> threads;
    for (int i = 0; i < THREADS; ++i) {
        threads.emplace_back([&counter, &mtx]() {
            for (int j = 0; j < ITERATIONS; ++j) {
                lock_guard<mutex> lock(mtx);
                counter++;
            }
        });
    }
    for (auto& t : threads) t.join();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Мьютекс: " << duration << " мс, результат: " << counter << endl;
}

void testAtomic() {
    atomic<int> counter{0};
    auto start = high_resolution_clock::now();

    vector<thread> threads;
    for (int i = 0; i < THREADS; ++i) {
        threads.emplace_back([&counter]() {
            for (int j = 0; j < ITERATIONS; ++j) {
                counter++;
            }
        });
    }
    for (auto& t : threads) t.join();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    cout << "Атомарный: " << duration << " мс, результат: " << counter << endl;
}

int main() {
    cout << "=== Сравнение производительности ===" << endl;
    testMutex();
    testAtomic();

    return 0;
}
