#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

#include "parseString.h"

using namespace std;

#define CAEZAR_SHIFT 3

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
        return true;
    } else {
        return false;
    }
}

// ����� ����
void registrationMenu()
{
    cout << "�������� ����� ����:" << endl;
    cout << "1 - ���� � ������� ������" << endl;
    cout << "2 - �����������" << endl;
    cout << "ESC - �����" << endl;
    cout << ">> ";
}

struct Account
{
	string username;
	string password;
	int accountType;
};

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
		// ����
        case '1': {
            cout << "�� ������ ���� � ������" << endl;
            // ������� �����
            registrationState = false;
            break;
        }
		// �����������
        case '2': {
			string username, password;
            bool temp = registration(username, password);
            if (temp == false) {
                system("CLS");
                cout << "������ ������������ ������" << endl;
                system("PAUSE");
                registrationMenu();
                break;
            } else {
                cout << "����������� ������ �������" << endl;
                currentUser = username;
				
				wstring accountPath = L"D:\\code\\TRPO\\QuizRunner\\res\\Accounts.txt";
				ofstream file; 
				file.open(accountPath, ios_base::app);

				if (!file.is_open())
					cerr << endl << "���� �� ������!" << endl;

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
