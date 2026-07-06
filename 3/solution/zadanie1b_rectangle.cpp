// Задание 1, часть Б. Класс Rectangle — конструктор копирования и деструктор.
#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {
        cout << "Создан прямоугольник " << width << "x" << height << endl;
    }

    Rectangle(const Rectangle& other)
        : width(other.width), height(other.height) {
        cout << "Создана копия прямоугольника" << endl;
    }

    ~Rectangle() {
        cout << "Удалён прямоугольник " << width << "x" << height << endl;
    }

    double getArea() const { return width * height; }
    double getPerimeter() const { return 2 * (width + height); }

    void display() const {
        cout << "Прямоугольник: " << width << " x " << height
             << ", площадь = " << getArea()
             << ", периметр = " << getPerimeter() << endl;
    }

    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

int main() {
    cout << "=== Создание объектов ===" << endl;
    Rectangle r1(5, 3);
    Rectangle r2 = r1;  // Конструктор копирования

    cout << "\n=== Информация о прямоугольниках ===" << endl;
    r1.display();
    r2.display();

    cout << "\n=== Изменение r1 ===" << endl;
    r1.setWidth(10);
    r1.display();

    cout << "\n=== Выход из программы (деструкторы будут вызваны автоматически) ===" << endl;
    return 0;
}
