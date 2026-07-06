// Задание 2. Работа с list.
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> lst = {5, 2, 8, 1, 9, 2, 5, 3};

    cout << "Исходный список: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    lst.push_front(0);
    lst.push_back(10);
    cout << "После push_front(0) и push_back(10): ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    lst.sort();
    cout << "После сортировки: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    lst.unique();
    cout << "После удаления дубликатов: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    lst.remove(5);
    cout << "После удаления всех 5: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    lst.reverse();
    cout << "После разворота: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    list<int>::iterator it = lst.begin();
    advance(it, 3);
    lst.insert(it, 99);
    cout << "После вставки 99 на позицию 3: ";
    for (int x : lst) cout << x << " ";
    cout << endl;

    return 0;
}
