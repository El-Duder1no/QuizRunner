#include "SecondType.h"
#include <fstream>
#include <string>
#include <vector>
void SecondType(std::ifstream& questions, std::vector<Questions>& text)
{
    Questions BUF;
    std::string n, temp, TrueAnswers, FalseAnswers;
    getline(questions, temp, '\n');
    BUF.question = temp;

    getline(questions, temp, '\n');
    std::vector<std::string> words;
    std::vector<std::string> word;
    parseString(temp, ", ", words);
    parseString(temp, ", ", word);
    word[0] = word[0].substr(2);
    word[1] = word[1].substr(2);
    word[2] = word[2].substr(2);
    word[3] = word[3].substr(2);
    FalseAnswers = word[0] + " " + word[1] + " " + word[2] + " " + word[3];

    for (int i = 0; i < 4; ++i) {
        n = words[i].substr(0, 1);
        if (n == "1") 
		{
            if (i != 0) {
                swap(words[0], words[i]);
            }
        }
        if (n == "2") 
		{
            if (i != 1) {
                swap(words[1], words[i]);
            }
        }
        if (n == "3") 
		{
            if (i != 2) {
                swap(words[2], words[i]);
            }
        }
        if (n == "4")
		{
            if (i != 3) {
                swap(words[3], words[i]);
            }
        }
    }
    words[0] = words[0].substr(2);
    words[1] = words[1].substr(2);
    words[2] = words[2].substr(2);
    words[3] = words[3].substr(2);
    TrueAnswers = words[0] + " " + words[1] + " " + words[2] + " " + words[3];
    BUF.type = "2";
    BUF.answers.push_back(FalseAnswers);
    BUF.RightAnswers.push_back(TrueAnswers);
    text.push_back(BUF);
}
