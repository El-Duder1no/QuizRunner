#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#include "parseString.h"

using namespace std;

#define CAEZAR_SHIFT 3

struct Account
{
	string username;
	string password;
	int accountType;
};

void SelectSort(vector<Account> &a, int *ind)
{
	for (int i = 0; i < a.size() - 1; i++) {
		int min = i;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[ind[j]].username < a[ind[min]].username) {
				min = i;
			}
		}
		swap(ind[i], ind[min]); 
	}
}

int BinSearch(vector<Account>& a, int* ind, string key) {
	int l = 0, r = a.size() - 1, m;
	while (l < r)
	{
		m = floor((l + r) / 2);
		if (a[ind[m]].username < key)
			l = m + 1;
		else
			r = m;
	}
	if (a[ind[r]].username == key)
		return r;
	else
		return -1;
}

void enterAccount(vector<Account>& a, int &ind)
{
	string username, password;

	system("CLS");
	
	cout << "Введите логин:" << endl << ">>";
	cin >> username;
	cout << "Введите пароль:" << endl << ">>";
	cin >> password;

}

void accountsParse(vector<Account>& a)
{
	wstring accountPath = L"D:\\code\\TRPO\\QuizRunner\\res\\Accounts.txt";
	ifstream file(accountPath);

	while (!file.eof()) {
		string temp;
		Account buff;

		getline(file, temp, '\n');
		vector<string> words;
		parseString(temp, " ", words);

		int type = stoi(words[2]);

		buff.accountType = type;
		buff.username = words[0];
		buff.password = words[1];

		a.push_back(buff);
	}

	file.close();
}

bool isPassCorrect(string password)
{
    if (password.size() < 8 || password.size() > 25)
        return 0;

    char* buff = new char[password.length() + 1];
    strcpy_s(buff, password.length() + 1, password.c_str());

    bool isUpper = false, isDigit = false;
    for (int i = 0; i < password.length() + 1; i++) {
        if (isdigit(buff[i])) {
            isDigit = true;
        }
        if (isalpha(buff[i])) {
            if (isupper(buff[i])) {
                isUpper = true;
            }
        }
    }

    if (isUpper == true && isDigit == true) {
        return true;
    } else {
        return false;
    }
}

bool registration(string& username, string& password)
{
    system("CLS");

    cout << "Длина пароля от 8 до 25 символов." << endl
         << "Пароль должен состоять из букв" << endl
         << "латинского алфавита и должен содержать" << endl
         << "как минимум одну заглавную букву и цифру.\n"
         << endl;

    cout << "Введите логин:" << endl << ">>";
    cin >> username;
    cout << "Введите пароль:" << endl << ">>";
    cin >> password;

    if (isPassCorrect(password) == true) {
        return true;
    } else {
        return false;
    }
}

// ШАПКИ МЕНЮ
void registrationMenu()
{
    cout << "Выберите пункт меню:" << endl;
    cout << "1 - Вход в учетную запись" << endl;
    cout << "2 - Регистрация" << endl;
    cout << "ESC - выход" << endl;
    cout << ">> ";
}

int main()
{
    setlocale(LC_ALL, "RUS");

	vector<Account> accounts;

    char chooseKey;
    bool registrationState = true;
	
    string currentUser;

    registrationMenu();

    while (registrationState) {
        switch (chooseKey = _getch()) {
		// ВХОД
        case '1': {
            cout << "Ты выбрал вход в учетку" << endl;

			accountsParse(accounts);
			int* index = new int[accounts.size()];
			SelectSort(accounts, index);
            // ФУНКЦИЯ ВХОДА
            registrationState = false;

			delete[] index;
            break;
        }
		// РЕГИСТРАЦИЯ
        case '2': {
			string username, password;
            bool temp = registration(username, password);
            if (temp == false) {
                system("CLS");
                cout << "Введен неправильный пароль" << endl;
                system("PAUSE");
                registrationMenu();
                break;
            } else {
                cout << "Регистрация прошла успешно" << endl;
                currentUser = username;
				
				// Переделать по человечески, а не как сейчас
				wstring accountPath = L"D:\\code\\TRPO\\QuizRunner\\res\\Accounts.txt";
				ofstream file; 
				file.open(accountPath, ios_base::app);

				if (!file.is_open())
					cerr << endl << "Файл не открыт!" << endl;

				for (int i = 0; i < password.size(); i++) {
					password[i] += CAEZAR_SHIFT;
				}
				file << username << " " << password << " 0" << endl;
				
				file.close();
				registrationState = false;
                break;
            }
        }
        case 27: {
            cout << "Ты выбрал выйти из программы" << endl;
            registrationState = false;
            break;
        }
        default: {
            cout << "ОШИБКА ВВОДА" << endl;
            break;
        }
        }
    }

    system("PAUSE");
    return 0;
}
