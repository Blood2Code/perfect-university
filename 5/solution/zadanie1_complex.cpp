// Задание 1. Класс Complex — перегрузка арифметических операторов.
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Оператор + как функция-член
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Оператор - как функция-член
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Оператор * как функция-член: (a+bi)*(c+di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // Оператор / — дружественная функция
    friend Complex operator/(const Complex& a, const Complex& b);

    friend ostream& operator<<(ostream& os, const Complex& c);
};

Complex operator/(const Complex& a, const Complex& b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0) {
        cout << "Ошибка: деление на ноль!" << endl;
        return Complex(0, 0);
    }
    double r = (a.real * b.real + a.imag * b.imag) / denominator;
    double i = (a.imag * b.real - a.real * b.imag) / denominator;
    return Complex(r, i);
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) os << " + " << c.imag << "i";
    else os << " - " << -c.imag << "i";
    return os;
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << "c1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << prod << endl;
    cout << "c1 / c2 = " << quot << endl;

    return 0;
}
