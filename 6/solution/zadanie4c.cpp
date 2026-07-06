// Задание 4, часть В. Проблема циклических ссылок и её решение через weak_ptr.
#include <iostream>
#include <memory>
using namespace std;

// Проблемный вариант: два shared_ptr держат друг друга — счётчик ссылок
// никогда не опустится до нуля, деструкторы не вызовутся (утечка памяти).
struct Node {
    shared_ptr<Node> next;
    ~Node() { cout << "Node удалён\n"; }
};

// Исправленный вариант: prev — слабая ссылка, она не увеличивает счётчик
// владения и не мешает освобождению памяти.
struct FixedNode {
    shared_ptr<FixedNode> next;
    weak_ptr<FixedNode> prev;
    ~FixedNode() { cout << "FixedNode удалён\n"; }
};

void demonstrateCycle() {
    cout << "=== Циклическая ссылка (утечка) ===" << endl;
    auto node1 = make_shared<Node>();
    auto node2 = make_shared<Node>();

    node1->next = node2;
    node2->next = node1;  // цикл: node1 <-> node2

    cout << "Выход из функции demonstrateCycle — деструкторы НЕ вызовутся" << endl;
}

void demonstrateFixed() {
    cout << "\n=== Исправлено с помощью weak_ptr ===" << endl;
    auto node1 = make_shared<FixedNode>();
    auto node2 = make_shared<FixedNode>();

    node1->next = node2;
    node2->prev = node1;   // слабая ссылка не создаёт цикл владения

    cout << "Выход из функции demonstrateFixed — деструкторы вызовутся" << endl;
}

int main() {
    demonstrateCycle();
    demonstrateFixed();

    return 0;
}
