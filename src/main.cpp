#include <iostream>
#include <conio.h>
#include <string>

#include "parseString.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	char chooseKey;
	bool registrationState = true;

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
			// ������� �����������
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
