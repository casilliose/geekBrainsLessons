#include <iostream>
#include <memory>

using namespace std;


/**
 * @brief 
 * 
 * 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям. Перегрузите оператор вывода для данного класса.
 *  Создайте два "умных" указателя today и date. 
 * Первому присвойте значение сегодняшней даты. 
 * Для него вызовите по отдельности методы доступа к полям класса Date, 
 * а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода. Затем переместите ресурс,
 *  которым владеет указатель today в указатель date. 
 * Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.
 * 
2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
• Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date и сравнивает их между собой (сравнение происходит по датам).
 Функция должна вернуть более позднюю дату.
• Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.

Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров
 */

class Date {
    private:
        uint day {1};
        uint month {1};
        uint year {1};
    public:
        uint getDay() const {
            return day;
        }
        void setDay(uint day) {
            this->day = day;
        }
        uint getMonth() const {
            return month;
        }
        void setMonth(uint month) {
            this->month = month;
        }
        uint getYear() const {
            return year;
        }
        void setYear(uint year) {
            this->year = year;
        }
        Date() {}
        ~Date(){}
        friend ostream& operator<< (ostream &out, const Date &date);
};

ostream& operator<< (ostream &out, const Date &date) {
    out << (date.getDay() < 10 ? "0" : "") << to_string(date.getDay()) << "-" << (date.getMonth() < 10 ? "0" : "") << to_string(date.getMonth()) << "-" << to_string(date.getYear());
    return out;
}

const Date* compareDate(const Date* const date1, const Date* const date2) {
    if ((*date1).getYear() > (*date2).getYear()) {
        return date1;
    }
    if ((*date1).getMonth() > (*date2).getMonth()) {
        return date1;
    }
    if ((*date1).getDay() > (*date2).getDay()) {
        return date1;
    }
    return date2;
}

void exchange(Date* const date1, Date* const date2) {
    uint day = (*date1).getDay();
    uint month = (*date1).getMonth();
    uint year = (*date1).getYear();
    (*date1).setDay((*date2).getDay());
    (*date1).setMonth((*date2).getMonth());
    (*date1).setYear((*date2).getYear());
    (*date2).setDay(day);
    (*date2).setMonth(month);
    (*date2).setYear(year);
}

int main() {
    cout << "Домашка 1" << endl;
    unique_ptr<Date> today = make_unique<Date>();
    auto date = make_unique<Date>();
    (*today).setDay(8);
    (*today).setMonth(8);
    (*today).setYear(2022);
    (*today).getDay();
    (*today).getMonth();
    (*today).getYear();
    cout << (*today);
    cout << endl;
    date = move(today);
    cout << "if make_unique and move" << endl;
    cout << "date is nullptr = " << boolalpha << (date == nullptr) << endl;
    cout << "today is nullptr = " << boolalpha << (today == nullptr) << endl;

    cout << "if make_shared and =" << endl;
    shared_ptr<Date> today2 = make_shared<Date>();
    shared_ptr<Date> today3 = make_shared<Date>();
    (*today2).setDay(8);
    (*today2).setMonth(8);
    (*today2).setYear(2022);
    today3 = today2;
    cout << "today3 is nullptr = " << boolalpha << (today3 == nullptr) << endl;
    cout << "today2 is nullptr = " << boolalpha << (today2 == nullptr) << endl;
    cout << endl;
    
    cout << "Домашка 2" << endl;
    unique_ptr<Date> date1 = make_unique<Date>();
    unique_ptr<Date> date2 = make_unique<Date>();
    (*date1).setDay(11);
    (*date1).setMonth(11);
    (*date1).setYear(2011);
    (*date2).setDay(9);
    (*date2).setMonth(8);
    (*date2).setYear(2022);
    cout << "compare" << endl;
    auto compare = compareDate(date1.get(), date2.get());
    cout << (*compare) << endl;
    cout << "exchange" << endl;
    exchange(date1.get(), date2.get());
    cout << (*date1) << endl;
    cout << (*date2) << endl;
    cout << endl;
    return 0;
}
