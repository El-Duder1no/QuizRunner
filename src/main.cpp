#include <algorithm>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "parseString.h"

using namespace std;

#define CAEZAR_SHIFT 3

// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ
void PAUSE();
void CLS();
// ШАПКИ МЕНЮ
void registrationMenu();

struct Account {
    string username;
    string password;
    int accountType;
};

void SelectSort(vector<Account>* a, int* ind)
{
    for (int i = 0; i < a->size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < a->size(); j++) {
            if (a->at(ind[j]).username < a->at(ind[min]).username) {
                min = j;
            }
        }
        swap(ind[i], ind[min]);
    }
}

int BinSearch(vector<Account>& a, int* ind, string key)
{
    int l = 0, r = a.size() - 1, m;
    while (l < r) {
        m = floor((l + r) / 2);
        if (a[ind[m]].username < key)
            l = m + 1;
        else
            r = m;
    }
    if (a[ind[r]].username == key) {
        return r;
    } else {
        return -1;
    }
}

bool enterAccount(vector<Account>& a, int* ind, string &User)
{
    string username, password;

	CLS();

    cout << "Введите логин:" << endl << ">>";
    cin >> username;
    cout << "Введите пароль:" << endl << ">>";
    cin >> password;

    for (int i = 0; i < password.size(); i++) {
        password[i] += CAEZAR_SHIFT;
    }

    int temp = BinSearch(a, ind, username);

    if (temp == -1) {
        return false;
    } else if (a[ind[temp]].password == password) {
		User = username;
        return true;
    }
}

void accountsParse(vector<Account>& a)
{
    wstring accountPath = L"D:\\code\\TRPO\\QuizRunner\\res\\Accounts.txt";
    ifstream file(accountPath);

    while (!file.eof()) {
        string temp;
        Account buff;

        getline(file, temp, '\n');

        if (temp == "") {
            return;
        }

        vector<string> words;
        parseString(temp, " ", words);

        buff.accountType = stoi(words.at(2));
        buff.username = words.at(0);
        buff.password = words.at(1);

        words.clear();
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

int registration(vector<Account>& a, string& username, string& password)
{
	CLS();

    cout << "Длина пароля от 8 до 25 символов." << endl
         << "Пароль должен состоять из букв" << endl
         << "латинского алфавита и должен содержать" << endl
         << "как минимум одну заглавную букву и цифру.\n"
         << endl;

    cout << "Введите логин:" << endl << ">>";
    cin >> username;
    cout << "Введите пароль:" << endl << ">>";
    cin >> password;

	//---------
	accountsParse(a);
	int* ind = new int[a.size()];
	for (int i = 0; i < a.size(); i++) {
		ind[i] = i;
	}
	SelectSort(&a, ind);

	for (int i = 0; i < username.size(); i++) {
		username[i] += CAEZAR_SHIFT;
	}

	int temp = BinSearch(a, ind, username);

	delete[] ind;

	if (temp == -1) {
		return 0;
	}
	//---------

    if (isPassCorrect(password) == true) {
        return 1;
    } else {
        return 2;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    vector<Account> accounts;

    char chooseKey;
    bool registrationState = true;

    string currentUser;

    wstring accountPath = L"\res\Accounts.txt";

    registrationMenu();
    while (registrationState) {
        switch (chooseKey = _getch()) {
        // ВХОД
        case '1': {
            accountsParse(accounts);
            int* index = new int[accounts.size()];
            for (int i = 0; i < accounts.size(); i++) {
                index[i] = i;
            }
            SelectSort(&accounts, index);

            bool temp = enterAccount(accounts, index, currentUser);

            switch (temp) {
            case false: {
                system("CLS");
                cout << "Неправильный логин или пароль" << endl;
                system("PAUSE");
                registrationMenu();
                break;
            }
            case true: {
                system("CLS");
                cout << "Вход в личный кабинет" << endl;
				cout << "currentUser-" << currentUser << endl;
                registrationState = false;
                break;
            }
            }
            delete[] index;
            break;
        }
        // РЕГИСТРАЦИЯ
        case '2': {
            string username, password;
            int temp = registration(accounts, username, password);
            if (temp == 2) {
				CLS();
                cout << "Введен неправильный пароль" << endl;
				PAUSE();
                registrationMenu();
                break;
            } 
			if (temp == 0) {
				CLS();
				cout << "Такой аккаунт уже существует" << endl;
				PAUSE();
				registrationMenu();
				break;
			}
			if (temp == 1) {
				cout << "Регистрация прошла успешно" << endl;
				currentUser = username;

				ofstream file(accountPath, ios_base::app);

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
        // ВЫХОД ИЗ ПРОГРАММЫ
        case 27: {
            registrationState = false;
            break;
        }
        default: {
            cout << "ОШИБКА ВВОДА" << endl;
            break;
        }
        }
    }

	PAUSE();
    return 0;
}

void PAUSE()
{
	cout << "Нажмите любую клавишу чтобы продолжить" << endl;
	cin.ignore();
	cin.get();
}

void CLS()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void registrationMenu()
{
	cout << "Выберите пункт меню:" << endl;
	cout << "1 - Вход в учетную запись" << endl;
	cout << "2 - Регистрация" << endl;
	cout << "ESC - выход" << endl;
	cout << ">> ";
}