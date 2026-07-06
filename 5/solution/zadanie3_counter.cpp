// Задание 3. Класс Counter — перегрузка инкремента/декремента и ввода/вывода.
#include <iostream>
using namespace std;

class Counter {
private:
    int value;
    int minValue;
    int maxValue;

public:
    Counter(int min = 0, int max = 100, int start = 0)
        : minValue(min), maxValue(max) {
        if (start < min) value = min;
        else if (start > max) value = max;
        else value = start;
    }

    int getValue() const { return value; }

    // Префиксный инкремент: изменяет объект и возвращает ссылку на него
    Counter& operator++() {
        if (value < maxValue) ++value;
        return *this;
    }

    // Постфиксный инкремент: сохраняет старое состояние, возвращает его копией
    Counter operator++(int) {
        Counter temp = *this;
        ++(*this);
        return temp;
    }

    Counter& operator--() {
        if (value > minValue) --value;
        return *this;
    }

    Counter operator--(int) {
        Counter temp = *this;
        --(*this);
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Counter& c) {
        os << "Counter[" << c.minValue << ".." << c.maxValue << "]: " << c.value;
        return os;
    }

    friend istream& operator>>(istream& is, Counter& c) {
        int newValue;
        is >> newValue;
        if (newValue >= c.minValue && newValue <= c.maxValue) {
            c.value = newValue;
        } else {
            cout << "Ошибка: значение вне диапазона [" << c.minValue
                 << ".." << c.maxValue << "]" << endl;
        }
        return is;
    }
};

int main() {
    Counter c(0, 10, 5);

    cout << "Начальное состояние: " << c << endl;

    cout << "\nПрефиксный инкремент:" << endl;
    cout << "++c = " << ++c << endl;
    cout << "После ++c: " << c << endl;

    cout << "\nПостфиксный инкремент:" << endl;
    cout << "c++ = " << c++ << endl;
    cout << "После c++: " << c << endl;

    cout << "\nПрефиксный декремент:" << endl;
    cout << "--c = " << --c << endl;
    cout << "После --c: " << c << endl;

    cout << "\nПостфиксный декремент:" << endl;
    cout << "c-- = " << c-- << endl;
    cout << "После c--: " << c << endl;

    cout << "\nВведите новое значение (0-10): ";
    cin >> c;
    cout << "После ввода: " << c << endl;

    return 0;
}
