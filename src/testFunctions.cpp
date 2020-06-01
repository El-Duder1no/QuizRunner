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
			switch(atoi(type.c_str())){
            case 1:
                ParseFirstQuestions(questions, QuestionsBank);
                break;
            case 2:
                ParseSecondQuestions(questions, QuestionsBank);
            break;
            case 3:
                ParseThirdQuestions(questions, QuestionsBank);
                break;
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
            if (!(type == ""))
            {
            ParseTest(questions, QuestionForTest, type);
    }
		}
        return true;
    }
}

