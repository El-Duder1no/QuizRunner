#include "FirstType.h"
#include <fstream>
#include <string>
#include <vector>
void FirstType(std::ifstream& questions, std::vector<Questions>& text)
{
    Questions BUF;
    std::string n, temp, TrueAnswer, FalseAnswers;
    getline(questions, temp, '\n');
    BUF.question = temp;

    getline(questions, temp, '\n');
    std::vector<std::string> words;
    parseString(temp, ", ", words);
    for (int i = 0; i < 4; ++i) {
        n = words[i].substr(0, 1);
        if (n == "1") {
            if (i != 3) {
                swap(words[3], words[i]);
            }
            words[3] = words[3].substr(2);
            TrueAnswer = words[3];
        }
    }

    words[0] = words[0].substr(2);
    words[1] = words[1].substr(2);
    words[2] = words[2].substr(2);
    FalseAnswers = words[0] + " " + words[1] + " " + words[2];
    BUF.type = "1";
    BUF.answers.push_back(FalseAnswers);
    BUF.RightAnswers.push_back(TrueAnswer);
    text.push_back(BUF);
}
