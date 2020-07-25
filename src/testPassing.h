#ifndef TEST_PASSING_H
#define TEST_PASSING_H

#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "screenFunctions.h"
#include "structures.h"
#include "testFunctions.h"

void testFilling(
        const std::string testPath,
        const std::string questionsPath,
        std::vector<Questions>& Test);

void printQuestion(const std::vector<Questions> Test, const int index);

double checkAnswers(
        const std::vector<Questions>& Test,
        const std::vector<std::string> answers);

bool writeResults(
        const std::string resultsPath,
        currentUser currUser,
        const double result,
        const double time);

void testPass(
        const std::string testPath,
        const std::string questionsPath,
        const std::string resultsPath,
        currentUser currUser);

#endif