#include "Questions.h"
#include "adminMenu.h"
#include "binSearch.h"
#include "currentUserStruct.h"
#include "parseString.h"
#include "resultStruct.h"
#include "screenFunctions.h"
#include "selectSort.h"
#include "signInOut.h"
#include "testPassing.h"
#include "userMenu.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#ifdef _WIN32
#define ACCOUNTS_PATH "..\\res\\Accounts.txt"
#define TEST_PATH "..\\res\\Test.txt"
#define QUESTIONS_PATH "..\\res\\Questions.txt"
#define NOT_IN_TEST_PATH "..\\res\\NotInTheTest.txt"
#define RESULTS_PATH "..\\res\\Results.txt"
#else
#define ACCOUNTS_PATH "res/Accounts.txt"
#define TEST_PATH "res/Test.txt"
#define QUESTIONS_PATH "res/Questions.txt"
#define NOT_IN_TEST_PATH "res/NotInTheTest.txt"
#define RESULTS_PATH "res/Results.txt"
#endif

int main()
{
    setlocale(LC_ALL, "RUS");

    ifstream inputText;
    vector<Questions> QuestionsBank;

    currentUser currUser;

    signInOut(ACCOUNTS_PATH, currUser);

    switch (currUser.accountType) {
    case 0: {
        if (!User(RESULTS_PATH, currUser)) {
            cout << "Fail\n";
        }
    }
    case 1: {
        if (!Administrator(QUESTIONS_PATH, TEST_PATH, NOT_IN_TEST_PATH)) {
            cout << "Fail\n";
        }
    }
    }

    PAUSE();
    return 0;
}
