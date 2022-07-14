#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Pair1 {
    T firstT;
    T secondT;
public:
    Pair1(T m_fist, T m_second) {
        firstT = m_fist;
        secondT = m_second;
    }
    
    T first() const {
        return firstT;
    }
    T second() const {
        return secondT;
    }
};

template <class Type1, class Type2>
class Pair {
    Type1 i;
    Type2 j;
public:
    Pair (Type1 a, Type2 b){
        i = a;
        j = b;
    };
    Type1 first() const {
        return i;
    }
    Type2 second() const {
        return j;
    }
};


// единсвенный способ как получилось сделать, видимо я чего то в шаблонах недоганяю
template <class T, class size>
class StaticArray_Base
{
};

template <class size>
class StringValuePair: public StaticArray_Base<string, size>
{
    string str;
    size sc;
    public:
        StringValuePair(string m_str, size s) {
            str = m_str;
            sc = s;
        }
        string first() {
            return str;
        }
        size second() {
            return sc;
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

class GenericPlayer : public Hand {
    string name {""};
    const int MaxScore {21};
    public:
        virtual bool IsHitting() = 0;
        bool IsBoosted() {
            return GetValue(false) && GetValue(true) > MaxScore ? true : false;
        }
        void Bust() {
            cout << "У игрока: " << name << " перебор";
        }
};

int main() {
    cout << "Домашка 1" << endl;
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    cout << endl;

    cout << "Домашка 2" << endl;
    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
    cout << endl;

    cout << "Домашка 3" << endl;
    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    cout << endl;

    cout << "Домашка 4" << endl;

    cout << endl;
    return 0;
}
