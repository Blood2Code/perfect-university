// Задание 6. Самостоятельная работа: иерархия транспортных средств.
// Vehicle -> Car, Motorcycle, Truck.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int year;
    double speed;

public:
    Vehicle(const string& b, int y, double s) : brand(b), year(y), speed(s) {}
    virtual ~Vehicle() {}

    virtual void display() const {
        cout << "ТС: " << brand << ", " << year << " г., макс. скорость: " << speed << " км/ч" << endl;
    }

    virtual double calculateFuelConsumption() const = 0;  // Абстрактный метод
};

class Car : public Vehicle {
private:
    int doors;
    string fuelType;

public:
    Car(const string& b, int y, double s, int d, const string& fuel)
        : Vehicle(b, y, s), doors(d), fuelType(fuel) {}

    double calculateFuelConsumption() const override {
        // Условная модель: чем выше макс. скорость, тем больше расход
        return 5.0 + speed * 0.02;
    }

    void display() const override {
        Vehicle::display();
        cout << "  Тип: Легковой автомобиль" << endl;
        cout << "  Дверей: " << doors << ", топливо: " << fuelType << endl;
        cout << "  Расход топлива: " << calculateFuelConsumption() << " л/100км" << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    string type;  // спорт, туристический, круизер и т.д.

public:
    Motorcycle(const string& b, int y, double s, const string& t)
        : Vehicle(b, y, s), type(t) {}

    double calculateFuelConsumption() const override {
        return 2.5 + speed * 0.01;
    }

    void display() const override {
        Vehicle::display();
        cout << "  Тип: Мотоцикл (" << type << ")" << endl;
        cout << "  Расход топлива: " << calculateFuelConsumption() << " л/100км" << endl;
    }
};

class Truck : public Vehicle {
private:
    double loadCapacity;  // грузоподъемность в тоннах

public:
    Truck(const string& b, int y, double s, double capacity)
        : Vehicle(b, y, s), loadCapacity(capacity) {}

    double calculateFuelConsumption() const override {
        return 15.0 + loadCapacity * 2.0;
    }

    void display() const override {
        Vehicle::display();
        cout << "  Тип: Грузовик" << endl;
        cout << "  Грузоподъемность: " << loadCapacity << " т" << endl;
        cout << "  Расход топлива: " << calculateFuelConsumption() << " л/100км" << endl;
    }
};

int main() {
    cout << "=== Иерархия транспортных средств ===" << endl << endl;

    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Toyota Camry", 2022, 210, 4, "бензин"));
    vehicles.push_back(new Motorcycle("Yamaha R1", 2021, 280, "спортивный"));
    vehicles.push_back(new Truck("Volvo FH", 2020, 130, 20));

    for (Vehicle* v : vehicles) {
        v->display();
        cout << endl;
    }

    for (Vehicle* v : vehicles) delete v;

    return 0;
}
