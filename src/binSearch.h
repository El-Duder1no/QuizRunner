#ifndef SEARCH_H
#define SEARCH_H

#include "accountStruct.h"
#include "resultStruct.h"
#include <cmath>
#include <string>
#include <vector>

int BinSearch(std::vector<Account>& a, int* ind, std::string key);
#endif
