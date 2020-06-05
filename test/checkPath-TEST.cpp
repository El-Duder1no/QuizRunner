#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "Questions.h"
#include "resultStruct.h"
#include "testFunctions.h"

#ifdef _WIN32
#define RESULTS_PATH "..\\res\\test_files\\Results.txt"
#define QUESTIONS_PATH "..\\res\\test_files\\Questions.txt"
#define NO_FILE_PATH "\\res\\test_files\\"
#else
#define QUESTIONS_PATH "res/test_files/Questions.txt"
#define RESULTS_PATH "res/test_files/Results.txt"
#define NO_FILE_PATH "res/test_files/"
#endif

std::vector<Results> userResult;
std::vector<Questions> question;

TEST(CheckPath, InCorrectPATH)
{
    std::ifstream ResultsPath(NO_FILE_PATH);
    EXPECT_FALSE(CheckPath(ResultsPath, userResult));

    std::ifstream QuestionsPath(NO_FILE_PATH);
    EXPECT_FALSE(CheckPath(QuestionsPath, question));
    question.clear();
    userResult.clear();
}

TEST(CheckPath, CorrectPATH)
{
    std::ifstream File(RESULTS_PATH);
    EXPECT_TRUE(CheckPath(File, userResult));

    std::ifstream QuestionsFile(QUESTIONS_PATH);
    EXPECT_TRUE(CheckPath(QuestionsFile, question));

    question.clear();
    userResult.clear();
}