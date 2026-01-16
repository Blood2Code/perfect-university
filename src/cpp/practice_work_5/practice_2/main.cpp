#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите N: ";
    cin >> n;

    int sum = 0;
    int i = 1;

    while (i <= n) {
        sum += i;
        i++;
    }

    cout << "Сумма = " << sum;
    return 0;
}
