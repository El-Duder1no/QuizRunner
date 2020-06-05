#ifndef userMenu

#define userMenu
#include "accountStruct.h"
#include "currentUserStruct.h"
#include "parseString.h"
#include "resultStruct.h"
#include "screenFunctions.h"
#include "testFunctions.h"
#include "testPassing.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#ifdef _WIN32
#define PATH_TEST "..\\res\\Test.txt"
#define PATH_QUESTIONS "..\\res\\Questions.txt"
#define PATH_NOT_IN_TEST "..\\res\\NotInTheTest.txt"
#define PATH_RESULTS "..\\res\\Results.txt"
#else
#define PATH_TEST "res/Test.txt"
#define PATH_QUESTIONS "res/Questions.txt"
#define PATH_NOT_IN_TEST "res/NotInTheTest.txt"
#define PATH_RESULTS "res/Results.txt"
#endif


bool User(const std::string ResultsPath, currentUser& user);
void UserMenu();
bool CheckResult(
        currentUser& user,
        std::vector<Results>& usersResults,
        std::vector<Results>& CurrentUserResults);
void printResults(std::vector<Results>& CurrentUserResults);
#endif
