// Задание 1, часть Б. Динамический массив: заполнение и вывод в обратном порядке.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int *arr = new int[n];     // Выделяем память под массив из n элементов

    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;        // Заполняем числами от 1 до n
    }

    cout << "Массив в обратном порядке: ";
    for (int i = n - 1; i >= 0; --i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;              // Освобождение памяти массива — обязательно delete[]

    return 0;
}
