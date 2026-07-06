// Задание 6. Адаптеры контейнеров: stack, queue, priority_queue.
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

void partA() {
    stack<int> st;
    cout << "=== Стек (LIFO) ===" << endl;
    st.push(10); st.push(20); st.push(30);
    cout << "Верхний элемент: " << st.top() << endl;

    cout << "Извлечение элементов: ";
    while (!st.empty()) { cout << st.top() << " "; st.pop(); }
    cout << endl;

    queue<int> q;
    cout << "\n=== Очередь (FIFO) ===" << endl;
    q.push(10); q.push(20); q.push(30);
    cout << "Первый элемент: " << q.front() << endl;
    cout << "Последний элемент: " << q.back() << endl;

    cout << "Извлечение элементов: ";
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
    cout << endl;
}

struct Task {
    string name;
    int priority;
};

struct CompareTask {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority;
    }
};

void partB() {
    priority_queue<int> maxPq;
    maxPq.push(10); maxPq.push(30); maxPq.push(20); maxPq.push(5); maxPq.push(25);

    cout << "\n=== Максимальная куча ===" << endl;
    cout << "Извлечение элементов (по убыванию): ";
    while (!maxPq.empty()) { cout << maxPq.top() << " "; maxPq.pop(); }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minPq;
    minPq.push(10); minPq.push(30); minPq.push(20); minPq.push(5); minPq.push(25);

    cout << "\n=== Минимальная куча ===" << endl;
    cout << "Извлечение элементов (по возрастанию): ";
    while (!minPq.empty()) { cout << minPq.top() << " "; minPq.pop(); }
    cout << endl;

    priority_queue<Task, vector<Task>, CompareTask> taskQueue;
    taskQueue.push({"Срочная задача", 10});
    taskQueue.push({"Обычная задача", 5});
    taskQueue.push({"Критическая задача", 15});

    cout << "\n=== Очередь задач по приоритету ===" << endl;
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        cout << "Задача: " << t.name << " (приоритет: " << t.priority << ")" << endl;
        taskQueue.pop();
    }
}

int main() {
    partA();
    partB();
    return 0;
}
