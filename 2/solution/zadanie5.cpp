// Задание 5. Комплексное задание: класс DynamicArray на основе unique_ptr<int[]>.
#include <iostream>
#include <memory>
using namespace std;

class DynamicArray {
private:
    unique_ptr<int[]> data;
    size_t size;

public:
    DynamicArray(size_t s) : data(make_unique<int[]>(s)), size(s) {
        cout << "Создан массив размера " << size << "\n";
        for (size_t i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    void setValue(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        } else {
            cout << "Ошибка: индекс вне диапазона!" << endl;
        }
    }

    int getValue(size_t index) const {
        if (index < size) {
            return data[index];
        }
        cout << "Ошибка: индекс вне диапазона!" << endl;
        return 0;
    }

    size_t getSize() const { return size; }

    void print() const {
        cout << "[";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    // Деструктор не нужен — unique_ptr автоматически освободит память
};

int main() {
    DynamicArray arr(10);

    for (size_t i = 0; i < arr.getSize(); ++i) {
        arr.setValue(i, static_cast<int>(i) * 10);
    }

    cout << "Массив: ";
    arr.print();

    arr.setValue(2, 999);
    arr.setValue(7, -5);

    cout << "После изменения: ";
    arr.print();

    return 0;
}
