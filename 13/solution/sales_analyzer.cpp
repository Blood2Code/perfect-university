// Самостоятельная работа: "Разработка системы анализа больших данных
// с использованием STL и многопоточности".
//
// Демонстрационный проект: анализ большого массива транзакций
// интернет-магазина (категория товара, сумма покупки, регион).
// Система считает статистику по категориям (выручка, средний чек,
// максимальный чек) как последовательно, так и параллельно (по схеме
// MapReduce: каждый поток строит свою локальную статистику без
// синхронизации, а результаты объединяются один раз в конце), после
// чего сравнивает время выполнения обоих подходов.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <thread>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <random>
using namespace std;
using namespace chrono;

struct Transaction {
    string category;
    double amount;
};

struct CategoryStats {
    double totalRevenue = 0.0;
    long long count = 0;
    double maxAmount = 0.0;

    void add(double amount) {
        totalRevenue += amount;
        ++count;
        if (amount > maxAmount) maxAmount = amount;
    }

    // Слияние статистики другого потока в текущую (шаг "reduce")
    void merge(const CategoryStats& other) {
        totalRevenue += other.totalRevenue;
        count += other.count;
        if (other.maxAmount > maxAmount) maxAmount = other.maxAmount;
    }

    double average() const { return count == 0 ? 0.0 : totalRevenue / count; }
};

using StatsMap = unordered_map<string, CategoryStats>;

// Генерация синтетического набора "больших данных" (фиксированное зерно —
// для воспроизводимости результатов между запусками).
vector<Transaction> generateData(size_t n) {
    static const vector<string> categories = {
        "Электроника", "Одежда", "Книги", "Продукты", "Спорттовары", "Игрушки"
    };

    mt19937 rng(42);
    uniform_int_distribution<size_t> categoryDist(0, categories.size() - 1);
    uniform_real_distribution<double> amountDist(50.0, 50000.0);

    vector<Transaction> data;
    data.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        data.push_back({categories[categoryDist(rng)], amountDist(rng)});
    }
    return data;
}

// Последовательный анализ: один проход по всем данным.
StatsMap analyzeSequential(const vector<Transaction>& data) {
    StatsMap stats;
    for (const auto& t : data) {
        stats[t.category].add(t.amount);
    }
    return stats;
}

// Параллельный анализ: данные делятся на equal-размерные части,
// каждый поток строит СВОЮ локальную StatsMap (без блокировок — гонки
// данных нет, потому что потоки не разделяют память на этапе подсчёта),
// а объединение (merge) происходит один раз, уже в основном потоке.
StatsMap analyzeParallel(const vector<Transaction>& data, unsigned numThreads) {
    size_t n = data.size();
    size_t chunkSize = n / numThreads;

    vector<thread> threads;
    vector<StatsMap> localStats(numThreads);

    for (unsigned i = 0; i < numThreads; ++i) {
        size_t start = i * chunkSize;
        size_t end = (i == numThreads - 1) ? n : start + chunkSize;

        threads.emplace_back([&data, &localStats, i, start, end]() {
            for (size_t j = start; j < end; ++j) {
                localStats[i][data[j].category].add(data[j].amount);
            }
        });
    }

    for (auto& t : threads) t.join();

    // Этап reduce: объединяем локальные карты статистики в одну общую.
    StatsMap result;
    for (const auto& local : localStats) {
        for (const auto& [category, catStats] : local) {
            result[category].merge(catStats);
        }
    }
    return result;
}

void printReport(const StatsMap& stats, double elapsedMs, const string& label) {
    // Копируем в vector для сортировки по выручке (STL-алгоритм sort,
    // см. практическую работу про STL-алгоритмы).
    vector<pair<string, CategoryStats>> sorted(stats.begin(), stats.end());
    sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
        return a.second.totalRevenue > b.second.totalRevenue;
    });

    cout << "\n=== " << label << " (время: " << elapsedMs << " мс) ===" << endl;
    for (const auto& [category, s] : sorted) {
        cout << "  " << category
             << ": выручка = " << (long long)s.totalRevenue
             << ", чеков = " << s.count
             << ", средний чек = " << (long long)s.average()
             << ", макс. чек = " << (long long)s.maxAmount << endl;
    }

    double grandTotal = accumulate(sorted.begin(), sorted.end(), 0.0,
        [](double sum, const auto& p) { return sum + p.second.totalRevenue; });
    cout << "  ИТОГО по всем категориям: " << (long long)grandTotal << endl;
}

int main() {
    const size_t DATA_SIZE = 5'000'000;
    unsigned numThreads = thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4;

    cout << "Генерация " << DATA_SIZE << " транзакций..." << endl;
    vector<Transaction> data = generateData(DATA_SIZE);
    cout << "Данные готовы. Используем " << numThreads << " потоков для параллельного анализа." << endl;

    auto start = high_resolution_clock::now();
    StatsMap seqStats = analyzeSequential(data);
    auto end = high_resolution_clock::now();
    double seqTime = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    StatsMap parStats = analyzeParallel(data, numThreads);
    end = high_resolution_clock::now();
    double parTime = duration_cast<milliseconds>(end - start).count();

    printReport(seqStats, seqTime, "Последовательный анализ");
    printReport(parStats, parTime, "Параллельный анализ");

    cout << "\n=== Сравнение производительности ===" << endl;
    cout << "Последовательно: " << seqTime << " мс" << endl;
    cout << "Параллельно (" << numThreads << " потоков): " << parTime << " мс" << endl;
    if (parTime > 0) {
        cout << "Ускорение: " << (seqTime / parTime) << "x" << endl;
    }

    return 0;
}
