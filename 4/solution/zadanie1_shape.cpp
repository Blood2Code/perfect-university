// Задание 1. Иерархия Shape -> Rectangle, Circle, Triangle.
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const string& c = "белый") : color(c) {
        cout << "Конструктор Shape: " << color << endl;
    }

    ~Shape() {
        cout << "Деструктор Shape" << endl;
    }

    void setColor(const string& c) { color = c; }
    string getColor() const { return color; }

    void display() const {
        cout << "Фигура цвета: " << color << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h, const string& c = "белый")
        : Shape(c), width(w), height(h) {
        cout << "Конструктор Rectangle: " << width << " x " << height << endl;
    }

    ~Rectangle() {
        cout << "Деструктор Rectangle" << endl;
    }

    double getArea() const { return width * height; }
    double getPerimeter() const { return 2 * (width + height); }

    void display() const {
        Shape::display();
        cout << "Прямоугольник: " << width << " x " << height
             << ", площадь = " << getArea()
             << ", периметр = " << getPerimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, const string& c = "белый")
        : Shape(c), radius(r) {}

    double getArea() const { return 3.14159 * radius * radius; }

    void display() const {
        Shape::display();
        cout << "Круг: радиус = " << radius
             << ", площадь = " << getArea() << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h, const string& c = "белый")
        : Shape(c), base(b), height(h) {}

    double getArea() const { return 0.5 * base * height; }

    void display() const {
        Shape::display();
        cout << "Треугольник: основание = " << base
             << ", высота = " << height
             << ", площадь = " << getArea() << endl;
    }
};

int main() {
    cout << "=== Создание объекта Rectangle ===" << endl;
    Rectangle rect(5, 3, "красный");

    cout << "\n=== Информация ===" << endl;
    rect.display();

    cout << "\n=== Изменение цвета ===" << endl;
    rect.setColor("синий");
    rect.display();

    cout << "\n=== Классы Circle и Triangle ===" << endl;
    Circle circle(4, "желтый");
    Triangle triangle(6, 3, "зеленый");

    circle.display();
    triangle.display();

    cout << "\n=== Уничтожение объектов ===" << endl;
    return 0;
}
