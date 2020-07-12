#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "structures.h"
//#include "Questions.h"
#include "parseForTXT.h"
//#include "resultStruct.h"
#include "resultsParse.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool CheckPath(std::ifstream& questions, std::vector<Questions>& QuestionsBank);
bool CheckPath(
        std::fstream& questions, std::vector<Questions>& QuestionForTest);
bool CheckPath(std::ifstream& results, std::vector<Results>& userResult);
#endif
