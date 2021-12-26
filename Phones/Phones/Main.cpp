//Создал студент 2-ого курса Подкопалов Андрей

#include "Shoulders.h"

using namespace std;
int main() {
	setlocale(0, "ru");
	Stationary iris;  //создаём телефон класса Stationary
	iris.get_selfnumber(); //узнаём собственный номер
	iris.change_number("875123");  //меняем свой номер на другой
	iris.call("875123");  //звоним самому себе
	iris.call("861233");  //звоним, но нам не отвечают
	iris.negconnect(); //перерубаем провод
	iris.call("534123");  //не можем позвонить
	Mobile nokia;  //создаём телефон класса Mobile
	nokia.get_oper(); //узнаём своего оператора. Это МТС. Огорчаемся
	nokia.get_selfnumber(); //узнаём собственный номер
	nokia.change_oper("Билайн"); //меняем оператора
	nokia.get_selfnumber(); //смотрим, как изменился номер
	nokia.show_contacts();  //отображаем контакты
	nokia.add_contact("Лёха"); //пытаемся добавить существующий контакт
	nokia.add_contact("Миша"); // добавляем контакт
	nokia.add_contact("Работа"); // добавляем контакт
	nokia.del_contact("Я"); //удаляем контакт
	nokia.show_contacts();  //отображаем контакты
	cout << nokia.calculate("8*9") << "\n"; //считаем выражение
	Smart apple;  //создаём телефон класса Smart
	apple.get_photo(); //просматриваем фотографии
	apple.photo("Селфи"); //фотаем себя
	apple.photo("Селфи"); //фотаем себя
	apple.photo("Селфи"); //фотаем себя
	apple.del_photo("Селфи2"); //удаляем неудачный снимок
	apple.get_photo(); //просматриваем фотографии
}