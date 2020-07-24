#include "adminMenu.h"
#include "signInOut.h"
#include "structures.h"
#include "userMenu.h"

#include <iostream>
#include <string>

#include <fstream>

using namespace std;

#define ACCOUNTS_PATH "../res/Accounts.txt"
#define TEST_PATH "../res/Accounts.txt"
#define QUESTIONS_PATH "../res/Accounts.txt"
#define NOT_IN_TEST_PATH "../res/NotInTheTest.txt"
#define RESULTS_PATH "../res/Results.txt"

int main()
{
    setlocale(LC_ALL, "RUS");

    ifstream acc(ACCOUNTS_PATH);
    ifstream test(TEST_PATH);
    ifstream quest(QUESTIONS_PATH);
    ifstream ntest(TEST_PATH);
    ifstream res(RESULTS_PATH);

    if (!acc.is_open())
        cout << "acc jopa!\n";
    if (!test.is_open())
        cout << "test jopa!\n";
    if (!quest.is_open())
        cout << "quest jopa!\n";
    if (!ntest.is_open())
        cout << "ntest jopa!\n";
    if (!res.is_open())
        cout << "res jopa!\n";

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

    myPause();
    return 0;
}
