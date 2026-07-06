// Задание 4. Оптимизация с помощью предвычислений: префиксные суммы.
#include <iostream>
#include <vector>
using namespace std;

// Наивное вычисление суммы подмассива — O(n) на каждый запрос
int rangeSumNaive(const vector<int>& arr, int left, int right) {
    int sum = 0;
    for (int i = left; i <= right; i++) sum += arr[i];
    return sum;
}

// Предвычисление префиксных сумм — O(n) один раз на построение,
// затем O(1) на каждый последующий запрос.
class PrefixSum {
private:
    vector<int> prefix;  // prefix[i] = arr[0] + arr[1] + ... + arr[i-1]

public:
    PrefixSum(const vector<int>& arr) {
        prefix.resize(arr.size() + 1, 0);
        for (size_t i = 0; i < arr.size(); ++i) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
    }

    int getSum(int left, int right) const {
        // Сумма [left..right] = prefix[right+1] - prefix[left]
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Сумма [2..5] (ожидается 18): " << rangeSumNaive(arr, 2, 5) << endl;

    PrefixSum ps(arr);
    cout << "Сумма [2..5] (префиксная): " << ps.getSum(2, 5) << endl;

    cout << "Сумма [0..9] (ожидается 55): " << ps.getSum(0, 9) << endl;
    cout << "Сумма [7..7] (ожидается 8): " << ps.getSum(7, 7) << endl;

    return 0;
}
