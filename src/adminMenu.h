#ifndef adminMenu
#define adminMenu

#include "screenFunctions.h"
#include "testFunctions.h"
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Questions.h"

bool Administrator(
        const std::string questionsPath,
        const std::string TestPath,
        const std::string NotInTestPath);
void AdminMenu();
void CreateTest(
        std::vector<Questions>& text,
        std::vector<Questions>& textBuf,
        std::vector<Questions>& textOut);
void EditingTest(
        std::vector<Questions>& textBuf, std::vector<Questions>& textOut);
void AddQuestions(
        std::vector<Questions>& text,
        std::vector<Questions>& textBuf,
        std::vector<Questions>& textOut);
void AddQuestions(
        std::vector<Questions>& textBuf, std::vector<Questions>& textOut);
void PrintQuestions(std::vector<Questions>& questions, int i);
bool Filing(
        std::fstream& questions,
        std::vector<Questions>& textBuf,
        const std::string questionsPath);
void RemoveQuestion(
        std::vector<Questions>& textBuf, std::vector<Questions>& textOut);
#endif
