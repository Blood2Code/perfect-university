// Задание 7, часть А. Анализ частоты слов в тексте с использованием map.
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string text = "hello world hello cpp hello stl world cpp programming";

    map<string, int> wordCount;

    stringstream ss(text);
    string word;

    while (ss >> word) {
        for (char& c : word) c = tolower(c);
        wordCount[word]++;   // map::operator[] создаёт элемент со значением 0, если ключа ещё нет
    }

    cout << "=== Частота слов ===" << endl;
    for (const auto& p : wordCount) cout << p.first << ": " << p.second << endl;

    string mostFrequent;
    int maxCount = 0;
    for (const auto& p : wordCount) {
        if (p.second > maxCount) {
            maxCount = p.second;
            mostFrequent = p.first;
        }
    }
    cout << "\nСамое частотное слово: " << mostFrequent
         << " (встречается " << maxCount << " раз)" << endl;

    return 0;
}
