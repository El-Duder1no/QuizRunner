#ifndef userMenu

#define userMenu
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include "cls.h"
#include "pause.h"
#include "resultStruct.h"
#include "testFunctions.h"
#include "parseString.h"
#include "selectSort.h"
#include "binSearch.h"
#include "accountStruct.h"
#include "currentUserStruct.h"

bool User(const std::string ResultsPath, currentUser& user);
void UserMenu();
bool CheckResult(currentUser& user, std::vector<Results>& usersResults);
#endif
