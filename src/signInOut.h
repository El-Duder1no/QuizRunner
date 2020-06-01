#ifndef SIGN_IN_OUT_H
#define SIGN_IN_OUT_H

#define CAESAR_SHIFT 3

#include "accountStruct.h"
#include "binSearch.h"
#include "parseString.h"
#include "screenFunctions.h"
#include "selectSort.h"

#include <conio.h>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void registrationMenu();

bool isLoginCorrect(std::string username);
bool isPassCorrect(std::string password);

void accountsParse(std::vector<Account>& a, const std::string accountPath);
bool enterAccount(std::vector<Account>& a, int* ind, std::string& User);

int registration(
        std::vector<Account>& a,
        std::string& username,
        std::string& password,
        const std::string accountPath);

void signInOut(const std::string accountPath, std::string& User);

#endif