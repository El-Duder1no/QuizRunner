#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "parseString.h"

using namespace std;

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

string registration()
{
    string username, password;

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
        return username;
    } else {
        return "ERROR";
    }
}

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

    char chooseKey;
    bool registrationState = true;

    string currentUser;

    registrationMenu();

    while (registrationState) {
        switch (chooseKey = _getch()) {
        case '1': {
            cout << "Ты выбрал вход в учетку" << endl;
            // ФУНКЦИЯ ВХОДА
            registrationState = false;
            break;
        }
        case '2': {
            string temp = registration();
            if (temp == "ERROR") {
                system("CLS");
                cout << "Введен неправильный пароль" << endl;
                system("PAUSE");
                registrationMenu();
                break;
            } else {
                cout << "Регистрация прошла успешно" << endl;
                currentUser = temp;
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
