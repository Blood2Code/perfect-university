// Задание 2. Класс DynamicArray с глубоким копированием и оператором присваивания.
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    DynamicArray(size_t n) : data(new int[n]), size(n) {
        cout << "Выделена память для " << size << " элементов" << endl;
        for (size_t i = 0; i < size; ++i) data[i] = 0;
    }

    DynamicArray(const DynamicArray& other) : data(new int[other.size]), size(other.size) {
        cout << "Конструктор копирования: создана копия" << endl;
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }

    ~DynamicArray() {
        cout << "Освобождение памяти для " << size << " элементов" << endl;
        delete[] data;
    }

    void setValue(size_t index, int value) {
        if (index < size) data[index] = value;
        else cout << "Ошибка: индекс вне диапазона!" << endl;
    }

    int getValue(size_t index) const {
        if (index < size) return data[index];
        cout << "Ошибка: индекс вне диапазона!" << endl;
        return 0;
    }

    size_t getSize() const { return size; }

    void display() const {
        cout << "[";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        cout << "Оператор присваивания" << endl;
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }
};

int main() {
    cout << "=== Создание массива ===" << endl;
    DynamicArray arr1(5);
    for (size_t i = 0; i < arr1.getSize(); ++i) arr1.setValue(i, i * 10);

    cout << "arr1: "; arr1.display();

    cout << "\n=== Копирование массива ===" << endl;
    DynamicArray arr2 = arr1;
    cout << "arr2: "; arr2.display();

    cout << "\n=== Изменение arr1 ===" << endl;
    arr1.setValue(0, 100);
    cout << "arr1: "; arr1.display();
    cout << "arr2: "; arr2.display();

    cout << "\n=== Присваивание ===" << endl;
    DynamicArray arr3(3);
    arr3 = arr1;
    cout << "arr3: "; arr3.display();

    cout << "\n=== Выход из программы ===" << endl;
    return 0;
}
