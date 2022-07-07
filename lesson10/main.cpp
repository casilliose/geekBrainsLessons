#include <iostream>
#include <cmath>

using namespace std;

class Figure {
    public:
        virtual double area() = 0;
};

class Parallelogram : public Figure {
    public:
        Parallelogram() {}
        virtual double area() = 0;
};

class Rectangle : public Parallelogram {
    double length {1};
    double width {1};
    public:
        Rectangle (double length, double width) {
            this->length = length;
            this->width = width;
        }
        double area() {
            return length * width;
        }
};

class Square : public Parallelogram {
    double side {1};
    public:
        Square (double side) {
            this->side = side;
        }
        double area() {
            return side * side;
        }
};

class Rhombus : public Parallelogram {
    double diagonalFirst {1};
    double diagonalSecond {1};
    public:
        Rhombus (double diagonalFirst, double diagonalSecond) {
            this->diagonalFirst = diagonalFirst;
            this->diagonalSecond = diagonalSecond;
        }
        double area() {
            return (diagonalFirst * diagonalSecond) / 2;
        }
};

class Circle : public Figure {
    double radius {0};
    public:
        Circle (double radius) {
            this->radius = radius;
        }
        double area() {
            return M_PI * pow(radius, 2);
        }
};

class Car {
    string company {""};
    string model {""};
public:
    Car() {
        cout << "Car" << endl;
    }
};

class PassengerCar : public Car {
public:
    PassengerCar() {
        cout << "PassengerCar" << endl;
    }
};

class Bus : public Car {
public:
    Bus() {
        cout << "Bus" << endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan() {
        cout << "Minivan" << endl;
    }
};

class Fraction {
    int numerator;
    int denominator;
    public:
        Fraction(int numerator, int denominator) {
            this->numerator = numerator;
            if (denominator <= 0) {
                cout << "Знаменатель не может быть 0 или меньше" << endl;
                exit(0);
            }
            this->denominator = denominator;
        }

        int getNumerator() const {
            return numerator;
        }

        int getDenominator() const {
            return denominator;
        }

        Fraction operator- () const {
            return Fraction(numerator - 1, denominator - 1);
        }

        Fraction operator+ () const {
            return Fraction(numerator + 1, denominator + 1);
        }
};

Fraction operator+(const Fraction &d1, const Fraction &d2)
{
    return Fraction(d1.getNumerator() + d2.getNumerator(), d1.getDenominator() + d2.getDenominator());
}

Fraction operator-(const Fraction &d1, const Fraction &d2)
{
    return Fraction(d1.getNumerator() - d2.getNumerator(), d1.getDenominator() - d2.getDenominator());
}

Fraction operator/(const Fraction &d1, const Fraction &d2)
{
    return Fraction(d1.getNumerator() / d2.getNumerator(), d1.getDenominator() / d2.getDenominator());
}

Fraction operator*(const Fraction &d1, const Fraction &d2)
{
    return Fraction(d1.getNumerator() * d2.getNumerator(), d1.getDenominator() * d2.getDenominator());
}

bool operator ==(const Fraction &d1, const Fraction &d2)
{
    return d1.getNumerator() == d2.getNumerator() && d1.getDenominator() == d2.getDenominator();
}

bool operator != (const Fraction &d1, const Fraction &d2)
{
    return d1.getNumerator() != d2.getNumerator() && d1.getDenominator() != d2.getDenominator(); 
}

bool operator<(const Fraction &d1, const Fraction &d2)
{
    return d1.getNumerator() < d2.getNumerator();
}

bool operator>(const Fraction &d1, const Fraction &d2)
{
    return d1.getNumerator() > d2.getNumerator();
}

bool operator>=(const Fraction &d1, const Fraction &d2)
{
    return d1.getNumerator() <= d2.getNumerator();
}

bool operator<=(const Fraction &d1, const Fraction &d2)
{
    return d1.getNumerator() >= d2.getNumerator();
}

enum TypeCard {TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7,  EIGHT = 8, NINE = 9, TEN = 10, JACK = 10, LADY = 10, KING = 10, ACE = 1};

enum SuitCard {PEAK = 1, BUBA = 2, BAPTIIZE = 3, CHIRVA = 4};

class Card {
    TypeCard type;
    SuitCard suit;
    bool isOpen {false};
    public:
        Card (TypeCard type, SuitCard suit) {
            this->type = type;
            this->suit = suit; 
        }
        ~Card () {}
        void Flip() {
            isOpen = !isOpen;
        }
        TypeCard GetValue() {
            return type;
        }
        SuitCard GetSuit() {
            return suit;
        }
};

int main() {
    cout << "Домашнее задани 1" << endl;
    Rectangle rectangl(2.2, 4);
    cout << "Площадь прямоугольника = " << rectangl.area() << endl;
    Square sq(2.10);
    cout << "Площадь квадрата = " << sq.area() << endl;
    Rhombus romb(3.0, 2.1);
    cout << "Площадь ромба = " << romb.area() << endl;
    Circle cicle(2);
    cout << "Площадь круга = " << cicle.area() << endl;
    cout << endl;

    cout << "Домашнее задани 2" << endl;
    Car Car;
    PassengerCar PassengerCar;
    Bus Bus;
    Minivan Minivan;
    cout << endl;

    cout << "Домашнее задани 3" << endl;
    Fraction Fraction1(2,5);
    Fraction Fraction2(1,2);
    Fraction summa = Fraction1 + Fraction2;
    cout << "сложение = " << summa.getNumerator() << " / " << summa.getDenominator() << endl;
    Fraction subtraction = Fraction1 - Fraction2;
    cout << "вычитание = " << subtraction.getNumerator() << " / " << subtraction.getDenominator()  << endl;
    Fraction division = Fraction1 / Fraction2;
    cout << "деление = " << division.getNumerator() << " / " << division.getDenominator()  << endl;
    Fraction multiplication = Fraction1 * Fraction2;
    cout << "умножение = " << multiplication.getNumerator() << " / " << multiplication.getDenominator()  << endl;
    Fraction dec = -Fraction1;
    cout << "декремент = " << dec.getNumerator() << " / " << dec.getDenominator()  << endl;
    Fraction inc = +Fraction1;
    cout << "сравнение == " << std::boolalpha << (inc == dec) << endl;
    cout << "обратное стравнение != " << std::boolalpha << (inc != dec) << endl;
    cout << "меньше != " << std::boolalpha << (inc < dec) << endl;
    cout << "больше != " << std::boolalpha << (inc > dec) << endl;
    cout << "меньше или равно != " << std::boolalpha << (inc <= dec) << endl;
    cout << "больше или равно != " << std::boolalpha << (inc >= dec) << endl;
    cout << endl;
    return 0;
}