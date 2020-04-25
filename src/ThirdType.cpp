#include "ThirdType.h"
#include <fstream>
#include <string>
#include <vector>
void ThirdType(std::ifstream& questions, std::vector<Questions>& text)
{
    Questions BUF;
    std::string temp, TrueAnswers;
    getline(questions, temp, '\n');
    BUF.question = temp;
    std::vector<std::string> words;

    getline(questions, temp, '\n');
    parseString(temp, ", ", words);
    words[0] = words[0].substr(2);
    words[1] = words[1].substr(2);
    TrueAnswers = words[0] + " " + words[1];
    BUF.type = "3";
    BUF.answers.push_back(TrueAnswers);
    BUF.RightAnswers.push_back(TrueAnswers);
    text.push_back(BUF);
}
