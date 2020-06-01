#include "Questions.h"
#include "adminMenu.h"
#include "binSearch.h"
#include "parseString.h"
#include "screenFunctions.h"
#include "selectSort.h"
#include "signInOut.h"

#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#define ACCOUNTS_PATH "..\\res\\Accounts.txt"
#define TEST_PATH "..\\res\\Test.txt"
#define QUESTIONS_PATH "..\\res\\Questions.txt"
#define NOT_IN_TEST_PATH "..\\res\\NotInTheTest.txt"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ifstream inputText;
    vector<Questions> QuestionsBank;

    string currentUser = "";

    signInOut(ACCOUNTS_PATH, currentUser);

    if (!Administrator(QUESTIONS_PATH, TEST_PATH, NOT_IN_TEST_PATH)) {
        cout << "Fail\n";
    }

    PAUSE();
    return 0;
}
