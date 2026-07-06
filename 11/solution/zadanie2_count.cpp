// Задание 2. Подсчёт элементов: count и count_if.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void partA() {
    vector<int> v = {1, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 2, 8, 2, 9};

    cout << "Вектор: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    int countTwo = count(v.begin(), v.end(), 2);
    cout << "Количество двоек: " << countTwo << endl;

    int evenCount = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    cout << "Количество чётных чисел: " << evenCount << endl;

    int greaterThanFive = count_if(v.begin(), v.end(), [](int x) { return x > 5; });
    cout << "Количество чисел > 5: " << greaterThanFive << endl;

    int inRange = count_if(v.begin(), v.end(), [](int x) { return x >= 3 && x <= 7; });
    cout << "Количество чисел в [3, 7]: " << inRange << endl;
}

void partB() {
    vector<string> words = {"apple", "banana", "cat", "dog", "elephant", "fox", "grape", "hippo"};

    cout << "\nСлова: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    int countLength3 = count_if(words.begin(), words.end(), [](const string& s) { return s.length() == 3; });
    cout << "Строк длиной 3: " << countLength3 << endl;

    int countWithA = count_if(words.begin(), words.end(), [](const string& s) { return s.find('a') != string::npos; });
    cout << "Строк, содержащих 'a': " << countWithA << endl;

    int countStartsWithC = count_if(words.begin(), words.end(), [](const string& s) { return !s.empty() && s[0] == 'c'; });
    cout << "Строк, начинающихся на 'c': " << countStartsWithC << endl;
}

int main() {
    partA();
    partB();
    return 0;
}
