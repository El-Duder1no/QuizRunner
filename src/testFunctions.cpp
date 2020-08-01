#include "testFunctions.h"

bool CheckPath(std::ifstream& questions)
{
    if (!questions) {
        return false;
    }
    return true;
}

bool CheckPath(std::fstream& questions)
{
    if (!questions) {
        return false;
    }
    return true;
}

void parseRes(
        std::ifstream& results,
        std::vector<Results>& userResult) // no questions ok?
{
    resultsParse(results, userResult);
}

void parseTest(std::fstream& questions, std::vector<Questions>& QuestionForTest)
{
    questions.seekg(std::ios_base::beg);
    while (!questions.eof()) {
        std::string type;
        getline(questions, type, '\n');
        if (!(type == "")) {
            ParseTest(questions, QuestionForTest, type);
        }
    }
}

bool parseQuestions(
        std::ifstream& questions, std::vector<Questions>& QuestionsBank)
{
    questions.seekg(std::ios_base::beg);
    while (!questions.eof()) {
        std::string type;
        getline(questions, type, '\n');
        switch (atoi(type.c_str())) {
        case 1: {
            if (!ParseFirstQuestions(questions, QuestionsBank)) {
                return false;
            }
            break;
        }
        case 2: {
            if (!ParseSecondQuestions(questions, QuestionsBank)) {
                return false;
            }
            break;
        }
        case 3: {
            if (!ParseThirdQuestions(questions, QuestionsBank)) {
                return false;
            }
            break;
        }
        }
    }
    return true;
}
