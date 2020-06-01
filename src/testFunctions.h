#ifndef TEST_FUNCTIONS
#define TEST_FUNCTIONS
#include "Questions.h"
#include "parseForTXT.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
bool CheckPath(std::ifstream& questions, std::vector<Questions>& QuestionsBank);
bool CheckPath(
        std::fstream& questions, std::vector<Questions>& QuestionForTest);
#endif
