#ifndef SEARCH_H
#define SEARCH_H

#include "accountStruct.h"
#include <string>
#include <vector>

int BinSearch(std::vector<Account>& a, int* ind, std::string key);

#endif
