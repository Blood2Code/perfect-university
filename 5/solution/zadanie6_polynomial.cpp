// Задание 6. Класс Polynomial — комплексное задание по перегрузке операторов.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial {
private:
    vector<double> coeffs;  // coeffs[i] — коэффициент при x^i

    void trim() {
        while (coeffs.size() > 1 && coeffs.back() == 0) coeffs.pop_back();
    }

public:
    Polynomial() : coeffs(1, 0) {}
    Polynomial(const vector<double>& c) : coeffs(c) { trim(); }
    Polynomial(double c) : coeffs(1, c) {}

    double& operator[](size_t i) {
        if (i >= coeffs.size()) coeffs.resize(i + 1, 0);
        return coeffs[i];
    }

    const double& operator[](size_t i) const {
        if (i >= coeffs.size()) throw out_of_range("Индекс вне диапазона");
        return coeffs[i];
    }

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = max(coeffs.size(), other.coeffs.size());
        vector<double> result(maxSize, 0);
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] += other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t maxSize = max(coeffs.size(), other.coeffs.size());
        vector<double> result(maxSize, 0);
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] -= other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        size_t newSize = coeffs.size() + other.coeffs.size() - 1;
        vector<double> result(newSize, 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            for (size_t j = 0; j < other.coeffs.size(); ++j)
                result[i + j] += coeffs[i] * other.coeffs[j];
        return Polynomial(result);
    }

    // Оператор () — вычисление значения многочлена в точке x (схема Горнера-подобная сумма степеней)
    double operator()(double x) const {
        double result = 0;
        double power = 1;
        for (size_t i = 0; i < coeffs.size(); ++i) {
            result += coeffs[i] * power;
            power *= x;
        }
        return result;
    }

    int degree() const { return coeffs.size() - 1; }

    friend ostream& operator<<(ostream& os, const Polynomial& p);
};

ostream& operator<<(ostream& os, const Polynomial& p) {
    if (p.coeffs.size() == 1 && p.coeffs[0] == 0) {
        os << "0";
        return os;
    }

    bool first = true;
    for (int i = (int)p.coeffs.size() - 1; i >= 0; --i) {
        double coef = p.coeffs[i];
        if (coef == 0) continue;

        if (!first) {
            os << (coef > 0 ? " + " : " - ");
            coef = abs(coef);
        } else {
            if (coef < 0) { os << "-"; coef = -coef; }
            first = false;
        }

        if (i == 0) {
            os << coef;
        } else {
            if (coef != 1) os << coef;   // коэффициент 1 перед x не печатаем
            os << "x";
            if (i > 1) os << "^" << i;
        }
    }
    return os;
}

int main() {
    Polynomial p1({1, 2, 3});   // 3x^2 + 2x + 1
    Polynomial p2({1, 1});      // x + 1
    Polynomial p3({1, 0, -1});  // -x^2 + 1

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;

    cout << "\np1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;

    cout << "\np1(2) = " << p1(2) << endl;
    cout << "p2(3) = " << p2(3) << endl;

    cout << "\nКоэффициенты p1: ";
    for (int i = 0; i <= p1.degree(); ++i) cout << "x^" << i << ":" << p1[i] << " ";
    cout << endl;

    p1[1] = 5;
    cout << "После изменения p1[1] = 5: " << p1 << endl;

    return 0;
}
