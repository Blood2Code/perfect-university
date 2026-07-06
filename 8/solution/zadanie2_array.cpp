// Задание 2. Шаблон класса Array — динамический массив произвольного типа.
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize() {
        capacity = capacity == 0 ? 1 : capacity * 2;
        T* newData = new T[capacity];
        for (size_t i = 0; i < size; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Array(size_t cap = 0) : size(0), capacity(cap) {
        data = (capacity > 0) ? new T[capacity] : nullptr;
        cout << "Создан массив вместимостью " << capacity << endl;
    }

    Array(const Array& other) : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
        cout << "Создана копия массива" << endl;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    ~Array() {
        delete[] data;
        cout << "Массив удалён" << endl;
    }

    T& operator[](size_t index) {
        if (index >= size) throw out_of_range("Индекс вне диапазона");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) throw out_of_range("Индекс вне диапазона");
        return data[index];
    }

    void push_back(const T& value) {
        if (size >= capacity) resize();
        data[size++] = value;
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }

    void display() const {
        cout << "[";
        for (size_t i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main() {
    cout << "=== Тестирование шаблона Array ===" << endl;

    Array<int> intArr;
    cout << "\nДобавление элементов в intArr:" << endl;
    for (int i = 1; i <= 10; ++i) {
        intArr.push_back(i * 10);
        cout << "  Добавлен " << i * 10 << ", размер: " << intArr.getSize()
             << ", вместимость: " << intArr.getCapacity() << endl;
    }
    cout << "intArr: ";
    intArr.display();

    Array<string> strArr;
    strArr.push_back("Apple");
    strArr.push_back("Banana");
    strArr.push_back("Cherry");
    cout << "\nstrArr: ";
    strArr.display();

    cout << "strArr[1] = " << strArr[1] << endl;
    strArr[1] = "Blueberry";
    cout << "После изменения: ";
    strArr.display();

    Array<double> doubleArr;
    doubleArr.push_back(3.14);
    doubleArr.push_back(2.71);
    doubleArr.push_back(1.41);
    cout << "\ndoubleArr: ";
    doubleArr.display();

    return 0;
}
