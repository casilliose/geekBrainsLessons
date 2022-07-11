#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayInt
{
    private:
        uint m_length;
        int *m_data;
        void quickSort(int *numbers, int left, int right)
        {
            int pivot; // разрешающий элемент
            int l_hold = left; //левая граница
            int r_hold = right; // правая граница
            pivot = numbers[left];
            while (left < right) // пока границы не сомкнутся
            {
                while ((numbers[right] >= pivot) && (left < right))
                right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
                if (left != right) // если границы не сомкнулись
                {
                numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
                left++; // сдвигаем левую границу вправо
                }
                while ((numbers[left] <= pivot) && (left < right))
                left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
                if (left != right) // если границы не сомкнулись
                {
                numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
                right--; // сдвигаем правую границу влево
                }
            }
            numbers[left] = pivot; // ставим разрешающий элемент на место
            pivot = left;
            left = l_hold;
            right = r_hold;
            if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
                quickSort(numbers, left, pivot - 1);
            if (right > pivot)
                quickSort(numbers, pivot + 1, right);
        }
    public:
        ArrayInt(): m_length(0), m_data(nullptr){ }
        ArrayInt(uint length):
        m_length(length)
        {
            assert(length >= 0);
            if (length > 0)
                m_data = new int[length];
            else
                m_data = nullptr;
        }
        int get(uint idx) {
            if (m_data == nullptr) {
                throw "Массив не создан";
            }
            return m_data[idx];
        }
        void set(uint idx, int value) {
            if (m_data == nullptr || idx > m_length - 1) {
                throw "Такого индекса нету в массиве";
            }
            m_data[idx] = value;
        }
        void print() {
            for (size_t i = 0; i < m_length; i++)
            {
                cout << m_data[i] << ", ";
            }
        }
        int &operator[] (uint idx) { 
            return m_data[idx];
        }
        void sort() {
            quickSort(m_data, 0, m_length - 1);
        }
        ~ArrayInt()
        {
            delete[] m_data;
        }
        void pop_front() {
            int *new_data = new int[m_length - 1];
            for (size_t i = 1; i < m_length; i++)
            {
                new_data[i-1] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            new_data = nullptr;
            m_length--;
        }
        void pop_back() {
            int *new_data = new int[m_length - 1];
            for (size_t i = 0; i < m_length - 1; i++)
            {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            new_data = nullptr;
            m_length--;
        }
};

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

class Hand {
    int countCards {56};
    vector<Card*> cards;
    public:
        void Add(Card* card) {
            cards.push_back(card);
        }
        void Clear() {
            cards.clear();
        }
        int GetValue(bool aceToeleven) {
            int summa {0};
            for (auto &card : cards) {
                if (card == nullptr) {
                    continue;
                }
                if (aceToeleven == true && card->GetValue() == ACE) {
                    summa += 11;
                } else {
                    summa += (int)card->GetValue();
                }
            }
            return summa;
        }
};

int main() {
    cout << "Домашняя работа 1" << endl;
    ArrayInt cont(6);
    cont.set(0, 4);
    cont.set(1, 2);
    cont.set(2, 6);
    cont.set(3, 7);
    cont[4] = 1;
    cont[5] = 0;
    cout << "массив до сортировки " << endl;
    cont.print();
    cont.sort();
    cout << endl;
    cout << "массив после сортировки  " << endl;
    cont.print();
    cout << endl;
    cont.pop_back();
    cont.print();
    cout << endl;
    cont.pop_front();
    cont.print();
    cout << endl;

    cout << "Домашняя работа 2" << endl;
    vector<int> array2 = { 10, 2, 6, 2, 2, 1 };
    int count = 0;
    bool flag = false;
    for (size_t i = 0; i < 6; i++)
    {
        flag = true;
        for (size_t j = 0; j < 6; j++)
        {
            if (i != j && array2[i] == array2[j]) {
                flag = false;
                break;
            }
        }
        if (flag == true)
            count++;
    }
    cout << "количество элементов без повторений = " << count << endl;
    cout << endl;

    cout << "Домашняя работа 3" << endl;
    
    cout << endl;
    Hand hand;
    Card card(KING, PEAK);
    hand.Add(&card);
    cout << "Сумма карт на руке = " << hand.GetValue(false);
    cout << endl;
    Card card2(ACE, BUBA);
    hand.Add(&card2);
    cout << "Сумма карт на руке = " << hand.GetValue(true);
    cout << endl;
    return 0;
}
