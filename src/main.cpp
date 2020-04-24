#include <iostream>
#include <conio.h>
#include <string>

#include "parseString.h"

using namespace std;

string registration()
{
	string username, password;

	system("CLS");

	cout << "Длина пароля от 8 до 25 символов" << endl
		 << "Пароль должен содержать:" << endl
		 << "Как минимум одну заглавную букву и цифру" << endl << endl;

	cout << "Введите логин:" << endl << ">>";
	cin >> username;
	cout << "Введите пароль:" << endl << ">>";
	cin >> password;

	return username;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	char chooseKey;
	bool registrationState = true;
	string currentUser;

	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Вход в учетную запись" << endl;
	cout << "2 - Регистрация" << endl;
	cout << "ESC - выход" << endl;
	
	while (registrationState) {
		switch (chooseKey = _getch())
		{
		case '1' : 
			cout << "Ты выбрал вход в учетку" << endl;
			// ФУНКЦИЯ ВХОДА
			break;
		case '2':
			cout << "Ты выбрал регистрацию" << endl;
			currentUser = registration();
			registrationState = false;
			break;
		case 27:
			cout << "Ты выбрал выйти из программы" << endl;
			registrationState = false;
			break;
		default : 
			cout << "ОШИБКА ВВОДА" << endl;
			break;
		}
	}

	system("PAUSE");
	return 0;
}
