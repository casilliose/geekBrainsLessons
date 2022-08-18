#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**

2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, 
инициализирующий x значением параметра. Написать класс Bar, хранящий вещественное число y
 (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
  Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a. 
  В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n. 
  Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
  В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод, означающий задание переместиться на соседнюю позицию.
 Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне). 
 Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения. Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,
  а также выводящую подробную информацию о всех возникающих ошибках. 
 */

class DivisionByZero : public exception
{
    private:
        string m_error;
 
    public:
        DivisionByZero(string error)
            : m_error(error)
        {
        }
 
	 const char* getError() { return m_error.c_str(); }
};
 

template <typename T>
const T div(const T& x, const T& y)
{
    if (y == 0) {
        throw DivisionByZero("Division by zero");
    }
    return x / y;
};

class Ex  : public exception {
    public:
        float x {0.0};
        Ex(float xx): x(xx){}
};

class Bar {
    private:
        float y {0.0};
    public:
        Bar() {
            y = 0;
        }
        void set(float a) {
            if (y + a > 100) {
                throw Ex(a * y);
            }
            y = a;
        }
};

class OffTheField : public exception {
    private:
        string m_error {"OffTheField"};
        int m_x, m_y;
 
    public:
        OffTheField(string error, int x, int y)
            : m_error(error), m_x(x), m_y(y)
        {
        }
 
	 const string getError() { return m_error + "x = " + to_string(m_x) + " y = " + to_string(m_y) ; }
};

class IllegalCommand : public exception {
    private:
        string m_error {"IllegalCommand"};
        int m_x, m_y;
 
    public:
        IllegalCommand(string error, int x, int y)
            : m_error(error), m_x(x), m_y(y)
        {
        }
 
	 const string getError() { return m_error + "x = " + to_string(m_x) + " y = " + to_string(m_y) ; }
};

class Robot {
    private:
        int x {0}, y {0};
        vector<vector<int>> map;
    public:
        Robot() {
            vector<vector<int>> map{10,vector<int>(10, 0)};
            this->map = map;
        }
        void stepTo(int x, int y) {
            if (x < 1 || y < 1) {
                throw OffTheField("You try out map, set y and x more 0", x, y);
            }
            if (x > 10 || y > 10) {
                throw IllegalCommand("max diapazon 10, please set y and x no more 10", x, y);
            }
            this->x = --x;
            this->y = --y;
            map[x][y] = 1;
        }
        void print() {
            for (size_t i = 0; i < 10; i++) {
                for (size_t j = 0; j < 10; j++)
                {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    cout << "Домашка 1" << endl;
    try
    {
        float result = div<float>(3,0);
        cout << "result = " << to_string(result) << endl;
    }
    catch(DivisionByZero &ex)
    {
        cerr << ex.getError() << endl;
    } catch (...) {
        cerr << "error" << endl;
    }
    cout << endl;

    cout << "Домашка 2" << endl;
    Bar bar;
    int n;
    while(true) {
        try {
            cin >> n;
            if (n == 0) break;
            bar.set(n);
        } catch (Ex &ex) {
            cerr << ex.x << endl;
        }
    }
    cout << endl;

    cout << "Домашка 3" << endl;
    try
    {
        Robot robot = Robot();
        robot.stepTo(1,1);
        robot.stepTo(1,2);
        robot.stepTo(2,2);
        robot.print();
        robot.stepTo(-1, 0);
        robot.stepTo(1000, 1000);
    }
    catch(IllegalCommand &ex) {
        cerr << ex.getError() << '\n';
    }
    catch(OffTheField &e)
    {
        cerr << e.getError() << '\n';
    }  catch(...) {
        cerr << "Error is undefauned";
    }
    
    cout << endl;

    return 0;
}
