#include <iostream>
#include <conio.h>
#include <string>

#include "parseString.h"

using namespace std;

string registration()
{
	string username, password;

	system("CLS");

	cout << "����� ������ �� 8 �� 25 ��������" << endl
		 << "������ ������ ���������:" << endl
		 << "��� ������� ���� ��������� ����� � �����" << endl << endl;

	cout << "������� �����:" << endl << ">>";
	cin >> username;
	cout << "������� ������:" << endl << ">>";
	cin >> password;

	return username;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	char chooseKey;
	bool registrationState = true;
	string currentUser;

	cout << "�������� ����� ����:" << endl;
	cout << "1 - ���� � ������� ������" << endl;
	cout << "2 - �����������" << endl;
	cout << "ESC - �����" << endl;
	
	while (registrationState) {
		switch (chooseKey = _getch())
		{
		case '1' : 
			cout << "�� ������ ���� � ������" << endl;
			// ������� �����
			break;
		case '2':
			cout << "�� ������ �����������" << endl;
			currentUser = registration();
			registrationState = false;
			break;
		case 27:
			cout << "�� ������ ����� �� ���������" << endl;
			registrationState = false;
			break;
		default : 
			cout << "������ �����" << endl;
			break;
		}
	}

	system("PAUSE");
	return 0;
}
