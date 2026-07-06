// Задание 2, часть А. Создание и удаление объекта Student в динамической памяти.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double grade;

public:
    Student() : name("Unknown"), age(0), grade(0.0) {
        cout << "Конструктор по умолчанию\n";
    }

    Student(const string& n, int a, double g) : name(n), age(a), grade(g) {
        cout << "Конструктор с параметрами: " << name << "\n";
    }

    ~Student() {
        cout << "Деструктор: " << name << "\n";
    }

    void display() const {
        cout << "Студент: " << name << ", возраст: " << age << ", средний балл: " << grade << "\n";
    }

    void setGrade(double g) { grade = g; }
    double getGrade() const { return grade; }
};

int main() {
    Student* s = new Student("Иванов Иван", 19, 4.5);

    s->display();

    s->setGrade(4.9);
    s->display();

    delete s;

    return 0;
}
