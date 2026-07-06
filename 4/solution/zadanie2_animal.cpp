// Задание 2. Виртуальные функции и полиморфизм: Animal -> Dog, Cat, Cow.
#include <iostream>
#include <vector>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(const string& n) : name(n) {}

    virtual ~Animal() {}

    virtual void speak() const {
        cout << name << " издает звук" << endl;
    }

    virtual void move() const {
        cout << name << " двигается" << endl;
    }

    string getName() const { return name; }
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(const string& n, const string& b) : Animal(n), breed(b) {}

    void speak() const override {
        cout << name << " (" << breed << ") лает: Гав-гав!" << endl;
    }

    void move() const override {
        cout << name << " бегает на четырех лапах" << endl;
    }

    void fetch() const {
        cout << name << " приносит палку" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& n) : Animal(n) {}

    void speak() const override {
        cout << name << " мяукает: Мяу-мяу!" << endl;
    }

    void move() const override {
        cout << name << " крадется бесшумно" << endl;
    }
};

class Cow : public Animal {
public:
    Cow(const string& n) : Animal(n) {}

    void speak() const override {
        cout << name << " мычит: Му-у-у!" << endl;
    }

    void move() const override {
        cout << name << " медленно идет" << endl;
    }
};

void makeSound(const Animal& animal) {
    cout << "Звук: ";
    animal.speak();
}

int main() {
    cout << "=== Полиморфизм: массив указателей на Animal ===" << endl;

    Animal* animals[4];
    animals[0] = new Dog("Бобик", "Овчарка");
    animals[1] = new Cat("Мурка");
    animals[2] = new Cow("Буренка");
    animals[3] = new Dog("Шарик", "Дворняга");

    for (int i = 0; i < 4; i++) {
        animals[i]->speak();
        animals[i]->move();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) delete animals[i];

    cout << "=== Функция, работающая полиморфно ===" << endl;
    Dog dog("Рекс", "Немецкая овчарка");
    Cat cat("Симба");
    Cow cow("Зорька");

    makeSound(dog);
    makeSound(cat);
    makeSound(cow);

    return 0;
}
