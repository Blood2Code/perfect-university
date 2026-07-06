// Задание 5. Демонстрация deadlock и способы его предотвращения.
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtxA;
mutex mtxB;

// ---- Часть А: демонстрация взаимоблокировки ----
void thread1() {
    cout << "Поток 1: захват mtxA..." << endl;
    lock_guard<mutex> lockA(mtxA);
    this_thread::sleep_for(chrono::milliseconds(10));

    cout << "Поток 1: попытка захвата mtxB..." << endl;
    lock_guard<mutex> lockB(mtxB);

    cout << "Поток 1: обе блокировки получены!" << endl;
}

void thread2() {
    cout << "Поток 2: захват mtxB..." << endl;
    lock_guard<mutex> lockB(mtxB);
    this_thread::sleep_for(chrono::milliseconds(10));

    cout << "Поток 2: попытка захвата mtxA..." << endl;
    lock_guard<mutex> lockA(mtxA);

    cout << "Поток 2: обе блокировки получены!" << endl;
}

// ---- Часть Б: предотвращение через std::lock ----
void threadSafe1() {
    lock(mtxA, mtxB);
    lock_guard<mutex> lockA(mtxA, adopt_lock);
    lock_guard<mutex> lockB(mtxB, adopt_lock);

    cout << "Поток 1 (безопасный): обе блокировки получены!" << endl;
}

void threadSafe2() {
    lock(mtxA, mtxB);
    lock_guard<mutex> lockA(mtxA, adopt_lock);
    lock_guard<mutex> lockB(mtxB, adopt_lock);

    cout << "Поток 2 (безопасный): обе блокировки получены!" << endl;
}

// ---- Часть В: scoped_lock (C++17) ----
void threadScoped1() {
    scoped_lock lock(mtxA, mtxB);
    cout << "Поток 1 (scoped_lock): обе блокировки получены!" << endl;
}

void threadScoped2() {
    scoped_lock lock(mtxA, mtxB);
    cout << "Поток 2 (scoped_lock): обе блокировки получены!" << endl;
}

int main() {
    // ВНИМАНИЕ: task5a() в этом порядке потоков может (не гарантированно, но
    // с высокой вероятностью благодаря sleep) привести к настоящему deadlock
    // и "зависнуть". Приведено для демонстрации проблемы — не для регулярного
    // запуска. Ниже она закомментирована, чтобы автоматическая проверка
    // программы не зависала; при желании раскомментируйте для наблюдения.
    /*
    cout << "=== Демонстрация deadlock (может зависнуть!) ===" << endl;
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    */

    cout << "=== Предотвращение deadlock через std::lock ===" << endl;
    thread t3(threadSafe1);
    thread t4(threadSafe2);
    t3.join();
    t4.join();

    cout << "\n=== Использование scoped_lock (C++17) ===" << endl;
    thread t5(threadScoped1);
    thread t6(threadScoped2);
    t5.join();
    t6.join();

    cout << "\nПрограмма завершена без deadlock" << endl;

    return 0;
}
