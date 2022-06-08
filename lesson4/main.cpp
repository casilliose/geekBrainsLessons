#include <iostream>

using namespace std;

uint16_t const d {10};
uint16_t const s {2};

bool isSimpleNumber(int32_t number)
{
    if (number <= 1) {
        return false;
    }
    for (size_t i = number - 1; i > 1; i--) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // домашка 1
    uint16_t a {0};
    uint16_t b {0};
    cout << "Домашнее задание 1" << endl;
    cout << "Введите первое число :" << endl;
    cin >> a;
    cout << "Первое число :" << a << endl;
    cout << "Введите второе число :" << endl;
    cin >> b;
    cout << "Второе число число :" << b << endl;
    auto c = a + b;
    cout << "Сумма числа a + b = " << c << endl;
    if (c >= 10 && c <= 20) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl << endl;

    // // домашка 2
    cout << "Домашнее задание 2" << endl;
    if (d+s == 10 || (s == 10 && d == 10)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << endl << endl;

    // // домашка 3
    cout << "Домашнее задание 3" << endl;
    cout << "Нечетные числа от 1 до 50 : ";
    for (size_t i = 1; i <= 50; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl << endl;

    // // домашка 4
    cout << "Домашнее задание 4" << endl;
    uint16_t const x {6};
    uint16_t const y {6};
    uint16_t matrix[x][y] {0};
    for (size_t i = 0; i < x; i++) {
        matrix[i][i] = 1;
    }
    for (size_t i = 0; i < x; i++) {
        for (size_t j = 0; j < y; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;

    // // домашка 5
    uint64_t l {1};
    cout << "Домашнее задание 5" << endl;
    cout << "Введите любое число от 0" << endl;
    cin >> l;
    cout << (isSimpleNumber(l) ? "Это простое число" : "Это не простое число");
    cout << endl << endl;

    // домашка 6
    cout << "Домашнее задание 6" << endl;
    cout << "Введите (год): от 1 до 3000" << endl;
    uint16_t year {1};
    cin >> year;
    if (year % 400 == 0) {
        cout << "Год : " << year << " Весокосный" << endl;
    } else if (year % 100 == 0) {
        cout << "Год : " << year << " Не весокосный" << endl;
    } else if (year % 4 == 0) {
        cout << "Год : " << year << " Весокосный" << endl;
    } else {
        cout << "Год : " << year << " Не весокосный" << endl;
    }
    return 0;
}
