#include "Questions.h"
#include "parseForTXT.h"
#include "resultStruct.h"
#include "resultsParse.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#ifdef _WIN32
#define FALSE_QUESTIONS_PATH "..\\res\\test_files\\WrongQuestions.txt"
#define QUESTIONS_PATH "..\\res\\test_files\\Questions.txt"
#define TEST_PATH "..\\res\\test_files\\Test.txt"
#else
#define QUESTIONS_PATH "res/test_files/Questions.txt"
#define TEST_PATH "res/test_files/Test.txt"
#define FALSE_QUESTIONS_PATH "res/test_files/WrongQuestions.txt"
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
    EXPECT_TRUE(ParseFirstQuestions(QuestionsFile, actual));
}

TEST(QuestionsParse, INCORRECT_PARSE)
{
    std::ifstream WrongQuestionsFile(FALSE_QUESTIONS_PATH);
    std::vector<Questions> actual;
    WrongQuestionsFile.seekg(std::ios_base::beg);
    std::string type;

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseSecondQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseSecondQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseSecondQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseThirdQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseThirdQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseThirdQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseFirstQuestions(WrongQuestionsFile, actual));

    getline(WrongQuestionsFile, type, '\n');
    EXPECT_FALSE(ParseFirstQuestions(WrongQuestionsFile, actual));
}

TEST(TestParse, CORRECT_PARSE)
{
    std::vector<Questions> expected;
    Questions buff;
    std::string temp, TrueAnswers, WrongAnswers;
    buff.type = "2";
    buff.question = "Arrange numbers in ascending order:";
    WrongAnswers = "2 4 5 3";
    TrueAnswers = "2 3 4 5";
    buff.answers[0] = WrongAnswers;
    buff.RightAnswers[0] = TrueAnswers;
    expected.push_back(buff);
    std::fstream TestFile(TEST_PATH);
    std::vector<Questions> actual;
    TestFile.seekg(std::ios_base::beg);
    std::string type;
    getline(TestFile, type, '\n');
    ParseTest(TestFile, actual, type);

    buff.type = "1";
    buff.question = "2+2= ?";

    WrongAnswers = "3 5 4 8";
    TrueAnswers = "4";
    buff.answers[1] = WrongAnswers;
    buff.RightAnswers[1] = TrueAnswers;
    expected.push_back(buff);
    getline(TestFile, type, '\n');
    ParseTest(TestFile, actual, type);
    int questionSize = actual.size();
    for (int i = 0; i < questionSize; ++i) {
        ASSERT_STREQ(actual[i].type.c_str(), expected[i].type.c_str());
        ASSERT_STREQ(actual[i].question.c_str(), expected[i].question.c_str());
        ASSERT_STREQ(
                actual[i].answers[i].c_str(), expected[i].answers[i].c_str());
        int questionsSize = actual[i].answers.size();
        for (int j = 0; j < questionsSize; ++j) {
            ASSERT_STREQ(
                    actual[i].answers[j].c_str(),
                    expected[i].answers[j].c_str());
        }
        questionsSize = actual[i].RightAnswers.size();
        for (int j = 0; j < questionsSize; ++j) {
            ASSERT_STREQ(
                    actual[i].RightAnswers[j].c_str(),
                    expected[i].RightAnswers[j].c_str());
        }
    }
}