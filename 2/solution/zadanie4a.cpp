// Задание 4, часть А. std::unique_ptr — единоличное владение.
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Student {
private:
    string name;
    int age;
    double grade;

public:
    Student(const string& n, int a, double g) : name(n), age(a), grade(g) {
        cout << "Конструктор с параметрами: " << name << "\n";
    }
    ~Student() { cout << "Деструктор: " << name << "\n"; }

    void display() const {
        cout << "Студент: " << name << ", возраст: " << age << ", средний балл: " << grade << "\n";
    }
};

unique_ptr<Student> createStudent(const string& name, int age, double grade) {
    return make_unique<Student>(name, age, grade);
}

int main() {
    unique_ptr<Student> s1 = createStudent("Иванов Иван", 19, 4.5);

    s1->display();

    // unique_ptr<Student> s2 = s1;      // ОШИБКА КОМПИЛЯЦИИ: копирование запрещено
    unique_ptr<Student> s2 = std::move(s1); // перемещение владения разрешено

    cout << "После перемещения s1 " << (s1 ? "не пуст" : "пуст (nullptr)") << endl;
    s2->display();

    return 0;
}
