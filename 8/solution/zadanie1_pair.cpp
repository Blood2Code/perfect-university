// Задание 1. Шаблон класса Pair — хранит два значения одного типа.
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Pair {
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const { return first; }
    T getSecond() const { return second; }

    void setFirst(T f) { first = f; }
    void setSecond(T s) { second = s; }

    void swap() {
        T temp = first;
        first = second;
        second = temp;
    }

    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }

    bool operator==(const Pair& other) const {
        return first == other.first && second == other.second;
    }
};

int main() {
    cout << "=== Тестирование шаблона Pair ===" << endl;

    Pair<int> p1(10, 20);
    cout << "p1: ";
    p1.display();
    cout << "first = " << p1.getFirst() << ", second = " << p1.getSecond() << endl;

    p1.swap();
    cout << "После swap: ";
    p1.display();

    Pair<double> p2(3.14, 2.71);
    cout << "\np2: ";
    p2.display();

    Pair<string> p3("Hello", "World");
    cout << "\np3: ";
    p3.display();

    Pair<char> p4('A', 'B');
    cout << "p4: ";
    p4.display();

    return 0;
}
