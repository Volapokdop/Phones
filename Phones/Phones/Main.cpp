//������ ������� 2-��� ����� ���������� ������

#include "Shoulders.h"

using namespace std;
int main() {
	setlocale(0, "ru");
	Stationary iris;  //������ ������� ������ Stationary
	iris.get_selfnumber(); //����� ����������� �����
	iris.change_number("875123");  //������ ���� ����� �� ������
	iris.call("875123");  //������ ������ ����
	iris.call("861233");  //������, �� ��� �� ��������
	iris.negconnect(); //���������� ������
	iris.call("534123");  //�� ����� ���������
	Mobile nokia;  //������ ������� ������ Mobile
	nokia.get_oper(); //����� ������ ���������. ��� ���. ����������
	nokia.get_selfnumber(); //����� ����������� �����
	nokia.change_oper("������"); //������ ���������
	nokia.get_selfnumber(); //�������, ��� ��������� �����
	nokia.show_contacts();  //���������� ��������
	nokia.add_contact("˸��"); //�������� �������� ������������ �������
	nokia.add_contact("����"); // ��������� �������
	nokia.add_contact("������"); // ��������� �������
	nokia.del_contact("�"); //������� �������
	nokia.show_contacts();  //���������� ��������
	cout << nokia.calculate("8*9") << "\n"; //������� ���������
	Smart apple;  //������ ������� ������ Smart
	apple.get_photo(); //������������� ����������
	apple.photo("�����"); //������ ����
	apple.photo("�����"); //������ ����
	apple.photo("�����"); //������ ����
	apple.del_photo("�����2"); //������� ��������� ������
	apple.get_photo(); //������������� ����������
}