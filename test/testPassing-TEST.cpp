#include <fstream>
#include <gtest/gtest.h>
#include <vector>

#include "screenFunctions.h"
#include "structures.h"
#include "testFunctions.h"
#include "testPassing.h"

#define RESULTS_PATH "res/test_files/ResultsWrite.txt"
#define WRONG_RESULTS_PATH "res/test_files"
#define QUIZ_PATH "res/test_files/Questions.txt"

TEST(checkAnswerTest, allOptions)
{
    std::vector<Questions> test;
    std::vector<std::string> answers;

    testFilling("", QUIZ_PATH, test);

    answers.push_back("0.5");
    answers.push_back("2 3 4 5");
    answers.push_back("10");
    EXPECT_FLOAT_EQ(checkAnswers(test, answers), 100);

    answers.clear();
    answers.push_back("0");
    answers.push_back("0");
    answers.push_back("0");
    EXPECT_FLOAT_EQ(checkAnswers(test, answers), 0);

    answers.clear();
    answers.push_back("0.5");
    answers.push_back("0");
    answers.push_back("0");
    EXPECT_FLOAT_EQ(checkAnswers(test, answers), 33);

    answers.clear();
    answers.push_back("0.5");
    answers.push_back("2 3 4 5");
    answers.push_back("0");
    EXPECT_FLOAT_EQ(checkAnswers(test, answers), 66);
}

TEST(writeResultsTest, correct)
{
    double result = "100", time = "67";
    currentUser currUser;
    currUser.username = "Oleg";
    currUser.accountType = 0;

    EXPECT_TRUE(writeResults(RESULTS_PATH, currUser, result, time));

    std::ofstream file(RESULTS_PATH, std::ios_base::trunc);
}

TEST(writeResultsTest, incorrect)
{
    double result = "100", time = "67";
    currentUser currUser;
    currUser.username = "OlegPetrovich";
    currUser.accountType = 0;

    EXPECT_FALSE(writeResults(WRONG_RESULTS_PATH, currUser, result, time));

    std::ofstream file(RESULTS_PATH, std::ios_base::trunc);
}