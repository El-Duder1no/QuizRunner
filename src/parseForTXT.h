#ifndef PARSE_FOR_TXT_H
#define PARSE_FOR_TXT_H

#define RIGHT_ANSWER 3
#define ANSWERS_SIZE 4

//#include "Questions.h"
#include "parseString.h"
#include "structures.h"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

bool ParseFirstQuestions(
        std::ifstream& questions, std::vector<Questions>& text);
bool ParseSecondQuestions(
        std::ifstream& questions, std::vector<Questions>& text);
bool ParseThirdQuestions(
        std::ifstream& questions, std::vector<Questions>& text);
void ParseTest(
        std::fstream& questions,
        std::vector<Questions>& text,
        std::string type);
#endif
