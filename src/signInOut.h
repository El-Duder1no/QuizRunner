#ifndef SIGN_IN_OUT_H
#define SIGN_IN_OUT_H

#define CAESAR_SHIFT 3
#define _CRT_SECURE_NO_WARNINGS

#include "accountStruct.h"
#include "currentUserStruct.h"
#include "parseString.h"
#include "screenFunctions.h"

#include <algorithm>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void registrationMenu();

bool isLoginCorrect(std::string username);
bool isPassCorrect(std::string password);

void accountsParse(std::vector<Account>& a, const std::string accountPath);
bool enterAccount(
        currentUser& User,
        std::string password,
        std::string username,
        const std::string accountPath);

int registration(
        const std::string username,
        const std::string password,
        const std::string accountPath);

void signInOut(const std::string accountPath, currentUser& User);

#endif
