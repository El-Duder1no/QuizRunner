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
#define TEST-PATH "..\\res\\Test.txt"
#define QUESTIONS-PATH "..\\res\\Questions.txt"
#define NOT-IN-TEST-PATH "..\\res\\NotInTheTest.txt"
#define RESULTS-PATH "..\\res\\Results.txt"
#else
#define TEST-PATH "res/Test.txt"
#define QUESTIONS-PATH "res/Questions.txt"
#define NOT-IN-TEST-PATH "res/NotInTheTest.txt"
#define RESULTS-PATH "res/Results.txt"
#endif


bool User(const std::string ResultsPath, currentUser& user);
void UserMenu();
bool CheckResult(
        currentUser& user,
        std::vector<Results>& usersResults,
        std::vector<Results>& CurrentUserResults);
void printResults(std::vector<Results>& CurrentUserResults);
#endif
