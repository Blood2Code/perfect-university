// Задание 4. Класс DynamicArray — перегрузка оператора присваивания (правило трёх).
#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    DynamicArray(size_t n = 0) : size(n) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) data[i] = 0;
        cout << "Конструктор: создан массив размера " << size << endl;
    }

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
        cout << "Конструктор копирования" << endl;
    }

    ~DynamicArray() {
        delete[] data;
        cout << "Деструктор: удалён массив размера " << size << endl;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        cout << "Оператор присваивания" << endl;
        if (this != &other) {           // защита от самоприсваивания
            delete[] data;               // 1. освободить старую память
            size = other.size;
            data = new int[size];        // 2. выделить новую память
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i]; // 3. скопировать данные
            }
        }
        return *this;                    // 4. вернуть *this
    }

    int& operator[](size_t index) {
        if (index >= size) throw out_of_range("Индекс вне диапазона");
        return data[index];
    }

    const int& operator[](size_t index) const {
        if (index >= size) throw out_of_range("Индекс вне диапазона");
        return data[index];
    }

    size_t getSize() const { return size; }

    void display() const {
        cout << "[";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]";
    }
};

int main() {
    cout << "=== Создание массива arr1 ===" << endl;
    DynamicArray arr1(5);
    for (size_t i = 0; i < arr1.getSize(); ++i) arr1[i] = i * 10;
    cout << "arr1 = "; arr1.display(); cout << endl;

    cout << "\n=== Копирование через конструктор копирования ===" << endl;
    DynamicArray arr2 = arr1;
    cout << "arr2 = "; arr2.display(); cout << endl;

    cout << "\n=== Присваивание ===" << endl;
    DynamicArray arr3(3);
    arr3 = arr1;
    cout << "arr3 = "; arr3.display(); cout << endl;

    cout << "\n=== Самоприсваивание ===" << endl;
    arr1 = arr1;
    cout << "arr1 = "; arr1.display(); cout << endl;

    cout << "\n=== Выход из программы ===" << endl;
    return 0;
}
