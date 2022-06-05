#include <iostream>
#include "extern.cpp"

using namespace std;

extern const int a,b,c,d;

int main()
{
    setlocale(LC_ALL, "Russian");
    // home work 1 and 4
    cout << "a * (b + (c / d)) = " << a * (b + (static_cast<float>(c) / d)) << endl;
    cout << endl;
    cout << endl;

    // home work 2
    int g;
    cout << "Введите целое число : " << endl;
    cin >> g;
    cout << (g <= 21 ? (21 - g) : ((g-21) * 2)) << endl;
    cout << endl;
    cout << endl;

    // home work 3
    int Array[3][3][3] {
        {{1,2,3},{4,5,6},{7,8,9}},
        {{10,11,12},{13,14,15},{16,17,18}},
        {{19,20,21},{22,23,24},{25,26,27}},
    }, *ptrArr;
    ptrArr = &Array[1][1][1];
    cout << "Array[1][1][1] = " << (*ptrArr) << endl;
    return 0;
}