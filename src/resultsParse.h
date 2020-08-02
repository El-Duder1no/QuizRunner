#ifndef RESULT_PARSE_H
#define RESULT_PARSE_H

#include "parseString.h"
#include "structures.h"

#include <fstream>
#include <vector>

void resultsParse(const std::string resultsPath, std::vector<Results>& a);

#endif
