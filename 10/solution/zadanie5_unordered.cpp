// Задание 5. Неупорядоченные контейнеры unordered_set и unordered_map.
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_set<int> us = {5, 2, 8, 1, 9, 2};

    cout << "unordered_set (порядок не гарантирован): ";
    for (int x : us) cout << x << " ";
    cout << endl;

    us.insert(10);
    us.insert(3);
    us.erase(2);

    cout << "После операций: ";
    for (int x : us) cout << x << " ";
    cout << endl;

    cout << "Наличие 8: " << (us.find(8) != us.end() ? "Да" : "Нет") << endl;
    cout << "Количество 5: " << us.count(5) << endl;

    unordered_map<string, int> um;
    um["apple"] = 5;
    um["banana"] = 3;
    um["cherry"] = 7;

    cout << "\nunordered_map (порядок не гарантирован):" << endl;
    for (const auto& p : um) cout << "  " << p.first << ": " << p.second << endl;

    cout << "Количество корзин: " << um.bucket_count() << endl;
    cout << "load factor: " << um.load_factor() << endl;

    return 0;
}
