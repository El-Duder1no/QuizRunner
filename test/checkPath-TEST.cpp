#include "structures.h"
#include "testFunctions.h"

#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#define QUESTIONS_PATH "res/test_files/Questions.txt"
#define RESULTS_PATH "res/test_files/Results.txt"
#define NO_FILE_PATH "res/test_files/noFile.txt"

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