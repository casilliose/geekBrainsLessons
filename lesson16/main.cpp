#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <regex>
#include <algorithm>
#include <optional>

using namespace std;

tuple<string,string,string> extractFio(string line) {
    const regex r(R"(([^0-9)(+ \r\n])+)");
    vector<string> map;
    for(sregex_iterator i = sregex_iterator(line.begin(), line.end(), r); i != std::sregex_iterator(); ++i)
    {
        smatch m = *i;
        map.push_back(m.str());
    }
    map.push_back("");
    tuple<string,string,string> personFio(map[0], map[1], map[2]);
    return personFio;
}

tuple<uint,uint,string,uint> extractPhone(string line) {
    const regex r(R"((\w+))");
    vector<string> map;
    for(sregex_iterator i = sregex_iterator(line.begin(), line.end(), r); i != std::sregex_iterator(); ++i)
    {
        smatch m = *i;
        map.push_back(m.str());
    }
    map.push_back("0");
    tuple<uint,uint,string,uint> phone(
        stoi(map[0]),
        stoi(map[1]),
        map[2], 
        stoi(map[3])
    );
    return phone;
}

class Person {
    public:
        string lastName;
        optional<string> middleName {nullopt};
        string name;
        Person() : lastName(""), name(""), middleName("") {}
        Person(string h, string s, optional<string> m) : lastName(h), name(s), middleName(m) {}
        friend bool operator< (const Person& p1, const Person& p2);
        friend bool operator== (const Person& p1, const Person& p2);
};

ostream& operator << (ostream &os, const Person &p)
{
    return os << p.lastName << " " << p.name << " " << (p.middleName.has_value() ? p.middleName.value() : "")  << " ";
}

bool operator<(const Person& p1, const Person& p2)
{
    return tie(p1.name, p1.middleName.value(), p1.lastName) < tie(p2.name, p2.middleName.value(), p2.lastName);
}

bool operator==(const Person& p1, const Person& p2)
{
    return tie(p1.name, p1.middleName.value(), p1.lastName) == tie(p2.name, p2.middleName.value(), p2.lastName);
}

class PhoneNumber {
    public:
        uint codeContry;
        uint codeCity;
        string number;
        optional<uint> dopNumber {nullopt};
        PhoneNumber() : codeContry(0), codeCity(0), number(""), dopNumber(0){}
        PhoneNumber(uint cCountry, uint cCity, string n, optional<uint> dopN) : codeContry(cCountry), codeCity(cCity), number(n), dopNumber(dopN) {}
        friend bool operator< (const PhoneNumber& p1, const PhoneNumber& p2);
        friend bool operator== (const PhoneNumber& p1, const PhoneNumber& p2);
};

ostream& operator << (ostream &os, const PhoneNumber &p)
{
    if (p.dopNumber.has_value() && p.dopNumber.value() != 0) {
        return os << "+" << p.codeContry << " (" << p.codeCity << ") " << p.number << " " << p.dopNumber.value();
    }
    return os << "+" << p.codeContry << " (" << p.codeCity << ") " << p.number << " ";
}

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.codeContry, p1.codeCity, p1.number, p1.dopNumber.value()) < tie(p2.codeContry, p2.codeCity, p2.number, p2.dopNumber.value());
}

bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.codeContry, p1.codeCity, p1.number, p1.dopNumber.value()) == tie(p2.codeContry, p2.codeCity, p2.number, p2.dopNumber.value());
}

class PhoneBook {
    public:
        vector<tuple<Person,PhoneNumber>> mapPersonAndNumber;
        PhoneBook() = default;
        PhoneBook(ifstream &ifstr) {
            if (ifstr.is_open())
            {
                string line;
                while (ifstr.good())
                {
                    getline(ifstr, line);
                    if (line.size() > 0) {
                        tuple<string,string,string> personExt = extractFio(line);
                        tuple<uint,uint,string,uint> phoneExt = extractPhone(line);
                        Person pers(get<0>(personExt), get<1>(personExt), get<2>(personExt));
                        PhoneNumber phone(get<0>(phoneExt), get<1>(phoneExt), get<2>(phoneExt), get<3>(phoneExt));
                        tuple<Person,PhoneNumber> personPhone(pers, phone);
                        mapPersonAndNumber.push_back(personPhone);
                    }
                }
                ifstr.close();
            }
        }
        void SortByName() {
            sort(
                mapPersonAndNumber.begin(), 
                mapPersonAndNumber.end(), 
                [](tuple<Person,PhoneNumber> first, tuple<Person,PhoneNumber> second)
                {
                    if (get<0>(first).lastName == get<0>(second).lastName && get<0>(first).name == get<0>(second).name) {
                        return get<0>(first).middleName < get<0>(second).middleName;
                    } else if (get<0>(first).lastName == get<0>(second).lastName) {
                        return get<0>(first).name < get<0>(second).name;
                    }
                    return get<0>(first).lastName < get<0>(second).lastName;
                }
            );
        }
        void SortByPhone() {
            sort(
                mapPersonAndNumber.begin(), 
                mapPersonAndNumber.end(), 
                [](tuple<Person,PhoneNumber> first, tuple<Person,PhoneNumber> second)
                {
                    if (
                        get<1>(first).codeContry == get<1>(second).codeContry && 
                        get<1>(first).codeCity == get<1>(second).codeCity &&
                        get<1>(first).number == get<1>(second).number
                    ) {
                        return get<1>(first).dopNumber > get<1>(second).dopNumber;
                    } else if (
                        get<1>(first).codeContry == get<1>(second).codeContry && 
                        get<1>(first).codeCity == get<1>(second).codeCity 
                    ) {
                        return get<1>(first).number > get<1>(second).number;
                    } else if (get<1>(first).codeContry == get<1>(second).codeContry) {
                        return get<1>(first).codeCity > get<1>(second).codeCity;
                    }
                    return get<1>(first).codeContry > get<1>(second).codeContry;
                }
            );
        }
        tuple<string,PhoneNumber> GetPhoneNumber(string lastName) {
            tuple<string, PhoneNumber> findPhoneNumber;
            uint count {0};
            for_each(
                mapPersonAndNumber.begin(),
                mapPersonAndNumber.end(),
                [&, lastName](const auto& item) {
                    if (get<0>(item).lastName == lastName) {
                        if (count == 0) {
                            get<1>(findPhoneNumber).codeContry = get<1>(item).codeContry;
                            get<1>(findPhoneNumber).codeCity = get<1>(item).codeCity;
                            get<1>(findPhoneNumber).number = get<1>(item).number;
                            get<1>(findPhoneNumber).dopNumber = get<1>(item).dopNumber;
                        }
                        count++;
                    }
                }
            );
            if (count > 1) {
                get<0>(findPhoneNumber) = "found more than 1";
                return findPhoneNumber;
            } else if (count < 1) {
                get<0>(findPhoneNumber) = "not found";
                return findPhoneNumber;
            }
            get<0>(findPhoneNumber) = "";
            return findPhoneNumber;
        }
        void ChangePhoneNumber(Person pers, PhoneNumber numb) {
            for_each(
                mapPersonAndNumber.begin(),
                mapPersonAndNumber.end(),
                [=](auto& item) {
                    if (
                        get<0>(item).lastName == pers.lastName &&
                        get<0>(item).name == pers.name
                    ) {
                        if (
                            !pers.middleName.has_value() ||
                            pers.middleName.value() == get<0>(item).middleName.value()
                        ) {
                            get<1>(item).codeCity = numb.codeCity;
                            get<1>(item).codeContry = numb.codeContry;
                            get<1>(item).number = numb.number;
                            get<1>(item).dopNumber = numb.dopNumber;
                        }
                    }
                }
            );
        }
};

ostream& operator << (ostream &os, const PhoneBook &p)
{
    for (size_t i = 0; i < p.mapPersonAndNumber.size(); i++) {
        os << get<0>(p.mapPersonAndNumber[i]) << " " << get<1>(p.mapPersonAndNumber[i]) << endl;
    }
    return os;
}

int main() {
    ifstream file("1b33f2ada7aa3d25a74c4ca948acb5a3.txt");
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };
    print_phone_number("Иванов");
    print_phone_number("Петров");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Котов", "Василий", "Елисееевич"}, PhoneNumber{7, 123, "15344458", nullopt});
    book.ChangePhoneNumber(Person{ "Миронова", "Маргарита", "Владимировна" }, PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;
}