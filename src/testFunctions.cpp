#include "testFunctions.h"

bool CheckPath(std::ifstream& questions, std::vector<Questions>& QuestionsBank, const std::string questionsPath)
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

bool CheckPath(std::fstream& FileTxt, std::vector<Questions>& QuestionForTest)
{
    if (FileTxt) {
        return false;
    } else {
        FileTxt.seekg(std::ios_base::beg);
        while (!FileTxt.eof()) {
            std::string type;
            getline(FileTxt, type, '\n');
            if (!(type == ""))
            std::cout<<" ";
                //PROVERKA(FileTxt, QuestionForTest, type);
        }
        return true;
    }
}

