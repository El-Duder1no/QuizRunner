#include "Questions.h"
#include "parseForTXT.h"
#include "resultStruct.h"
#include "resultsParse.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#ifdef _WIN32
#define QUESTIONS_PATH "..\\res\\test_files\\Questions.txt"
#define TEST_PATH "..\\res\\test_files\\Test.txt"
#else
#define QUESTIONS_PATH "res/test_files/Questions.txt"
#define TEST_PATH "res/test_files/Test.txt"
#endif

TEST(QuestionsParse, CORRECT_PARSE)
{
    std::ifstream QuestionsFile(QUESTIONS_PATH);
    std::vector<Questions> actual;
    QuestionsFile.seekg(std::ios_base::beg);
    std::string type;
    getline(QuestionsFile, type, '\n');
    EXPECT_TRUE(ParseThirdQuestions(QuestionsFile, actual));

    getline(QuestionsFile, type, '\n');
    EXPECT_TRUE(ParseSecondQuestions(QuestionsFile, actual));

    getline(QuestionsFile, type, '\n');
    EXPECT_TRUE(ParseThirdQuestions(QuestionsFile, actual));

    question.clear();
}
