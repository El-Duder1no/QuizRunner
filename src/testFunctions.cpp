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

            if (type == "1") {
                FirstType(questions, QuestionsBank);
            }

            if (type == "2") {
                SecondType(questions, QuestionsBank);
            }
            if (type == "3") {
                ThirdType(questions, QuestionsBank);
            }
        }
        return true;
    }
}
