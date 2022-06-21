#include <iostream>
#include "mylib.h"

#define isRANGE(search, range) (search > range || search < 0 ? false : true)

#define ARRSIZE 10

#define SwapINT(a, b) (x=a,a=b,b=x)

int main()
{
    std::cout << "Домашнее задание 1" << std::endl;
    MyNameSpace::initArray();
    MyNameSpace::printArray();
    MyNameSpace::countEvenAndOdd();
    std::cout << std::endl;

    std::cout << "Домашнее задание 2" << std::endl;
    std::cout << "Введите число и диапазон" << std::endl;
    int search, range;
    std::cin >> search;
    std::cin >> range;
    std::cout << std::boolalpha << isRANGE(search,range) << std::endl;
    std::cout << std::endl;
    
    std::cout << "Домашнее задание 3" << std::endl;
    uint64_t arr[ARRSIZE];
    uint64_t number {0}, count {0};
    do {
        std::cout << "Введите int число с индеком №" << count << std::endl;
        std::cin >> number;
        arr[count] = number;
        count++;
    } while (count < ARRSIZE);
    int size = ARRSIZE, x, a;
    for(size_t i = 0; i < ARRSIZE; i++) {           
        for(size_t j = size-1; j > i; j--) {
            if (arr[j-1] > arr[j]) {
                SwapINT(arr[j-1], arr[j]);
            }
        }
    }
    for (size_t i = 0; i < ARRSIZE; i++)
    {
        std::cout << arr[i] << (i == ARRSIZE ? "" : ", ");
    }
    std::cout << std::endl;

    std::cout << "Домашнее задание 4" << std::endl;
    #pragma pack(push, 1)
    struct student
    {
        std::string firstName;
        std::string lastName;
        std::string birthday;
        int groupNumber;
    };
    #pragma pack(pop)
    std::cout << sizeof(student) << std::endl;
    

    return 0;
}