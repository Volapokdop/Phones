//������ ������� 2-��� ����� ���������� ������

#pragma once
#include <iostream>  //��� cout
#include <string>  //��� string
#include <exception> //��� ������������� this
#include <cstdlib>  //����
#include <vector>  //��� ������������� ��������
#include <fstream> //��� ������������� ������

using namespace std;

int getRandomNumber(int min, int max); //��������� ��������� �����

class Photo {  //����� ��� �������� ���������� � ����
public:
    Photo();  //����������� ����
    Photo(std::string new_name, int new_number, int new_memory);  //����������� ���� � ��������� ����������
    std::string name;  //��������
    int number;  //���������� ���� � ���������� ���������
    int memory;  //������, ������� �������� ����������
    void set_name(std::string new_name);  //������������� ��� ����
    void set_number(int new_number);  //������������� ����� ����
    void set_memory(int new_memory);  //������������� ����� ���������� ������ ����
    std::string get_name();  //���������� ��� ����
    int get_number();  //���������� ����� ����
    int get_memory();  //���������� ����� ���������� ������
};

class Stationary  //������������ �������
{
private:
    bool connect;  //��������� �� � �������
public:
    Stationary(); //�����������
    Stationary(bool new_connect, std::string new_number, float new_length,
        float new_width, float new_high);  //����������� � ��������� ����������
    std::string number;  //�����
    float length,  //�����
        width,     //������
        high;      //������
    void change_number(const std::string& new_number);  //������� �����
    void call(const std::string& new_number);  //���������
    void get_call();  //������� ������
    void get_selfnumber();  //������ ���� �����
    void negconnect();  //���������� / ��������� ������� �� ����
};

class Mobile  : public Stationary  //���������
{
private:
public:
    Mobile();  //����������� ����������
    Mobile(int new_battery, int new_memory, std::string new_oper,
        std::string new_list, std::string new_number, float new_length,
        float new_width, float new_high);  //����������� � ��������� �������
    int battery,  //�����
    memory;  //������
    std::string oper;  //��������
    std::string list;  //������ ���������
    void blaze(); //�������� �������
    void get_oper(); //������ ������ ���������
    void change_oper(const std::string& new_oper); //������� ���������
    void watch_calendar();  //�������� ����
    void watchs();  //�������� �����
    void add_contact(const std::string& contact);  //�������� �������
    void del_contact(const std::string& contact);  //������� �������
    void show_contacts(); //�������� ��������
    float calculate(const std::string& term);  //��������� ��� �����
};

class Smart : public Mobile  //��������
{
private:
    std::vector <Photo*> pmas; //������ ����������
public:
    Smart();  //����������� ���������
    Smart(int new_battery, int new_memory, std::string new_oper,
        std::string new_list, std::string new_number, float new_length,
        float new_width, float new_high, std::vector <Photo*> new_pmas);  //����������� ��������� c ��������� ����������
    void photo(const std::string& img);  //������� ����
    int find_number(const std::string& img); //���������� ����� ����������
    void del_photo(const std::string& img); //������� ���� 
    std::string get_photo(); //�������� ������ ����
};
