// Задание 3. Абстрактный класс Figure и производные Square, Circle, Triangle.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Figure {
public:
    virtual ~Figure() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void display() const = 0;
};

class Square : public Figure {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double getArea() const override { return side * side; }
    double getPerimeter() const override { return 4 * side; }

    void display() const override {
        cout << "Квадрат: сторона = " << side
             << ", площадь = " << getArea()
             << ", периметр = " << getPerimeter() << endl;
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override { return M_PI * radius * radius; }
    double getPerimeter() const override { return 2 * M_PI * radius; }

    void display() const override {
        cout << "Круг: радиус = " << radius
             << ", площадь = " << getArea()
             << ", периметр = " << getPerimeter() << endl;
    }
};

class Triangle : public Figure {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3)
        : a(side1), b(side2), c(side3) {}

    double getArea() const override {
        double p = getPerimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    double getPerimeter() const override { return a + b + c; }

    void display() const override {
        cout << "Треугольник: стороны = " << a << ", " << b << ", " << c
             << ", площадь = " << getArea()
             << ", периметр = " << getPerimeter() << endl;
    }
};

int main() {
    cout << "=== Абстрактный класс Figure ===" << endl;

    // Figure f;  // Ошибка! Нельзя создать объект абстрактного класса

    vector<Figure*> figures;
    figures.push_back(new Square(5));
    figures.push_back(new Circle(3));
    figures.push_back(new Triangle(3, 4, 5));

    for (Figure* f : figures) f->display();

    for (Figure* f : figures) delete f;

    return 0;
}
