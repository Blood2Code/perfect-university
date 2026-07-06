// Задание 5. Иерархия сотрудников: Employee -> Manager, Developer, Intern.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(const string& n, int i, double salary)
        : name(n), id(i), baseSalary(salary) {}

    virtual ~Employee() {}

    virtual double calculateSalary() const { return baseSalary; }

    virtual void display() const {
        cout << "Сотрудник: " << name << " (ID: " << id << ")" << endl;
        cout << "  Базовая зарплата: " << baseSalary << endl;
    }

    string getName() const { return name; }
    int getId() const { return id; }
};

class Manager : public Employee {
private:
    int subordinates;
    double bonus;

public:
    Manager(const string& n, int i, double salary, int subs, double b)
        : Employee(n, i, salary), subordinates(subs), bonus(b) {}

    double calculateSalary() const override {
        return baseSalary + bonus + (subordinates * 100);
    }

    void display() const override {
        Employee::display();
        cout << "  Должность: Менеджер" << endl;
        cout << "  Подчиненных: " << subordinates << endl;
        cout << "  Бонус: " << bonus << endl;
        cout << "  Итоговая зарплата: " << calculateSalary() << endl;
    }
};

class Developer : public Employee {
private:
    string language;
    int projects;

public:
    Developer(const string& n, int i, double salary, const string& lang, int proj)
        : Employee(n, i, salary), language(lang), projects(proj) {}

    double calculateSalary() const override {
        return baseSalary + (projects * 500);
    }

    void display() const override {
        Employee::display();
        cout << "  Должность: Разработчик" << endl;
        cout << "  Язык программирования: " << language << endl;
        cout << "  Проектов: " << projects << endl;
        cout << "  Итоговая зарплата: " << calculateSalary() << endl;
    }
};

class Intern : public Employee {
private:
    string university;
    int internshipDuration;

public:
    Intern(const string& n, int i, double salary, const string& uni, int duration)
        : Employee(n, i, salary), university(uni), internshipDuration(duration) {}

    double calculateSalary() const override {
        return baseSalary * 0.7;
    }

    void display() const override {
        Employee::display();
        cout << "  Должность: Стажер" << endl;
        cout << "  Учебное заведение: " << university << endl;
        cout << "  Срок стажировки: " << internshipDuration << " мес." << endl;
        cout << "  Итоговая зарплата: " << calculateSalary() << endl;
    }
};

int main() {
    cout << "=== Иерархия сотрудников компании ===" << endl << endl;

    vector<Employee*> employees;

    employees.push_back(new Manager("Иванов Иван", 1001, 50000, 5, 10000));
    employees.push_back(new Developer("Петров Петр", 1002, 40000, "C++", 3));
    employees.push_back(new Developer("Сидорова Анна", 1003, 45000, "Python", 4));
    employees.push_back(new Intern("Кузнецов Алексей", 1004, 20000, "МГТУ", 6));
    employees.push_back(new Manager("Смирнова Елена", 1005, 55000, 8, 15000));

    double totalSalary = 0;

    for (Employee* emp : employees) {
        emp->display();
        cout << endl;
        totalSalary += emp->calculateSalary();
    }

    cout << "=== Итоги ===" << endl;
    cout << "Всего сотрудников: " << employees.size() << endl;
    cout << "Общий фонд зарплаты: " << totalSalary << endl;

    for (Employee* emp : employees) delete emp;

    return 0;
}
