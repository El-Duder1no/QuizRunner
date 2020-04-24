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

    cout << "����� ������ �� 8 �� 25 ��������." << endl
         << "������ ������ �������� �� ����" << endl
         << "���������� �������� � ������ ���������" << endl
         << "��� ������� ���� ��������� ����� � �����.\n"
         << endl;

    cout << "������� �����:" << endl << ">>";
    cin >> username;
    cout << "������� ������:" << endl << ">>";
    cin >> password;

    if (isPassCorrect(password) == true) {
        return username;
    } else {
        return "ERROR";
    }
}

void registrationMenu()
{
    cout << "�������� ����� ����:" << endl;
    cout << "1 - ���� � ������� ������" << endl;
    cout << "2 - �����������" << endl;
    cout << "ESC - �����" << endl;
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
            cout << "�� ������ ���� � ������" << endl;
            // ������� �����
            registrationState = false;
            break;
        }
        case '2': {
            string temp = registration();
            if (temp == "ERROR") {
                system("CLS");
                cout << "������ ������������ ������" << endl;
                system("PAUSE");
                registrationMenu();
                break;
            } else {
                cout << "����������� ������ �������" << endl;
                currentUser = temp;
                registrationState = false;
                break;
            }
        }
        case 27: {
            cout << "�� ������ ����� �� ���������" << endl;
            registrationState = false;
            break;
        }
        default: {
            cout << "������ �����" << endl;
            break;
        }
        }
    }

    system("PAUSE");
    return 0;
}
