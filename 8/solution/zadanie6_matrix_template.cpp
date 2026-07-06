// Задание 6. Комплексное задание: шаблон класса Matrix для произвольного типа.
#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, vector<T>(cols, T()));
    }

    Matrix(const vector<vector<T>>& init) : rows(init.size()), cols(init[0].size()), data(init) {}

    T& operator()(size_t i, size_t j) {
        if (i >= rows || j >= cols) throw out_of_range("Индекс вне диапазона");
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        if (i >= rows || j >= cols) throw out_of_range("Индекс вне диапазона");
        return data[i][j];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Размеры матриц не совпадают");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Размеры матриц не совпадают");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result(i, j) = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw invalid_argument("Количество столбцов первой матрицы должно равняться количеству строк второй");
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = T();
                for (size_t k = 0; k < cols; ++k) sum += data[i][k] * other.data[k][j];
                result(i, j) = sum;
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result(j, i) = data[i][j];
        return result;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m) {
        for (size_t i = 0; i < m.rows; ++i) {
            for (size_t j = 0; j < m.cols; ++j) {
                os << m.data[i][j];
                if (j < m.cols - 1) os << "\t";
            }
            os << endl;
        }
        return os;
    }

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }
};

int main() {
    cout << "=== Тестирование шаблона Matrix ===" << endl;

    Matrix<int> m1(2, 3);
    m1(0, 0) = 1; m1(0, 1) = 2; m1(0, 2) = 3;
    m1(1, 0) = 4; m1(1, 1) = 5; m1(1, 2) = 6;

    cout << "Матрица m1 (2x3):" << endl;
    cout << m1;

    Matrix<int> m2(2, 3);
    m2(0, 0) = 7; m2(0, 1) = 8; m2(0, 2) = 9;
    m2(1, 0) = 10; m2(1, 1) = 11; m2(1, 2) = 12;

    cout << "\nМатрица m2 (2x3):" << endl;
    cout << m2;

    Matrix<int> m3 = m1 + m2;
    cout << "\nm1 + m2:" << endl;
    cout << m3;

    Matrix<int> m4(3, 2);
    m4(0, 0) = 1; m4(0, 1) = 2;
    m4(1, 0) = 3; m4(1, 1) = 4;
    m4(2, 0) = 5; m4(2, 1) = 6;

    cout << "\nМатрица m4 (3x2):" << endl;
    cout << m4;

    Matrix<int> m5 = m4.transpose();
    cout << "Транспонированная m4:" << endl;
    cout << m5;

    Matrix<double> m6(2, 2);
    m6(0, 0) = 1.5; m6(0, 1) = 2.5;
    m6(1, 0) = 3.5; m6(1, 1) = 4.5;

    cout << "\nМатрица double:" << endl;
    cout << m6;

    return 0;
}
