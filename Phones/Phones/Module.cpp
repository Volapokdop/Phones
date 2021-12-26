//Создал студент 2-ого курса Подкопалов Андрей

#include "Shoulders.h"

int getRandomNumber(int min, int max)  //генерация слуйного числа в заданном диапазоне
{
	srand(time(0));
	const double fraction = 1.0 / (double(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return int(rand() * fraction * (max - min + 1) + min);
}

Photo::Photo() {  //конструктор фото
	name = "";
	number = 0;
	memory = 0;
}

Photo::Photo(std::string new_name, int new_number, int new_memory) {  //конструктор фото с заданными значениями
	this->name = new_name;
	this->number = new_number;
	this->memory = new_memory;
}

Stationary::Stationary() {  //конструктор стационарного телефона
	connect = 1;
	number = std::to_string(getRandomNumber(100000, 999999));
	length = 15;
	width = 20;
	high = 15;
}

Stationary::Stationary(bool new_connect, std::string new_number, 
	float new_length, float new_width, float new_high) {  //конструктор с заданными значениями
	this->connect = new_connect;
	this->number = new_number;
	this->length = new_length;
	this->width = new_width;
	this->high = new_high;
}

Mobile::Mobile() {  //конструктор мобильника
	battery = 100;
	memory = 5;
	oper = "МТС";
	number = "7914" + std::to_string(getRandomNumber(1000000, 9999999));
	length = 8;
	width = 2;
	high = 4;
	list = "Список контактов:\nМама\nЛёха\nЯ\n";
}

Mobile::Mobile(int new_battery, int new_memory, std::string new_oper,
	std::string new_list, std::string new_number, float new_length,
	float new_width, float new_high) {//конструктор с заданными числами
	battery = new_battery;
	memory = new_memory;
	oper = new_oper;
	number = new_number;
	length = new_length;
	width = new_width;
	high = new_high;
	list = new_list;
}

Smart::Smart() {  //конструктор смартфона
	battery = 100;
	memory = 2048;
	oper = "МТС";
	number = "7914" + std::to_string(getRandomNumber(1000000, 9999999));
	length = 12;
	width = 1;
	high = 5;
	list = "Список контактов:\nМама\nЛёха\nЯ\n";
	pmas.push_back(new Photo());;
	pmas[0]->set_name("Селфи");
	pmas[0]->set_number(0);
	pmas[0]->set_memory(256);
}

Smart::Smart(int new_battery, int new_memory, std::string new_oper,
	std::string new_list, std::string new_number, float new_length,
	float new_width, float new_high, std::vector <Photo*> new_pmas) {  //конструктор смартфона c заданными значениями
	battery = new_battery;
	memory = new_memory;
	oper = new_oper;
	number = new_number;
	length = new_length;
	width = new_width;
	high = new_high;
	list = new_list;
	pmas = new_pmas;
}

void Photo::set_number(int new_number) { //счётчик количества фотографий с одинаковым именем
	this->number = new_number;
}

void Photo::set_memory(int new_memory) {  //количество памяти, которую занимает фотография
	this->memory = new_memory;
}

void Photo::set_name(std::string new_name) {  //устанавливаем имя фото
	this->name = new_name;
}

std::string Photo::get_name() {  //возвращаем имя фото
	return name;
}

int Photo::get_number() {  //возвращаем номер фото
	return number;
}

int Photo::get_memory() {  //возвращаем объём занимаемой памяти
	return memory;
}

int Smart::find_number(const std::string& img) {  //определяет номер фотографии
	int k = 0;
	for (int i = 0; i < pmas.size(); i++) {
		if (pmas[i]->get_name() == img and pmas[i]->get_number() > k)
			k = pmas[i]->get_number();
	}
	return k+1;
}

void Stationary::change_number(const std::string& new_number) {  //сменить номер
	if (new_number.length() == 6 and number.length() == 6) 
		this->number = new_number;
	else
		if (new_number.length() == 7 and number.length() == 11)
			this->number = number.substr(0, 4) + new_number;
		
	else
		std::cout << "Введён неправильный номер\n";
}

void Stationary::call(const std::string& new_number) {  //позвонить
	if (connect==0)
		std::cout << "Вы не можете позвонить, вы не подключены к телефонной сети\n";
	else
	if (new_number.length() != 6 and new_number.length() != 11)
		std::cout << "Введён неправильный номер\n";
	else
		if (new_number == number)
			std::cout << "Нельзя позвонить самому себе\n";
		else
			std::cout << "Вам не отвечают\n";
}

void Stationary::negconnect() {  //подключить / отключить телефон от сети
	if (connect == 0) {
		this->connect = 1;
		std::cout << "Вы успешно подключились\n";
	}
	else {
		this->connect = 0;
		std::cout << "Вы успешно оборвали провод\n";
	}
}

void Stationary::get_call() {  //принять звонок
	if (number.length() == 6)
		if (connect == 0)
			std::cout << "Вы не подключены к телефонной сети\n";
		else
			std::cout << "Это оказался телефонный розыгрыш. Вы расстроились\n";
	else
		std::cout << "Это оказался телефонный розыгрыш. Вы расстроились\n";
}

void Stationary::get_selfnumber() {  //узнать свой номер
	std::cout << "Ваш номер: " + number + "\n";
}

void Mobile::blaze() { //зарядить телефон
	this->battery = 100;
	std::cout << "Телефон заряжен\n";
}

void Mobile::get_oper() {//узнать своего оператора
	std::cout << "Ваш оператор: " + oper + "\n";
}

void Mobile::change_oper(const std::string& new_oper) { //сменить оператора
	std::string o;
	if (battery != 0) {
		this->battery -= 1;
		if (new_oper == "МТС" or new_oper == "Мегафон" or new_oper == "Билайн") {
			this->oper = new_oper;
			if (new_oper == "МТС")
				o = "914";
			else
				if (new_oper == "Мегафон")
					o = "924";
				else
					if (new_oper == "Билайн")
						o = "960";
			this->number = "7" + o + number.substr(4, 7);
		}
		else
			std::cout << "Не существует такого оператора\n";
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

void Mobile::watch_calendar() {  //смотреть дату
	if (battery != 0) {
		this->battery -= 1;
		std::cout << "25.12.2021\n";
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

void Mobile::watchs() {  //смотреть время
	if (battery != 0) {
		this->battery -= 1;
		std::cout << "15:17\n";
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

void Mobile::add_contact(const std::string& contact) {  //добавить контакт
	if (battery != 0) {
		if (memory > 0) {
			this->battery -= 1;
			this->memory -= 1;
			if (list.find(contact, 0) > list.length())
				this->list += contact + "\n";
			else
				std::cout << "Такой контакт уже есть\n";
		}
		else
			std::cout << "Нет свободной памяти\n";
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}


void Mobile::del_contact(const std::string& contact) {  //удалить контакт
	if (battery != 0) {
		this->battery -= 1;
		this->memory += 1;
		if (list.find(contact, 0) <= list.length())
			this->list = list.erase(list.find(contact, 0), contact.length()+1);
		else
			std::cout << "Нет такого контакта\n";
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

void Mobile::show_contacts() {  //показать контакты
	if (battery != 0) {
		this->battery -= 1;
		std::cout << list;
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

float Mobile::calculate(const std::string& term) {  //посчитать два числа
	float a;
	int t1, t2, t3, t4, l;  //одна из переменных принимает значение позиции найденного знака, остальные -1 
	t1 = term.find("+");
	t2 = term.find("-");
	t3 = term.find("*");
	t4 = term.find("/");
	l = term.length();
	if (battery != 0) {
		this->battery -= 2; 
		if (t1 >= 0)
			a = stof(term.substr(0, t1)) + stof(term.substr(t1 + 1, l));
		else
			if (t2 >= 0)
				a = stof(term.substr(0, t2)) - stof(term.substr(t2 + 1, l));
			else
				if (t3 >= 0)
					a = stof(term.substr(0, t3)) * stof(term.substr(t3 + 1, l));
				else
					a = stof(term.substr(0, t4)) / stof(term.substr(t4 + 1, l));
		return a;
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

void Smart::photo(const std::string& img) {  //сделать фото
	int s = rand()%301+200;
	int k = pmas.size();
	if (battery != 0) {
		this->battery -= 2;
		if (memory - s >= 0) {
			pmas.push_back(new Photo());;
			pmas[k]->set_name(img);
			pmas[k]->set_number(find_number(img));
			pmas[k]->set_memory(s);
			std::cout << "Вы успешно сфотографировали " + img + "\n";
			this->memory -= s;
		}
		else
			std::cout << "Не хватает памяти на телефоне\n";
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

void Smart::del_photo(const std::string& img) { //удалить фото
	int i, j = 0;
	std::string k;
	bool x = 0;  //счётчик, есть ли фотография в списке
	if (battery != 0) {
		this->battery -= 2;
		for (i = 0; i < pmas.size(); i++) {
			if (pmas[i]->get_number() != 0)
				k = std::to_string(pmas[i]->get_number());
			else
				k = "";
			if (pmas[i]->get_name()+k == img) {
				x = 1;
				break;
			}
		}
		if (x == 0)
			std::cout << "Фотографии с таким именем не существует";
		else {
			memory += pmas[j]->get_memory();
			for (j = i; j < pmas.size() - 1; j++) {
				pmas[j]->set_name(pmas[j + 1]->get_name());
				pmas[j]->set_number(pmas[j + 1]->get_number());
				pmas[j]->set_memory(pmas[j + 1]->get_memory());
			}
			pmas.pop_back();
		}
	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}

std::string Smart::get_photo() { //показать список фото
	if (battery != 0) {
		this->battery -= 2;
		std::string s;
		for (int i = 0; i < pmas.size(); i++) {
			s += pmas[i]->get_name();
			if (pmas[i]->get_number() != 0)
				s += std::to_string(pmas[i]->get_number());
			s += " " + std::to_string(pmas[i]->get_memory()) + " кб\n";
		}
		std::cout << ("Список фотографий:\n" + s);
		return ("Список фотографий:\n" + s);

	}
	else
		std::cout << "Ваш телефон разряжен\n";
	if (battery < 0)
		this->battery = 0;
}