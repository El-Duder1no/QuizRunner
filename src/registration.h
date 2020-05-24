#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "CLS.h"
#include "accountStruct.h"
#include "accountsParse.h"
#include "binSearch.h"
#include "loginCheck.h"
#include "passCheck.h"
#include "selectSort.h"
#include <iostream>
#include <string>
#include <vector>

int registration(
        std::vector<Account>& a,
        std::string& username,
        std::string& password,
        std::wstring accountPath);

#endif
