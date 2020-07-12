#ifndef USER_MENU_H
#define USER_MENU_H

#include "structures.h"
//#include "accountStruct.h"
//#include "currentUserStruct.h"
#include "parseString.h"
//#include "resultStruct.h"
#include "screenFunctions.h"
#include "testFunctions.h"
#include "testPassing.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

bool User(
        const std::string ResultsPath,
        const std::string testPath,
        const std::string questionsPath,
        currentUser& user);
void UserMenu();
bool CheckResult(
        currentUser& user,
        std::vector<Results>& usersResults,
        std::vector<Results>& CurrentUserResults);
void printResults(std::vector<Results>& CurrentUserResults);

#endif
