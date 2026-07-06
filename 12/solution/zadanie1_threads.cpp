// Задание 1. Создание и запуск потоков.
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void printMessage(const string& msg, int delay) {
    this_thread::sleep_for(chrono::milliseconds(delay));
    cout << msg << " (поток ID: " << this_thread::get_id() << ")" << endl;
}

void computeSum(int a, int b) {
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Сумма " << a << " + " << b << " = " << a + b << endl;
}

int main() {
    cout << "Главный поток ID: " << this_thread::get_id() << endl;

    thread t1(printMessage, "Привет из потока!", 100);
    thread t2(computeSum, 10, 20);
    thread t3([]() {
        cout << "Лямбда-поток выполняется (ID: " << this_thread::get_id() << ")" << endl;
    });

    t1.join();
    t2.join();
    t3.join();

    cout << "Все потоки завершили работу" << endl;

    return 0;
}
