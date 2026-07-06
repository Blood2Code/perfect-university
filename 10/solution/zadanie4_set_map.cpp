// Задание 4. Ассоциативные контейнеры set и map.
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

void partA_set() {
    cout << "=== Часть А: set ===" << endl;
    set<int> s = {5, 2, 8, 1, 9, 2, 5};

    cout << "Множество (автоматически отсортировано): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    s.insert(3);
    s.insert(7);
    s.insert(5);
    cout << "После вставки 3, 7: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    if (s.find(8) != s.end()) cout << "8 найдена в множестве" << endl;

    cout << "Количество 5: " << s.count(5) << endl;

    auto it_low = s.lower_bound(4);
    cout << "Элементы >= 4: ";
    for (auto it = it_low; it != s.end(); ++it) cout << *it << " ";
    cout << endl;

    s.erase(3);
    cout << "После удаления 3: ";
    for (int x : s) cout << x << " ";
    cout << endl;
}

void partB_map() {
    cout << "\n=== Часть Б: map ===" << endl;
    map<string, int> ages;

    ages["Alice"] = 25;
    ages.insert({"Bob", 30});
    ages.insert(make_pair("Charlie", 35));
    ages.emplace("David", 40);

    cout << "Словарь ages:" << endl;
    for (const auto& p : ages) cout << "  " << p.first << ": " << p.second << endl;

    cout << "Возраст Alice: " << ages["Alice"] << endl;
    cout << "Возраст Bob: " << ages.at("Bob") << endl;

    if (ages.find("Charlie") != ages.end()) cout << "Charlie найден!" << endl;

    ages["Alice"] = 26;
    cout << "Новый возраст Alice: " << ages["Alice"] << endl;

    ages.erase("David");
    cout << "После удаления David:" << endl;
    for (const auto& p : ages) cout << "  " << p.first << ": " << p.second << endl;

    cout << "Количество записей: " << ages.size() << endl;
}

int main() {
    partA_set();
    partB_map();
    return 0;
}
