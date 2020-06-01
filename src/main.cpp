#include "Questions.h"
#include "accountsParse.h"
#include "adminMenu.h"
#include "binSearch.h"
#include "enterAccount.h"
#include "loginCheck.h"
#include "parseString.h"
#include "passCheck.h"
#include "registration.h"
#include "selectSort.h"
#include "screenFunctions.h"

#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#define TEST_PATH "..\\res\\Test.txt"
#define QUESTIONS_PATH "..\\res\\Questions.txt"
#define NOT_IN_TEST_PATH "..\\res\\NotInTheTest.txt"

using namespace std;

// ШАПКИ МЕНЮ
void registrationMenu();

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Account> accounts;

    ifstream inputText;
    vector<Questions> QuestionsBank;

    char chooseKey;
    bool registrationState = true;

    string currentUser = "";

    wstring accountPath = L"..\\res\\Accounts.txt";

    registrationMenu();
    while (registrationState) {
        switch (chooseKey = _getch()) {
        // ВХОД
        case '1': {
            vector<Account> accounts;
            accountsParse(accounts, accountPath);
            int* index = new int[accounts.size()];
            for (int i = 0; i < accounts.size(); i++) {
                index[i] = i;
            }
            SelectSort(accounts, index);

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
            vector<Account> accounts;

            int temp = registration(accounts, username, password, accountPath);
            if (temp == 2) {
                CLS();
                cout << "Введен неправильный логин или пароль" << endl;
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

                ofstream file(accountPath, ios_base::app | ios_base::ate);

                if (!file.is_open())
                    cerr << endl << "Файл не открыт!" << endl;

                for (int i = 0; i < password.size(); i++) {
                    password[i] += 3;
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
    if (!Administrator(QUESTIONS_PATH, TEST_PATH, NOT_IN_TEST_PATH)) {
        cout << " Fail";
    }
    PAUSE();
    return 0;
}

void registrationMenu()
{
    cout << "Выберите пункт меню:" << endl;
    cout << "1 - Вход в учетную запись" << endl;
    cout << "2 - Регистрация" << endl;
    cout << "ESC - выход" << endl;
    cout << ">> ";
}
