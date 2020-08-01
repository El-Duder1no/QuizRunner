#ifndef TEST_FUNCTIONS_H
#define TEST_FUNCTIONS_H

#include "parseForTXT.h"
#include "resultsParse.h"
#include "structures.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool CheckPath(std::ifstream& questions);
bool CheckPath(std::fstream& questions);
void parseRes(std::ifstream& results, std::vector<Results>& userResult);
bool parseQuestions(
        std::ifstream& questions, std::vector<Questions>& QuestionsBank);
void parseTest(
        std::fstream& questions, std::vector<Questions>& QuestionForTest);
#endif
