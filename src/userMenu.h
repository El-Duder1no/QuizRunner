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
#include "parseString.h"
#include "accountStruct.h"
#include "currentUserStruct.h"

bool User(const std::string ResultsPath, currentUser& user);
void UserMenu();
#endif
