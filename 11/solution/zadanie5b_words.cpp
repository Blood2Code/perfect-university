// Задание 5, часть Б. Фильтрация и сортировка строк.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    vector<string> words = {"apple", "banana", "cat", "dog", "elephant", "fox",
                             "grape", "hippo", "iguana", "jackal", "kangaroo", "lion"};

    cout << "Исходные слова: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    // 1. Отфильтровать слова длиннее 4 букв
    vector<string> longWords;
    copy_if(words.begin(), words.end(), back_inserter(longWords),
            [](const string& w) { return w.length() > 4; });

    cout << "Слова длиннее 4 букв: ";
    for (const auto& w : longWords) cout << w << " ";
    cout << endl;

    // 2. Отсортировать longWords по длине строки
    sort(longWords.begin(), longWords.end(),
         [](const string& a, const string& b) { return a.length() < b.length(); });

    // 3. Вывести отсортированные слова
    cout << "Отсортированные по длине: ";
    for (const auto& w : longWords) cout << w << " ";
    cout << endl;

    // 4. Найти слово "fox"
    auto it = find(words.begin(), words.end(), "fox");
    if (it != words.end()) {
        cout << "Слово 'fox' найдено" << endl;
    } else {
        cout << "Слово 'fox' не найдено" << endl;
    }

    // 5. Преобразовать все слова в верхний регистр
    transform(words.begin(), words.end(), words.begin(), [](string s) {
        for (char& c : s) c = toupper(c);
        return s;
    });

    cout << "Слова в верхнем регистре: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    return 0;
}
