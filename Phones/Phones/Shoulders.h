//Создал студент 2-ого курса Подкопалов Андрей

#pragma once
#include <iostream>  //для cout
#include <string>  //для string
#include <exception> //для использования this
#include <cstdlib>  //надо
#include <vector>  //для использования векторов
#include <fstream> //для использования файлов

using namespace std;

int getRandomNumber(int min, int max); //генератор случайных чисел

class Photo {  //класс для хранения информации о фото
public:
    Photo();  //конструктор фото
    Photo(std::string new_name, int new_number, int new_memory);  //конструктор фото с заданными значениями
    std::string name;  //название
    int number;  //количество фото с одинаковым названием
    int memory;  //память, которую занимает фотография
    void set_name(std::string new_name);  //устанавливаем имя фото
    void set_number(int new_number);  //устанавливаем номер фото
    void set_memory(int new_memory);  //устанавливаем объём занимаемой памяти фото
    std::string get_name();  //возвращаем имя фото
    int get_number();  //возвращаем номер фото
    int get_memory();  //возвращаем объём занимаемой памяти
};

class Stationary  //стационарный телефон
{
private:
    bool connect;  //подключён ли к проводу
public:
    Stationary(); //конструктор
    Stationary(bool new_connect, std::string new_number, float new_length,
        float new_width, float new_high);  //конструктор с заданными значениями
    std::string number;  //номер
    float length,  //длина
        width,     //ширина
        high;      //высота
    void change_number(const std::string& new_number);  //сменить номер
    void call(const std::string& new_number);  //позвонить
    void get_call();  //принять звонок
    void get_selfnumber();  //узнать свой номер
    void negconnect();  //подключить / отключить телефон от сети
};

class Mobile  : public Stationary  //мобильник
{
private:
public:
    Mobile();  //конструктор мобильника
    Mobile(int new_battery, int new_memory, std::string new_oper,
        std::string new_list, std::string new_number, float new_length,
        float new_width, float new_high);  //конструктор с заданными числами
    int battery,  //заряд
    memory;  //память
    std::string oper;  //оператор
    std::string list;  //список контактов
    void blaze(); //зарядить телефон
    void get_oper(); //узнать своего оператора
    void change_oper(const std::string& new_oper); //сменить оператора
    void watch_calendar();  //смотреть дату
    void watchs();  //смотреть время
    void add_contact(const std::string& contact);  //добавить контакт
    void del_contact(const std::string& contact);  //удалить контакт
    void show_contacts(); //показать контакты
    float calculate(const std::string& term);  //посчитать два числа
};

class Smart : public Mobile  //смартфон
{
private:
    std::vector <Photo*> pmas; //вектор фотографий
public:
    Smart();  //конструктор смартфона
    Smart(int new_battery, int new_memory, std::string new_oper,
        std::string new_list, std::string new_number, float new_length,
        float new_width, float new_high, std::vector <Photo*> new_pmas);  //конструктор смартфона c заданными значениями
    void photo(const std::string& img);  //сделать фото
    int find_number(const std::string& img); //возвращает номер фотографии
    void del_photo(const std::string& img); //удалить фото 
    std::string get_photo(); //показать список фото
};
