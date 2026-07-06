// Задание 4. Множественное наследование: Printable + Serializable -> Document.
#include <iostream>
#include <string>
using namespace std;

class Printable {
public:
    virtual ~Printable() {}
    virtual void print() const = 0;
};

class Serializable {
public:
    virtual ~Serializable() {}
    virtual string serialize() const = 0;
    virtual void deserialize(const string& data) = 0;
};

class Document : public Printable, public Serializable {
private:
    string title;
    string content;
    int id;

public:
    Document(const string& t = "", const string& c = "", int i = 0)
        : title(t), content(c), id(i) {}

    void print() const override {
        cout << "=== Документ ===" << endl;
        cout << "ID: " << id << endl;
        cout << "Заголовок: " << title << endl;
        cout << "Содержание: " << content << endl;
        cout << "================" << endl;
    }

    string serialize() const override {
        return to_string(id) + "|" + title + "|" + content;
    }

    void deserialize(const string& data) override {
        size_t pos1 = data.find('|');
        size_t pos2 = data.find('|', pos1 + 1);

        id = stoi(data.substr(0, pos1));
        title = data.substr(pos1 + 1, pos2 - pos1 - 1);
        content = data.substr(pos2 + 1);
    }

    void setTitle(const string& t) { title = t; }
    void setContent(const string& c) { content = c; }
    string getTitle() const { return title; }
};

int main() {
    cout << "=== Множественное наследование ===" << endl;

    Document doc("Отчет", "Текст отчета...", 123);
    doc.print();

    string serialized = doc.serialize();
    cout << "Сериализованные данные: " << serialized << endl;

    Document doc2;
    doc2.deserialize(serialized);
    cout << "\nПосле десериализации:" << endl;
    doc2.print();

    return 0;
}
