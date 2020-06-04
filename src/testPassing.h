#ifndef TEST_PASSING_H
#define TEST_PASSING_H

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "Questions.h"
#include "currentUserStruct.h"
#include "screenFunctions.h"
#include "testFunctions.h"

void testFilling(
        const std::string testPath,
        const std::string notInTheTestPath,
        const std::string questionsPath,
        std::vector<Questions>& Test);

void printQuestion(std::vector<Questions>& Test, const int index);

double checkAnswers(
        const std::vector<Questions>& Test,
        const std::vector<std::string> answers);

bool writeResults(
        const std::string resultsPath,
        currentUser currUser,
        const int result,
        const int time);

void testPass(
        const std::string testPath,
        const std::string notInTheTestPath,
        const std::string questionsPath,
        const std::string resultsPath,
        currentUser currUser);

#endif