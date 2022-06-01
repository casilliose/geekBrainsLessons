#include <iostream>
#include <variant>
#include <string>
#include <cassert>
#include "part.cpp"

using namespace std;

extern int bb;
static int ttt;

std::string str {""};

void tttTest()
{
    ttt = 333;
    bb = 111;
    cout << "ttt : " << ttt << endl;
    cout << "bb : " << bb << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    short int shInt {1};
    int iInt {2};
    long long ll {12312312312312132};
    char ch = '@';
    bool bl {false};
    float fl {1.32};
    double db (2.23232323232322323);
    uint16_t t {0};

    // странно что так можно
    register auto b {1}; 
    int c (1100);
    int d [1000];
    
    enum crossZero {cross, zero};
    typedef enum crossZero LOGICAL;
    LOGICAL testl;
    testl = cross;
    LOGICAL data[9];
    LOGICAL data2[9] = {cross,cross,zero,cross,zero,cross,zero,zero,zero};
    for (size_t i = 0; i < sizeof(data); i++) {
        data[i] = i % 2 == 0 ? cross : zero;
    }

    struct MapCrossZeroGame {
        crossZero MapGame[3][3];
        typedef struct gamerFirst {
            string IP {""};
            string Name {""};
            crossZero whoDoesHePlay {cross};
        } first;
        typedef struct gamerSecond {
            string IP {""};
            string Name {""};
            crossZero whoDoesHePlay {zero};
        } second;
        uint8_t howWin : 1;
        uint8_t whoseMove : 1;
    };

    struct MyVariant {
        union MyData {
            int a;
            float b;
            char c;
        } gg;
        uint isInt : 1;
        uint isFloat : 1;
        uint isChar : 1;
    };

    MyVariant variant1;

    variant1 = {34, 1, 0, 0};
    cout << "Вариант 1 - Int" << endl;
    cout << "Значение : " << variant1.gg.a << " isInt : " << variant1.isInt << " isFloat : " << variant1.isFloat << " isChar : " << variant1.isChar << endl;

    //variant2 = {1.1, 0, 1, 1};//такой формат выдает ошибку 
    /*
    error: narrowing conversion of ‘1.2e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
   82 |     variant2 = {{1.2}, 0, 1, 1};
      |                               
    */ 
    variant1.gg.b = 2.22;
    variant1.isInt = 0;
    variant1.isFloat = 1;
    variant1.isChar = 0;
    cout << "Вариант 2 - Float" << endl;
    cout << "Значение : " << variant1.gg.b << " isInt : " << variant1.isInt << " isFloat : " << variant1.isFloat << " isChar : " << variant1.isChar << endl;

    variant1 = {'G', 0, 0, 1};
    cout << "Вариант 3 -Char" << endl;
    cout << "Значение : " << variant1.gg.c << " isInt : " << variant1.isInt << " isFloat : " << variant1.isFloat << " isChar : " << variant1.isChar << endl;
 
    cout << endl;
    cout << endl;
    cout << endl;

    std::variant<int, float> v, w;
    v = 12; // v содержит int
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v);
    cout << "variant std w" << i << endl;

    // тестил работу переменных
    struct person {
    char name[10];
    char surname[10];
    int age;
    float salary;
    };
    person test5;
    test5 = {"igor", "branitsky", 77,2000.00};
    person test6[10];
    union example_U {
        int i;
        char c;
        float f;
        };
    union example_U x;
    x.i = 2.1;
    x.c = 'c';
    cout << "union x.i : " << x.i << endl;
    cout << "union x.c : " << x.c << endl;
    cout << testl << endl;
    cout << "Введите что хотите !!!" << endl;
    auto a = 'b';
    volatile char port;
    port = 'a';
    const auto gg {'b'};
    cin >> a;
    cin >> b;
    cout << "Ввели в a : " << a << endl;
    cout << "Ввели в b : " << b << endl;
    cout << "Ввели в c : " << c << endl;
    cout << "Ввели в d : " << d << endl;
    bb  = {1231};
    showExt();
    {
        // хрень ниже выдает странные ошибки но компилится
        /* /usr/bin/ld: /tmp/ccriFbmS.o: warning: relocation against `_Z4ssssB5cxx11' in read-only section `.text'
        /usr/bin/ld: /tmp/ccriFbmS.o: in function `main':
        main.cpp:(.text+0x2f2): undefined reference to `ssss[abi:cxx11]'
        /usr/bin/ld: warning: creating DT_TEXTREL in a PIE
        collect2: error: ld returned 1 exit status
        */
        // extern std::string ssss; 
        // {
        //     cout << "ssss : " << ssss << endl;
        // }
        str = "lol";
    }
    cout << "LOl : " << str << endl;
    // cout << "ssss : " << ssss << endl; обратно не работает ток в нутрь
    tttTest();
    return 0;
}

