#include "adminMenu.h"
#include "currentUserStruct.h"
#include "signInOut.h"
#include "userMenu.h"

#include <iostream>
#include <string>

using namespace std;

// D:/code/TRPO/QuizRunner/
#define ACCOUNTS_PATH "D:/code/TRPO/QuizRunner/res/Accounts.txt"
#define TEST_PATH "D:/code/TRPO/QuizRunner/res/Test.txt"
#define QUESTIONS_PATH "D:/code/TRPO/QuizRunner/res/Questions.txt"
#define NOT_IN_TEST_PATH "D:/code/TRPO/QuizRunner/res/NotInTheTest.txt"
#define RESULTS_PATH "D:/code/TRPO/QuizRunner/res/Results.txt"

int main()
{
    setlocale(LC_ALL, "RUS");

    currentUser currUser;

    while (signInOut(ACCOUNTS_PATH, currUser)) {
        switch (currUser.accountType) {
        case 0: {
            if (!User(RESULTS_PATH, TEST_PATH, QUESTIONS_PATH, currUser)) {
                cout << "Fail\n";
            }
            break;
        }
        case 1: {
            if (!Administrator(QUESTIONS_PATH, TEST_PATH, NOT_IN_TEST_PATH)) {
                cout << "Fail\n";
            }
            break;
        }
        }
    }

    PAUSE();
    return 0;
}
