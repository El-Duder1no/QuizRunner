#ifndef userMenu

#define userMenu
#include "accountStruct.h"
#include "currentUserStruct.h"
#include "parseString.h"
#include "resultStruct.h"
#include "screenFunctions.h"
#include "testFunctions.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

bool User(const std::string ResultsPath, currentUser& user);
void UserMenu();
bool CheckResult(currentUser& user, std::vector<Results>& usersResults);
#endif
