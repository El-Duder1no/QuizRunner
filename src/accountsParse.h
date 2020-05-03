#ifndef ACC_PARSE_H
#define ACC_PARSE_H

#include "accountStruct.h"
#include "parseString.h"
#include <fstream>
#include <string>
#include <vector>

void accountsParse(std::vector<Account>& a, std::wstring accountPath);

#endif