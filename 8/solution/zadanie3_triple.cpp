// Задание 3. Шаблон класса Triple (три параметра) и Pair2 (параметры по умолчанию).
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2, typename T3>
class Triple {
private:
    T1 first;
    T2 second;
    T3 third;

public:
    Triple(T1 f, T2 s, T3 t) : first(f), second(s), third(t) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    T3 getThird() const { return third; }

    void setFirst(T1 f) { first = f; }
    void setSecond(T2 s) { second = s; }
    void setThird(T3 t) { third = t; }

    void display() const {
        cout << "(" << first << ", " << second << ", " << third << ")" << endl;
    }
};

template <typename T1 = int, typename T2 = int>
class Pair2 {
private:
    T1 first;
    T2 second;

public:
    Pair2(T1 f, T2 s) : first(f), second(s) {}

    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    cout << "=== Тестирование шаблона Triple ===" << endl;

    Triple<int, double, string> t1(42, 3.14, "Hello");
    cout << "t1: ";
    t1.display();

    Triple<string, int, char> t2("Age", 25, 'A');
    cout << "t2: ";
    t2.display();

    Triple<int, int, int> t3(10, 20, 30);
    cout << "t3: ";
    t3.display();

    cout << "t1 first = " << t1.getFirst() << endl;
    cout << "t1 second = " << t1.getSecond() << endl;
    cout << "t1 third = " << t1.getThird() << endl;

    cout << "\n=== Тестирование Pair2 с типами по умолчанию ===" << endl;
    Pair2<> p1(10, 20);
    p1.display();

    Pair2<string, double> p2("Pi", 3.14159);
    p2.display();

    return 0;
}
