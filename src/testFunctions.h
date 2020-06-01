#ifndef TEST_FUNCTIONS
#define TEST_FUNCTIONS
#include "Questions.h"
#include "parseForTXT.h"
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
bool CheckPath(std::ifstream& questions, std::vector<Questions>& QuestionsBank);
bool CheckPath(std::fstream& questions, std::vector<Questions>& QuestionForTest);
#endif
