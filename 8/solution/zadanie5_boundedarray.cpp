// Задание 5. Шаблон класса BoundedArray с параметром-не-типом (размер).
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T, size_t N>
class BoundedArray {
private:
    T data[N];
    size_t currentSize;

public:
    BoundedArray() : currentSize(0) {
        for (size_t i = 0; i < N; ++i) data[i] = T();
    }

    bool push_back(const T& value) {
        if (currentSize < N) {
            data[currentSize++] = value;
            return true;
        }
        return false;
    }

    T& operator[](size_t index) {
        if (index >= currentSize) throw out_of_range("Индекс вне диапазона");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= currentSize) throw out_of_range("Индекс вне диапазона");
        return data[index];
    }

    size_t getSize() const { return currentSize; }
    constexpr size_t getCapacity() const { return N; }
    bool isEmpty() const { return currentSize == 0; }
    bool isFull() const { return currentSize == N; }

    void display() const {
        cout << "[";
        for (size_t i = 0; i < currentSize; ++i) {
            cout << data[i];
            if (i < currentSize - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    cout << "=== Тестирование BoundedArray ===" << endl;

    BoundedArray<int, 5> intArray;

    cout << "Вместимость: " << intArray.getCapacity() << endl;
    cout << "Пуст? " << (intArray.isEmpty() ? "Да" : "Нет") << endl;

    for (int i = 1; i <= 7; ++i) {
        if (intArray.push_back(i * 10)) {
            cout << "Добавлен " << i * 10 << ", размер: " << intArray.getSize() << endl;
        } else {
            cout << "Не удалось добавить " << i * 10 << " (массив полон)" << endl;
        }
    }

    cout << "Массив: ";
    intArray.display();
    cout << "Полон? " << (intArray.isFull() ? "Да" : "Нет") << endl;

    BoundedArray<string, 3> strArray;
    strArray.push_back("Apple");
    strArray.push_back("Banana");
    strArray.push_back("Cherry");
    strArray.push_back("Date");

    cout << "\nСтроковый массив: ";
    strArray.display();

    return 0;
}
