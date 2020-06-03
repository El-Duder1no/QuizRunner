#include "Questions.h"
#include "adminMenu.h"
#include "binSearch.h"
#include "currentUserStruct.h"
#include "parseString.h"
#include "resultStruct.h"
#include "screenFunctions.h"
#include "selectSort.h"
#include "signInOut.h"
#include "userMenu.h"

#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

#define ACCOUNTS_PATH "..\\res\\Accounts.txt"
#define TEST_PATH "..\\res\\Test.txt"
#define QUESTIONS_PATH "..\\res\\Questions.txt"
#define NOT_IN_TEST_PATH "..\\res\\NotInTheTest.txt"
#define RESULTS_PATH "..\\res\\Results.txt"

int main()
{
    setlocale(LC_ALL, "RUS");

    ifstream inputText;
    vector<Questions> QuestionsBank;

	string accpath = "D:\\code\\TRPO\\QuizRunner\\res\\Accounts.txt";
	string testpath = "D:\\code\\TRPO\\QuizRunner\\res\\Test.txt";
	string quepath = "D:\\code\\TRPO\\QuizRunner\\res\\Questions.txt";
	string notquepath = "D:\\code\\TRPO\\QuizRunner\\res\\NotInTheTest.txt";
	string respath = "D:\\code\\TRPO\\QuizRunner\\res\\Results.txt";


    currentUser currUser;

    signInOut(accpath, currUser);

    if (!Administrator(quepath, testpath, notquepath)) {
        cout << "Fail\n";
    }
    if (!User(respath, currUser)) {
        cout << "Fail\n";
    }

    PAUSE();
    return 0;
}
