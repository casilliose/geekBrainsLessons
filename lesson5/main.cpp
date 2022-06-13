#include <iostream>
#include <cmath>

using namespace std;

void printArray(double doubleArray[], uint64_t size);
void printArray(uint32_t * intArray, uint64_t size);

void intArrayChanger(uint32_t * intArray, uint64_t size);
void addElemInEmptyArray(uint32_t * emptyArray, uint64_t size);
void offsetArrayByN(uint32_t * offsetArray, int32_t n, uint64_t size);
bool checkBalance(uint32_t * checkArray, uint64_t size);

int main ()
{
    // Домашняя работа 1
    cout << "Домашняя работа 1" << endl;
    double doubleArray[] {1.3,2.1,3.5,4.10323};
    uint64_t size {4};
    printArray(doubleArray, size);
    cout << endl << endl;

    // Домашняя работа 2
    cout << "Домашняя работа 2" << endl;
    uint32_t intArray[] {1, 1, 0, 0, 1, 0, 1, 1, 0, 0};
    uint64_t intSizeArray = sizeof(intArray) / sizeof(intArray[0]);
    intArrayChanger(intArray, intSizeArray);
    printArray(intArray, intSizeArray);
    cout << endl << endl;

    // Домашняя работа 3
    cout << "Домашняя работа 3" << endl;
    uint8_t sizeEmptyArray {8};
    uint32_t intEmptyArray[sizeEmptyArray];
    addElemInEmptyArray(intEmptyArray, sizeEmptyArray);
    printArray(intEmptyArray, sizeEmptyArray);
    cout << endl << endl;

    // Домашняя работа 4
    cout << "Домашняя работа 4" << endl;
    uint32_t n {0};
    uint64_t sizeArr;
    cout << "Введите смещение -n до n+" << endl;
    cin >> n;
    uint32_t offsetArray[] = {1,2,3};
    sizeArr = sizeof(offsetArray) / sizeof(offsetArray[0]);
    offsetArrayByN(offsetArray, n, sizeArr);
    cout << endl << endl;

    // Домашняя работа 5
    cout << "Домашняя работа 5" << endl;
    uint32_t checkArray[] {7,1,2,3,1,14};
    uint64_t sizeCheckBalance;
    sizeCheckBalance = sizeof(checkArray) / sizeof(checkArray[0]);
    if (checkBalance(checkArray, sizeCheckBalance)) {
        cout << "Сумма левой и правой части равны";
    } else {
        cout << "Сумма левой и правой части неравны";
    }

    cout << endl;

    return 0;
}


bool checkBalance(uint32_t * checkArray, uint64_t size)
{
    uint64_t summLeft {0}, summRight {0};

    for (size_t i = 0; i < size; i++) {
        summLeft += checkArray[i];
        summRight = 0;
        for (size_t j = i + 1; j < size; j++) {
            summRight += checkArray[j];
        }
        if (summLeft == summRight) {
            return true;
        }
    }

    return summLeft == summRight;
}

void offsetArrayByN(uint32_t * offsetArray, int32_t n, uint64_t size)
{
    if (n == 0) {
        return;
    }
    uint32_t newArray[size];
    if (n < 0) {
        for (size_t i = 0; i < size; i++)
        {
            int32_t findNewIndex = i;
            for (size_t j = 1; j <= abs(n); j++) {
                if (findNewIndex - 1 < 0) {
                    findNewIndex = size - 1;
                } else {
                    findNewIndex -= 1;
                }
            }
            newArray[findNewIndex] = offsetArray[i];
        }
    } else {
        for (size_t i = 0; i < size; i++)
        {
            uint32_t findNewIndex = i;
            for (size_t j = 1; j <= n; j++) {
                if (findNewIndex + 1 >= size) {
                    findNewIndex = 0;
                } else {
                    findNewIndex += 1;
                }
            }
            newArray[findNewIndex] = offsetArray[i];
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        cout << newArray[i] << (i >= size - 1 ? " " : ", ");
    }
}

void addElemInEmptyArray(uint32_t * emptyArray, uint64_t size)
{
    uint8_t currentSum = 0;
    for (size_t i = 0; i < size; i++)
    {
        emptyArray[i] = (currentSum < 1 ?  currentSum = 1 : currentSum += 3);
    }
}

void printArray(double * doubleArray, uint64_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << doubleArray[i] << (i >= size - 1 ? " " : ", ");
    }
}

void printArray(uint32_t * intArray, uint64_t size)
{
    size_t i = 0;
    for (size_t i = 0; i < size; i++) 
    {
        cout << intArray[i] << (i >= size - 1 ? " " : ", ");
    }
}

void intArrayChanger(uint32_t * intArray, uint64_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        intArray[i] = intArray[i] == 1 ? 0 : 1;
    }
}