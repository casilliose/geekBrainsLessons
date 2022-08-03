#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool is_number(const string& s)
{
    return !s.empty() && find_if(s.begin(), 
        s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

template< class CharT, class Traits >
basic_ostream<CharT, Traits>& endll(basic_ostream<CharT, Traits>& os )
{
    os.put(os.widen('\n'));
    os.put(os.widen('\n'));
    os.flush();
 
    return os;
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
        TypeCard GetValue() const {
            return type;
        }
        SuitCard GetSuit() const {
            return suit;
        }
        friend ostream& operator<< (ostream &out, const Card &card);
};

ostream& operator<< (ostream &out, const Card &card) {
    if (card.isOpen == true) {
        out << "XX";
    } else {
        out << to_string(card.GetSuit()) << " " << to_string(card.GetValue());
    }
    return out;
}

class Hand {
    size_t countCards {56};
    vector<Card*> cards {countCards, nullptr};
    public:
        void Add(Card* card) {
            cards.push_back(card);
        }
        void Clear() {
            for (int i = 0; i < 56; i++) {
                delete[] cards[i];
            }
            cards.clear();
        }
        int GetValue(bool aceToeleven) const {
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
        void openFistCard() {
            return cards.front()->Flip();
        }
        string getCardsForPrint() const {
            string cardsString {""};
            for (auto &card : cards) {
                if (card == nullptr) {
                    continue;
                }
                cardsString += to_string(card->GetSuit()) + " " + to_string(card->GetValue());
            }
            return cardsString;
        }
};

class GenericPlayer : public Hand {
    const int MaxScore {21};
    public:
        string name {""};
        virtual bool IsHitting() = 0;
        bool IsBoosted() {
            return GetValue(false) && GetValue(true) > MaxScore ? true : false;
        }
        void Bust() {
            cout << "У игрока: " << name << " перебор";
        }
        friend ostream& operator<< (ostream &out, const GenericPlayer &player);
};

ostream& operator<< (ostream &out, const GenericPlayer &player) {
    out << player.name << " " << player.getCardsForPrint() << " сумма туз 1 = " << to_string(player.GetValue(false)) << " сумма туз 11 = " << to_string(player.GetValue(true));
    return out;
}

class Player : public GenericPlayer {
    public:
        bool IsHitting() const {
            cout << name << " еще карту ? введите да или нет " << endl;
            string input;
            cin >> input;
            return input == "да";
        }
        void Win() const {
            cout << name << " выйграл" << endl;
        }
        void Lose() const {
            cout << name << " проиграл" << endl;
        }
        void Push() const {
            cout << name << " ничья" << endl;
        }
};

class House : public GenericPlayer {
    public:
        bool IsHitting() const {
            const int minScoreDiler {16};
            return GetValue(false) < minScoreDiler && GetValue(true) < minScoreDiler;
        }
        void FlipFirstCard() {
            openFistCard();
        }
};

int main() {
    cout << "Домашка 1" << endl;
    string numberChar;
    int number {0};
    while (true) {
        cout << "Введите число : " << endl;
        cin >> numberChar;
        if (is_number(numberChar)) {
            number = stoi(numberChar);
            cout << "Вы ввели число : " << number << endl;
            break;
        }
        cerr << "Введите число, это не число : " << numberChar << endl;
    }
    cout << endl;

    cout << "Домашка 2" << endl;
    cout << "После этой строки должно быть 2 переноса строки и " << endll;
    cout << endl;
    
    return 0;
}
