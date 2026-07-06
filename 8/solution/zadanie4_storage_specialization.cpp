// Задание 4. Специализация шаблона Storage для bool и const char*.
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Storage {
private:
    T value;

public:
    Storage(T v) : value(v) {}

    void display() const {
        cout << "Значение: " << value << endl;
    }

    T getValue() const { return value; }
};

// Полная специализация для типа bool
template <>
class Storage<bool> {
private:
    bool value;

public:
    Storage(bool v) : value(v) {}

    void display() const {
        cout << "Булево значение: " << (value ? "true (истина)" : "false (ложь)") << endl;
    }

    bool getValue() const { return value; }

    void invert() { value = !value; }
};

// Полная специализация для типа const char*
template <>
class Storage<const char*> {
private:
    const char* value;

public:
    Storage(const char* v) : value(v) {}

    void display() const {
        cout << "C-строка: \"" << value << "\"" << endl;
    }

    const char* getValue() const { return value; }

    size_t getLength() const {
        size_t len = 0;
        while (value[len] != '\0') len++;
        return len;
    }
};

int main() {
    cout << "=== Специализация шаблона Storage ===" << endl;

    Storage<int> s1(42);
    s1.display();

    Storage<double> s2(3.14159);
    s2.display();

    Storage<string> s3("Hello, World!");
    s3.display();

    Storage<bool> s4(true);
    s4.display();

    s4.invert();
    cout << "После инверсии: ";
    s4.display();

    Storage<const char*> s5("Hello");
    s5.display();
    cout << "Длина строки: " << s5.getLength() << endl;

    return 0;
}
