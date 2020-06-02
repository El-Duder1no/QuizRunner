#ifndef SEARCH_H
#define SEARCH_H

#include "accountStruct.h"
#include "resultStruct.h"
#include <string>
#include <vector>
#include <cmath>

int BinSearch(std::vector<Account>& a, int* ind, std::string key);
int BinSearch(std::vector<Results>& a, int* ind, std::string key);
#endif
