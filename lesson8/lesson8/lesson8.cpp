#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

class Power {
private:
    float FirstNumber;
    float SecondNumber;
public:
    Power(float FirstNumber, float SecondNumber) {
        this->FirstNumber = FirstNumber;
        this->SecondNumber = SecondNumber;
    }
    ~Power() {}
    void set(float NumberValue) {
        FirstNumber = NumberValue;
    }
    void set(float NumberValue, bool isSecondNumber) {
        SecondNumber = NumberValue;
    }
    void calculate() {
        cout << "Степень числа " << FirstNumber << " в числе " << SecondNumber << " = " << pow(FirstNumber, SecondNumber) << endl;
    }
};

class RGBA {
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA() : m_red{ 0 }, m_green{ 0 }, m_blue{ 0 }, m_alpha{ 255 } {}
    RGBA(uint8_t m_red, uint8_t m_green, uint8_t m_blue, uint8_t m_alpha) {
        this->m_red = m_red;
        this->m_green = m_green;
        this->m_blue = m_blue;
        this->m_alpha = m_alpha;
    }
    ~RGBA(){}
    void print() {
        cout << "Red : " << m_red << "; Green : " << m_green << "; Blue : " << m_blue << "; Alpha : " << m_alpha << endl;
    }
};

class Stack {
    int countElement;
    int arrNumber[10];
public:
    Stack() {
        countElement = 0;
        reset();
    }
    ~Stack(){}
    void reset() {
        for (size_t i = 0; i < 10; i++)
        {
            arrNumber[i] = 0;
        }
    }
    int pop() {
        int number = arrNumber[countElement];
        arrNumber[countElement] = 0;
        countElement--;
        return number;
    }
    void push(int number) {
        arrNumber[countElement] = number;
        countElement++;
    }
    void print() {
        cout << "( ";
        for (size_t i = 0; i < countElement; i++)
        {
            cout << arrNumber[i] << " ";
        }
        cout << ")" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Домашнее задание 1" << endl;
    Power power{2,3};
    power.calculate();
    power.set(3);
    power.set(2, true);
    power.calculate();
    cout << endl;

    std::cout << "Домашнее задание 2" << endl;
    RGBA rgb;
    rgb.print();
    RGBA rgb2{1,1,1,240};
    rgb2.print();
    cout << endl;

    std::cout << "Домашнее задание 3" << endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    cout << endl;

    return 0;
}
