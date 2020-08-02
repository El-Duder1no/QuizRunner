#include "testFunctions.h"

bool CheckPath(std::ifstream& questions, std::vector<Questions>& QuestionsBank)
{
    if (!questions) {
        return false;
    } else {
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
}

bool CheckPath(std::fstream& questions, std::vector<Questions>& QuestionForTest)
{
    if (!questions) {
        return false;
    } else {
        questions.seekg(std::ios_base::beg);
        while (!questions.eof()) {
            std::string type;
            getline(questions, type, '\n');
            if (!(type == "")) {
                ParseTest(questions, QuestionForTest, type);
            }
        }
        return true;
    }
}

bool CheckPath(const std::string resultsPath, std::vector<Results>& userResult)
{
    std::ifstream results(resultsPath);

    if (!results.is_open()) {
        return false;
    } 

    results.seekg(std::ios_base::beg);
    while (!results.eof()) {
        resultsParse(resultsPath, userResult);
    }
    return true;

    results.close();
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
