#include <iostream>

namespace MyNameSpace {

    static float * arr;
    static int sizeArr;

    struct PositiveAndOdd {
        int positive;
        int negative;
    };

    void initArray() {
        std::cout << "Введите размер массива : " << std::endl;
        int n {0}, count {0};
        float number {0};
        std::cin >> n;
        sizeArr = n;
        float arrFloat[n];
        do {
            std::cout << "Введите float число с индеком №" << count << std::endl;
            std::cin >> number;
            arrFloat[count] = number;
            count++;
        } while (count < n);
        arr = arrFloat;
    }

    void printArray() {
        for (size_t i = 0; i < sizeArr; i++)
        {
            std::cout << arr[i] << (i == sizeArr ? "" : ", ");
        }
        std::cout << std::endl;
    }

    void countEvenAndOdd() {
        PositiveAndOdd PositiveAndOdd;
        PositiveAndOdd.positive = 0;
        PositiveAndOdd.negative = 0;
        for (size_t i = 0; i < sizeArr; i++)
        {
            if (arr[i] > 0) {
                PositiveAndOdd.positive++;
            } else {
                PositiveAndOdd.negative++;
            }
        }
        std::cout << "Количество позитивных элементов в массиве = " << PositiveAndOdd.positive << std::endl;
        std::cout << "Количество отрицательных элементов в массиве = " << PositiveAndOdd.negative << std::endl;
    }

}