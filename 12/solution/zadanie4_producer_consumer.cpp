// Задание 4. Условные переменные: задача "производитель-потребитель".
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
using namespace std;

queue<int> buffer;
const int BUFFER_MAX_SIZE = 5;
mutex mtx;
condition_variable cv_producer, cv_consumer;
bool finished = false;

void producer(int id) {
    for (int i = 1; i <= 10; ++i) {
        unique_lock<mutex> lock(mtx);

        cv_producer.wait(lock, [] { return buffer.size() < BUFFER_MAX_SIZE; });

        buffer.push(i);
        cout << "Производитель " << id << " добавил: " << i
             << ", размер буфера: " << buffer.size() << endl;

        cv_consumer.notify_one();

        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(int id) {
    while (!finished) {
        unique_lock<mutex> lock(mtx);

        cv_consumer.wait(lock, [] { return !buffer.empty() || finished; });

        if (!buffer.empty()) {
            int value = buffer.front();
            buffer.pop();
            cout << "Потребитель " << id << " извлёк: " << value
                 << ", размер буфера: " << buffer.size() << endl;

            cv_producer.notify_one();
        }

        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

int main() {
    thread prod1(producer, 1);
    thread prod2(producer, 2);
    thread cons1(consumer, 1);
    thread cons2(consumer, 2);

    prod1.join();
    prod2.join();

    this_thread::sleep_for(chrono::seconds(1));
    finished = true;

    cv_consumer.notify_all();
    cons1.join();
    cons2.join();

    return 0;
}
