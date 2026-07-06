// Задание 2. Класс Fraction — перегрузка операторов сравнения.
#include <iostream>
#include <algorithm>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd_val = gcd(abs(numerator), denominator);
        if (gcd_val != 0) {
            numerator /= gcd_val;
            denominator /= gcd_val;
        }
    }

    int gcd(int a, int b) const {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        reduce();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Две дроби равны, если numerator * other.denominator == other.numerator * denominator
    // (перекрёстное умножение — работает без чисел с плавающей точкой и их погрешностей)
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Fraction& other) const {
        return (*this > other) || (*this == other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
    if (f.denominator == 1) {
        os << f.numerator;
    } else {
        os << f.numerator << "/" << f.denominator;
    }
    return os;
}

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(3, 4);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;

    cout << "\nСравнение f1 и f2:" << endl;
    cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << endl;
    cout << "f1 != f2: " << (f1 != f2 ? "true" : "false") << endl;

    cout << "\nСравнение f1 и f3:" << endl;
    cout << "f1 < f3: " << (f1 < f3 ? "true" : "false") << endl;
    cout << "f1 > f3: " << (f1 > f3 ? "true" : "false") << endl;
    cout << "f1 <= f3: " << (f1 <= f3 ? "true" : "false") << endl;
    cout << "f1 >= f3: " << (f1 >= f3 ? "true" : "false") << endl;

    return 0;
}
