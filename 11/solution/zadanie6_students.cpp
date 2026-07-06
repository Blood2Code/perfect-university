// Задание 6. Комплексное задание: система управления студентами.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int id;
    double gpa;

    void display() const {
        cout << "ID: " << id << ", Имя: " << name << ", GPA: " << gpa << endl;
    }
};

int main() {
    vector<Student> students = {
        {"Иванов", 101, 4.5},
        {"Петров", 102, 3.8},
        {"Сидоров", 103, 4.2},
        {"Кузнецов", 104, 3.5},
        {"Смирнова", 105, 4.8},
        {"Попова", 106, 3.9},
        {"Васильев", 107, 4.1},
        {"Михайлов", 108, 3.7}
    };

    cout << "=== ВСЕ СТУДЕНТЫ ===" << endl;
    for_each(students.begin(), students.end(), [](const Student& s) { s.display(); });

    // 1. Сортировка по GPA по убыванию
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) { return a.gpa > b.gpa; });

    cout << "\n=== СТУДЕНТЫ ПО УБЫВАНИЮ GPA ===" << endl;
    for_each(students.begin(), students.end(), [](const Student& s) { s.display(); });

    // 2. Студент с максимальным GPA
    auto maxIt = max_element(students.begin(), students.end(),
                              [](const Student& a, const Student& b) { return a.gpa < b.gpa; });
    cout << "\n=== СТУДЕНТ С МАКСИМАЛЬНЫМ GPA ===" << endl;
    maxIt->display();

    // 3. Количество студентов с GPA > 4.0
    int countHigh = count_if(students.begin(), students.end(), [](const Student& s) { return s.gpa > 4.0; });
    cout << "\nСтудентов с GPA > 4.0: " << countHigh << endl;

    // 4. Студенты с GPA >= 4.0
    vector<Student> honours;
    copy_if(students.begin(), students.end(), back_inserter(honours),
            [](const Student& s) { return s.gpa >= 4.0; });

    cout << "\n=== СТУДЕНТЫ С GPA >= 4.0 ===" << endl;
    for_each(honours.begin(), honours.end(), [](const Student& s) { s.display(); });

    // 5. Студент с ID = 105
    auto it = find_if(students.begin(), students.end(), [](const Student& s) { return s.id == 105; });
    if (it != students.end()) {
        cout << "\nСтудент с ID 105: ";
        it->display();
    }

    // 6. Сортировка по имени
    sort(students.begin(), students.end(),
         [](const Student& a, const Student& b) { return a.name < b.name; });

    cout << "\n=== СТУДЕНТЫ ПО ИМЕНИ ===" << endl;
    for_each(students.begin(), students.end(), [](const Student& s) { s.display(); });

    return 0;
}
