// Задание 5. Класс Matrix — перегрузка оператора индексации [][] через вспомогательный класс.
#include <iostream>
using namespace std;

class MatrixRow {
private:
    double* row;
    int cols;

public:
    MatrixRow(double* r, int c) : row(r), cols(c) {}

    double& operator[](int col) {
        if (col < 0 || col >= cols) throw out_of_range("Индекс столбца вне диапазона");
        return row[col];
    }

    const double& operator[](int col) const {
        if (col < 0 || col >= cols) throw out_of_range("Индекс столбца вне диапазона");
        return row[col];
    }
};

class Matrix {
private:
    double** data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) data[i][j] = 0;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) delete[] data[i];
        delete[] data;
    }

    MatrixRow operator[](int row) {
        if (row < 0 || row >= rows) throw out_of_range("Индекс строки вне диапазона");
        return MatrixRow(data[row], cols);
    }

    const MatrixRow operator[](int row) const {
        if (row < 0 || row >= rows) throw out_of_range("Индекс строки вне диапазона");
        return MatrixRow(data[row], cols);
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) cout << data[i][j] << "\t";
            cout << endl;
        }
    }
};

int main() {
    Matrix m(3, 4);

    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j) {
            m[i][j] = i * m.getCols() + j + 1;
        }
    }

    cout << "Матрица 3x4:" << endl;
    m.display();

    cout << "\nЭлемент m[1][2] = " << m[1][2] << endl;

    m[2][3] = 99;
    cout << "\nПосле изменения m[2][3] = 99:" << endl;
    m.display();

    return 0;
}
