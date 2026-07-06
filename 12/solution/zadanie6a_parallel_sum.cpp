// Задание 6, часть А. Параллельное вычисление суммы массива.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
using namespace std;

class ParallelSumCalculator {
private:
    vector<int> data;
    int numThreads;
    mutex mtx;
    long long totalSum;

    void calculatePart(int start, int end, long long& localSum) {
        localSum = 0;
        for (int i = start; i < end; ++i) localSum += data[i];

        lock_guard<mutex> lock(mtx);
        totalSum += localSum;
    }

public:
    ParallelSumCalculator(const vector<int>& arr, int threads = 4)
        : data(arr), numThreads(threads), totalSum(0) {}

    long long compute() {
        totalSum = 0;
        int n = data.size();
        int chunkSize = n / numThreads;
        vector<thread> threads;
        vector<long long> partialSums(numThreads, 0);

        for (int i = 0; i < numThreads; ++i) {
            int start = i * chunkSize;
            int end = (i == numThreads - 1) ? n : start + chunkSize;
            threads.emplace_back(&ParallelSumCalculator::calculatePart, this, start, end, ref(partialSums[i]));
        }

        for (auto& t : threads) t.join();

        return totalSum;
    }

    long long computeSequential() {
        long long sum = 0;
        for (int val : data) sum += val;
        return sum;
    }
};

int main() {
    vector<int> arr(1000000);
    for (size_t i = 0; i < arr.size(); ++i) arr[i] = i;

    ParallelSumCalculator calculator(arr, 4);

    auto start = chrono::high_resolution_clock::now();
    long long parallelSum = calculator.compute();
    auto end = chrono::high_resolution_clock::now();
    auto parallelTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    long long sequentialSum = calculator.computeSequential();
    end = chrono::high_resolution_clock::now();
    auto sequentialTime = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "Последовательная сумма: " << sequentialSum
         << ", время: " << sequentialTime << " мс" << endl;
    cout << "Параллельная сумма: " << parallelSum
         << ", время: " << parallelTime << " мс" << endl;

    if (parallelTime > 0) {
        cout << "Ускорение: " << (double)sequentialTime / parallelTime << "x" << endl;
    }

    return 0;
}
