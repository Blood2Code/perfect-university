// Задание 7, часть Б. Система управления студентами с группами.
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    vector<int> grades;

    double getAverage() const {
        if (grades.empty()) return 0;
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }
};

int main() {
    map<string, set<string>> groups;
    map<string, Student> students;

    groups["И-101"] = {"Иванов", "Петров"};
    groups["И-102"] = {"Сидоров", "Кузнецова"};

    students["Иванов"] = {"Иванов", {5, 4, 5}};
    students["Петров"] = {"Петров", {4, 4, 3}};
    students["Сидоров"] = {"Сидоров", {5, 5, 4}};
    students["Кузнецова"] = {"Кузнецова", {3, 4, 5}};

    cout << "=== Студенты группы И-101 ===" << endl;
    for (const auto& name : groups["И-101"]) cout << "  " << name << endl;

    cout << "\n=== Средний балл каждого студента ===" << endl;
    for (const auto& p : students) {
        cout << "  " << p.first << ": " << p.second.getAverage() << endl;
    }

    string bestStudent;
    double bestAverage = -1;
    for (const auto& p : students) {
        if (p.second.getAverage() > bestAverage) {
            bestAverage = p.second.getAverage();
            bestStudent = p.first;
        }
    }
    cout << "\nЛучший студент: " << bestStudent << " (средний балл: " << bestAverage << ")" << endl;

    return 0;
}
