// Задание 3. Работа с deque.
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);

    cout << "deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    cout << "Элемент по индексу 2: " << dq[2] << endl;
    cout << "Элемент по индексу 0: " << dq.at(0) << endl;

    dq[2] = 100;
    cout << "После изменения dq[2] = 100: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    dq.insert(dq.begin() + 2, 50);
    cout << "После вставки 50 на позицию 2: ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    dq.pop_front();
    dq.pop_back();
    cout << "После pop_front() и pop_back(): ";
    for (int x : dq) cout << x << " ";
    cout << endl;

    return 0;
}
