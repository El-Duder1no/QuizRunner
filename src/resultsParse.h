#ifndef RESULT_PARSE_H
#define RESULT_PARSE_H

#include "parseString.h"
#include "resultStruct.h"
#include <fstream>
#include <vector>

void resultsParse(std::ifstream& results, std::vector<Results>& a);

#endif