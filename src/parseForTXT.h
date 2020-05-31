#ifndef PARSE_FOR_TXT
#define PARSE_FOR_TXT
#define RIGHT_ANSWER 3
#define ANSWERS_SIZE 4
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Questions.h"
#include "parseString.h"

void ParseFirstQuestions(std::ifstream& questions, std::vector<Questions>& text);
void SecondType(std::ifstream &questions, std::vector<Questions>& text);
void ThirdType(std::ifstream &questions, std::vector<Questions>& text);
#endif
