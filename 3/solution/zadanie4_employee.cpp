// Задание 4. Класс Employee — список инициализации, константное и ссылочное поля.
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    const int id;
    const string& companyName;
    string name;
    string position;
    double salary;

public:
    Employee(int empId, const string& company,
             const string& empName, const string& empPosition, double empSalary)
        : id(empId), companyName(company), name(empName), position(empPosition), salary(empSalary) {
        cout << "Сотрудник " << name << " создан" << endl;
    }

    int getId() const { return id; }
    const string& getCompanyName() const { return companyName; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }

    void setName(const string& newName) { name = newName; }
    void setPosition(const string& newPosition) { position = newPosition; }
    void setSalary(double newSalary) {
        if (newSalary >= 0) salary = newSalary;
    }

    void display() const {
        cout << "ID: " << id
             << ", Компания: " << companyName
             << ", Имя: " << name
             << ", Должность: " << position
             << ", Зарплата: " << salary << endl;
    }
};

int main() {
    string company = "ООО ТехноИнновации";

    cout << "=== Создание сотрудников ===" << endl;
    Employee emp1(1001, company, "Сергеев Алексей", "Разработчик", 120000);
    Employee emp2(1002, company, "Кузнецова Анна", "Менеджер проекта", 95000);

    cout << "\n=== Информация о сотрудниках ===" << endl;
    emp1.display();
    emp2.display();

    cout << "\n=== Изменение данных ===" << endl;
    emp1.setPosition("Старший разработчик");
    emp1.setSalary(150000);
    emp1.display();

    // emp1.id = 2000;  // НЕ СКОМПИЛИРУЕТСЯ: id — константное поле

    cout << "\n=== Изменение внешней переменной company ===" << endl;
    company = "ООО Новые Технологии";
    cout << "Внешняя переменная company изменена на: " << company << endl;
    emp1.display();  // companyName ссылается на изменённую переменную
    emp2.display();

    return 0;
}
