// Задание 1, часть А. Класс Point — точка на плоскости.
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    Point() : x(0), y(0) {
        cout << "Конструктор по умолчанию: точка создана в (0,0)" << endl;
    }

    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {
        cout << "Конструктор с параметрами: точка создана в ("
             << x << "," << y << ")" << endl;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double value) { x = value; }
    void setY(double value) { y = value; }

    double distanceTo(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1;
    Point p2(3, 4);

    cout << "p1: ";
    p1.display();
    cout << "p2: ";
    p2.display();

    cout << "Расстояние между p1 и p2: " << p1.distanceTo(p2) << endl;

    p1.setX(5);
    p1.setY(12);
    cout << "После изменения p1: ";
    p1.display();
    cout << "Расстояние между p1 и p2: " << p1.distanceTo(p2) << endl;

    return 0;
}
