#include <iostream>

using namespace std;

enum gender { MALE, FEMALE };

class Person {
	string name { "" };
	int age{ 0 };
	gender genderType { MALE };
	int weight{ 0 };
	static int counterObject;

public:
	Person() {
		counterObject++;
	}
	~Person(){}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setGender(enum gender gender) {
		this->genderType = gender;
	}
	void setWeight(int weight) {
		this->weight = weight;
	}
	string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	enum gender getGender() const {
		return genderType;
	}
	int getWeight() const {
		return weight;
	}
	static int getCountObject() {
		return counterObject;
	}
	void printSelf() {
		cout << "Номер объекта = " << counterObject << "; Имя - " << name << "; Пол = " << (genderType == MALE ? "мужской" : "женский") << "; Возраст = " << age << "; Вес = " << weight << endl;
	}
};

int Person::counterObject = 0;

class Student : public Person {
	int yearLearning{ 1992 };
public:
	void setYearLearning(int yearLearning) {
		this->yearLearning = yearLearning;
	}
	int getYearLearning() {
		return yearLearning;
	}
	void nextYearLearning(int year) {
		yearLearning += year;
	}
	void printSelf() {
		cout << "Номер объекта = " << getCountObject() << "; Имя - " << getName() << "; Пол = " << (getGender() == MALE ? "мужской" : "женский") << "; Возраст = " << getAge() << "; Вес = " << getWeight() << endl;
	}
};

class Fruit {
protected:
	string name{ "" };
	string color{ "" };
public:
	Fruit() {};
	Fruit(string name, string color) {
		this->name = name;
		this->color = color;
	}
	~Fruit() {}
	string getName() {
		return name;
	}
	string getColor() {
		return color;
	}
};

class Apple : public Fruit {
public:
	Apple(string color = "green") {
		this->name = "apple";
		this->color = color;
	}
	~Apple() {}
};

class Banana : public Fruit {
public:
	Banana(string name = "banana", string color = "yellow") {
		this->name = name;
		this->color = color;
	}
	~Banana() {}
};

class GrannySmith : public Apple {
public:
	GrannySmith() {

		this->name = "Granny Smith apple";
	}
	~GrannySmith() {}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Домашка 1" << endl;
	Student studentIgor;
	studentIgor.setName("Игорь");
	studentIgor.setAge(27);
	studentIgor.setWeight(90);
	studentIgor.setGender(MALE);
	studentIgor.printSelf();
	Student studentSveta;
	studentSveta.setName("Света");
	studentSveta.setAge(25);
	studentSveta.setWeight(50);
	studentSveta.setGender(FEMALE);
	studentSveta.setYearLearning(2022);
	studentSveta.printSelf();
	Student studentDima;
	studentDima.setName("Дима");
	studentDima.setAge(20);
	studentDima.setWeight(70);
	studentDima.setGender(MALE);
	studentSveta.nextYearLearning(1);
	studentDima.printSelf();
	cout << endl;

	cout << "Домашка 2" << endl;
	Apple apple("red");
	Banana banana;
	GrannySmith GrannySmith;
	cout << "My " << apple.getName() << " is " << apple.getColor() << ".\n";
	cout << "My " << banana.getName() << " is " << banana.getColor() << ".\n";
	cout << "My " << GrannySmith.getName() << " is " << GrannySmith.getColor() << ".\n";
	cout << endl;

	cout << "Домашка 3" << endl;
	/*
		Я предпочтку композицию объектов наследованию потому что:
			1 по скольку тут нет смысла в наследовании все объекты отвечают за свои дейтсвия и изолированы по принципу единственной ответсвенности.
			2 мне не нужен будет полиморфизм для подмены тип и проверки в рантайме на общий  тип

		Класс Player (один объект будет игроком, второй ПК)
		Класс Game (класс который будет управлять ходом игры, следить за правилами)
		Класс Render (класс который будет выводить текущие значение объектов на экран)
		Класс Cards (базовый тип карт)
		Итого 4 класса

		Ход программы
		Запускаем цик по флагу, что пользователь хочет выйти и закончить игру или повторить игру
		Создаем объект класcа Game с индикатором начала игры
		Запускаем второй цикл пока индикатор игры не false
		В конструкторе game создаем все необходимые объекты 2 players, render, cards (можно было бы для красоты использщовать service locator или DI conteiner но тут 4 класса так что нет смысла)
		Далее вызываем функцию которая рандомна создаст из Cards вектор размером 54 карты, у класса Cards метод который отдает карту которую еще не отдавал по принципу 2-10 цифры и 4 картинки по 4 масти получаем уникальное количество карт
		в случайном порядке, теперь мы иммем рандомно созданную колоду карт
		ПК (диллер) ходит перывый и сдает себе 2 карты одну видно сразу вторую нет
		затем сдает 2 карты игроку и диллер и игрок видят свои карты
		затем пользователю выводится вопрос еще или хватит
		если хватит то дальше ходит диллер если еще то пользователю сдается еще карта пока не скажет хватит или не будет общая сумма карт > 21 одного очка и игрок проиграет
		после того как игрок сказал хватит он не может набирать краты, диллер открыавет вторую крату затем
		время набирать диллеру основываясь на статистике и видя какое количество очков у игрока диллер может принять решение брать еще или остаться при своем
		так же можно сделать диллера хитрее и проверять следующую карту и если она не даст перебора брать еще (жульничества так многие онлайн казино и работают)
		и на каждой итерации вызывается render что бы вывести на экран пользователю текущее состояние объекта
	*/
	cout << endl;
}
