// Задание 5. Комплексный класс Student: динамический массив оценок,
// глубокое копирование, оператор присваивания, деструктор.
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string fullName;
    const int studentId;
    double* grades;
    int gradeCount;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        double* newGrades = new double[newCapacity];
        for (int i = 0; i < gradeCount; ++i) newGrades[i] = grades[i];
        delete[] grades;
        grades = newGrades;
        capacity = newCapacity;
    }

public:
    Student(const string& name, int id, const double* initialGrades, int count)
        : fullName(name), studentId(id), gradeCount(count), capacity(count + 5) {
        grades = new double[capacity];
        for (int i = 0; i < count; ++i) grades[i] = initialGrades[i];
        cout << "Студент " << fullName << " (ID: " << studentId << ") создан" << endl;
    }

    Student(const Student& other)
        : fullName(other.fullName), studentId(other.studentId),
          gradeCount(other.gradeCount), capacity(other.capacity) {
        grades = new double[capacity];
        for (int i = 0; i < gradeCount; ++i) grades[i] = other.grades[i];
        cout << "Создана копия студента " << fullName << endl;
    }

    ~Student() {
        delete[] grades;
        cout << "Студент " << fullName << " удален" << endl;
    }

    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] grades;
            fullName = other.fullName;
            // studentId - const, нельзя изменить
            gradeCount = other.gradeCount;
            capacity = other.capacity;
            grades = new double[capacity];
            for (int i = 0; i < gradeCount; ++i) grades[i] = other.grades[i];
        }
        return *this;
    }

    void addGrade(double grade) {
        if (gradeCount >= capacity) resize();
        grades[gradeCount++] = grade;
        cout << "Добавлена оценка " << grade << " для " << fullName << endl;
    }

    double getAverageGrade() const {
        if (gradeCount == 0) return 0;
        double sum = 0;
        for (int i = 0; i < gradeCount; ++i) sum += grades[i];
        return sum / gradeCount;
    }

    void display() const {
        cout << "Студент: " << fullName << " (ID: " << studentId << ")" << endl;
        cout << "Оценки: ";
        for (int i = 0; i < gradeCount; ++i) cout << grades[i] << " ";
        cout << endl;
        cout << "Средний балл: " << getAverageGrade() << endl;
    }

    string getName() const { return fullName; }
    int getId() const { return studentId; }
    int getGradeCount() const { return gradeCount; }
};

int main() {
    cout << "=== Создание студентов ===" << endl;
    double grades1[] = {4.5, 5.0, 4.0};
    Student s1("Иванов Иван", 1001, grades1, 3);

    double grades2[] = {5.0, 5.0, 4.5, 5.0};
    Student s2("Петрова Мария", 1002, grades2, 4);

    cout << "\n=== Информация о студентах ===" << endl;
    s1.display();
    cout << endl;
    s2.display();

    cout << "\n=== Добавление оценок ===" << endl;
    s1.addGrade(3.5);
    s1.addGrade(4.0);
    s1.display();

    cout << "\n=== Копирование студента ===" << endl;
    Student s3 = s1;
    s3.display();

    cout << "\n=== Изменение оригинала после копирования ===" << endl;
    s1.addGrade(5.0);
    cout << "Оригинал: "; s1.display();
    cout << "Копия: "; s3.display();

    return 0;
}
