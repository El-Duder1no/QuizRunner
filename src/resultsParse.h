#ifndef RESULT_PARSE_H
#define RESULT_PARSE_H

#include "resultStruct.h"
#include "parseString.h"
#include <vector>
#include <fstream>

void resultsParse(std::vector<Results>& a, std::ifstream& results);

#endif