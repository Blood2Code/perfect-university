// Задание 2, часть Б. Динамический массив объектов Student.
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
    Student* students = new Student[3];   // Массив создаётся конструктором по умолчанию

    students[0] = Student("Иванов Иван", 19, 4.5);
    students[1] = Student("Петрова Мария", 18, 4.8);
    students[2] = Student("Сидоров Алексей", 20, 4.2);

    cout << "\n=== Все студенты ===\n";
    for (int i = 0; i < 3; ++i) {
        students[i].display();
    }

    int bestIndex = 0;
    for (int i = 1; i < 3; ++i) {
        if (students[i].getGrade() > students[bestIndex].getGrade()) {
            bestIndex = i;
        }
    }

    cout << "\nЛучший студент: ";
    students[bestIndex].display();

    delete[] students;

    return 0;
}
