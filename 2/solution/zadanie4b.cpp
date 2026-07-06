// Задание 4, часть Б. std::shared_ptr — разделяемое владение со счётчиком ссылок.
#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct Student {
    string name;
    Student(const string& n) : name(n) { cout << "Создан студент " << name << "\n"; }
    ~Student() { cout << "Удалён студент " << name << "\n"; }
};

int main() {
    shared_ptr<Student> s1 = make_shared<Student>("Петрова Мария");
    cout << "use_count после создания s1: " << s1.use_count() << endl;

    shared_ptr<Student> s2 = s1;   // копия — счётчик увеличивается
    cout << "use_count после копии s2: " << s1.use_count() << endl;

    shared_ptr<Student> s3 = s1;   // ещё одна копия
    cout << "use_count после копии s3: " << s1.use_count() << endl;

    s3.reset();                    // удаляем одну из копий
    cout << "use_count после reset() s3: " << s1.use_count() << endl;

    return 0;
}
