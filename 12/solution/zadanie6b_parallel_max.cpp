// Задание 6, часть Б. Многопоточный поиск максимального элемента.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <chrono>
using namespace std;

class ParallelMaxFinder {
private:
    vector<int> data;
    int numThreads;
    mutex mtx;
    int globalMax;

    void findMaxPart(int start, int end) {
        int localMax = data[start];
        for (int i = start + 1; i < end; ++i) {
            if (data[i] > localMax) localMax = data[i];
        }

        lock_guard<mutex> lock(mtx);
        if (localMax > globalMax) globalMax = localMax;
    }

public:
    ParallelMaxFinder(const vector<int>& arr, int threads = 4)
        : data(arr), numThreads(threads), globalMax(arr[0]) {}

    int findMax() {
        globalMax = data[0];
        int n = data.size();
        int chunkSize = n / numThreads;
        vector<thread> threads;

        for (int i = 0; i < numThreads; ++i) {
            int start = i * chunkSize;
            int end = (i == numThreads - 1) ? n : start + chunkSize;
            threads.emplace_back(&ParallelMaxFinder::findMaxPart, this, start, end);
        }

        for (auto& t : threads) t.join();

        return globalMax;
    }

    int findMaxSequential() {
        return *max_element(data.begin(), data.end());
    }
};

int main() {
    vector<int> arr(1000000);
    for (size_t i = 0; i < arr.size(); ++i) arr[i] = i;
    arr[999999] = 10000000;

    ParallelMaxFinder finder(arr, 4);

    auto start = chrono::high_resolution_clock::now();
    int parallelMax = finder.findMax();
    auto end = chrono::high_resolution_clock::now();
    auto parallelTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    int sequentialMax = finder.findMaxSequential();
    end = chrono::high_resolution_clock::now();
    auto sequentialTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Последовательный максимум: " << sequentialMax
         << ", время: " << sequentialTime << " мс" << endl;
    cout << "Параллельный максимум: " << parallelMax
         << ", время: " << parallelTime << " мс" << endl;

    return 0;
}
