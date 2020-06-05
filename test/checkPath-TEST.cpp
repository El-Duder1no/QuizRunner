#include "Questions.h"
#include "resultStruct.h"
#include "testFunctions.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#ifdef _WIN32
#define RESULTS_PATH "..\\res\\test_files\\Results.txt"
#define QUESTIONS_PATH "..\\res\\test_files\\Questions.txt"
#define NO_FILE_PATH "\\res\\test_files\\"
#else
#define QUESTIONS_PATH "res/test_files/Questions.txt"
#define RESULTS_PATH "res/test_files/Results.txt"
#define NO_FILE_PATH "res/test_files/"
#endif

TEST(CheckPath, InCorrectPATH)
{
    std::vector<Results> userResult;
    std::vector<Questions> question;
    std::ifstream ResultsPath(NO_FILE_PATH);
    EXPECT_FALSE(CheckPath(ResultsPath, userResult));

    std::ifstream QuestionsPath(NO_FILE_PATH);
    EXPECT_FALSE(CheckPath(QuestionsPath, question));
}

TEST(CheckPath, CorrectPATH)
{
    std::vector<Results> userResult;
    std::vector<Questions> question;
    std::ifstream File(RESULTS_PATH);
    EXPECT_TRUE(CheckPath(File, userResult));

    std::ifstream QuestionsFile(QUESTIONS_PATH);
    EXPECT_TRUE(CheckPath(QuestionsFile, question));
}