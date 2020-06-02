#include "parseForTXT.h"

void ParseFirstQuestions(std::ifstream& questions, std::vector<Questions>& text)
{
    Questions buff;
    std::string CheckAnswer, temp, TrueAnswer, FalseAnswers;
    std::getline(questions, temp, '\n');
    buff.question = temp;

    getline(questions, temp, '\n');
    std::vector<std::string> words;
    std::vector<std::string> word;
    parseString(temp, ", ", words);
    parseString(temp, ", ", word);
    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        words[i] = words[i].substr(2);
    }
    FalseAnswers = words[0] + " " + words[1] + " " + words[2] + " " + words[3];

    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        CheckAnswer = word[i].substr(0, 1);
        if (CheckAnswer == "1") {
            if (i != RIGHT_ANSWER) {
                swap(word[RIGHT_ANSWER], word[i]);
            }
        }
    }
    word[RIGHT_ANSWER] = word[RIGHT_ANSWER].substr(2);
    TrueAnswer = word[RIGHT_ANSWER];
    buff.type = "1";
    buff.answers.push_back(FalseAnswers);
    buff.RightAnswers.push_back(TrueAnswer);
    text.push_back(buff);
}

void ParseSecondQuestions(
        std::ifstream& questions, std::vector<Questions>& text)
{
    Questions buff;
    std::string temp, TrueAnswers, FalseAnswers;
    int CheckAnswer;
    getline(questions, temp, '\n');
    buff.question = temp;

    getline(questions, temp, '\n');
    std::vector<std::string> words;
    std::vector<std::string> word;
    parseString(temp, ", ", words);
    parseString(temp, ", ", word);
    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        word[i] = word[i].substr(2);
    }
    FalseAnswers = word[0] + " " + word[1] + " " + word[2] + " " + word[3];

    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        temp = words[i].substr(0, 1);
        switch (CheckAnswer = atoi(temp.c_str())) {
        case 1:
            if (i != 0) {
                swap(words[0], words[i]);
            }
            break;
        case 2:
            if (i != 1) {
                swap(words[1], words[i]);
            }
            break;
        case 3:
            if (i != 2) {
                swap(words[2], words[i]);
            }
            break;
        case 4:
            if (i != 3) {
                swap(words[3], words[i]);
            }
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        words[i] = words[i].substr(2);
    }

    TrueAnswers = words[0] + " " + words[1] + " " + words[2] + " " + words[3];
    buff.type = "2";
    buff.answers.push_back(FalseAnswers);
    buff.RightAnswers.push_back(TrueAnswers);
    text.push_back(buff);
}

void ParseThirdQuestions(std::ifstream& questions, std::vector<Questions>& text)
{
    Questions buff;
    std::string temp, TrueAnswers;
    getline(questions, temp, '\n');
    buff.question = temp;
    std::vector<std::string> words;

    getline(questions, temp, '\n');
    parseString(temp, ", ", words);
    for (int i = 0; i < 2; ++i) {
        words[i] = words[i].substr(2);
    }
    TrueAnswers = words[0] + " " + words[1];
    buff.type = "3";
    buff.answers.push_back(TrueAnswers);
    buff.RightAnswers.push_back(TrueAnswers);
    text.push_back(buff);
}

void ParseTest(
        std::fstream& questions, std::vector<Questions>& text, std::string type)
{
    Questions buff;
    std::string temp, TrueAnswers, WrongAnswers;
    buff.type = type;
    std::getline(questions, temp, '\n');
    buff.question = temp;
    std::vector<std::string> words;

    getline(questions, temp, '\n');
    WrongAnswers = temp;
    getline(questions, temp, '\n');
    TrueAnswers = temp;
    buff.answers.push_back(WrongAnswers);
    buff.RightAnswers.push_back(TrueAnswers);
    text.push_back(buff);
}
