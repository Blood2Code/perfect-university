#include <iostream>
using namespace std;

int main() {
    double width, height;
    cout << "Введите ширину: ";
    cin >> width;
    cout << "Введите высоту: ";
    cin >> height;

    double area = width * height;
    cout << "Площадь: " << area;
    return 0;
}
