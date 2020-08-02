#include "parseForTXT.h"

bool ParseFirstQuestions(std::ifstream& questions, std::vector<Questions>& text)
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
    if (words.size() != ANSWERS_SIZE) {
        return false;
    }
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
    return true;
}

bool ParseSecondQuestions(
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
    if (words.size() != ANSWERS_SIZE) {
        return false;
    }
    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        word[i] = word[i].substr(2);
    }
    FalseAnswers = word[0] + " " + word[1] + " " + word[2] + " " + word[3];

    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        temp = words[i].substr(0, 1);
        switch (CheckAnswer = atoi(temp.c_str())) {
        case 1: {
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        default: {
            return false;
        }
        }
    }
    sort(words.begin(), words.end());
    for (int i = 0; i < ANSWERS_SIZE; ++i) {
        words[i] = words[i].substr(2);
    }

    TrueAnswers = words[0] + " " + words[1] + " " + words[2] + " " + words[3];
    buff.type = "2";
    buff.answers.push_back(FalseAnswers);
    buff.RightAnswers.push_back(TrueAnswers);
    text.push_back(buff);
    return true;
}

bool ParseThirdQuestions(std::ifstream& questions, std::vector<Questions>& text)
{
    Questions buff;
    std::string temp;
    getline(questions, temp, '\n');
    buff.question = temp;
    std::vector<std::string> words;

    getline(questions, temp, '\n');
    parseString(temp, ", ", words);
    if (words.size() != 2) {
        return false;
    }
    for (int i = 0; i < 2; ++i) {
        words[i] = words[i].substr(2);
        buff.RightAnswers.push_back(words[i]);
        buff.answers.push_back(words[i]);
    }
    buff.type = "3";

    text.push_back(buff);
    return true;
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

    if (type == "3") {
        getline(questions, temp, '\n');
        parseString(temp, " ", words);
            for (int i = 0; i < 2; ++i) {
        words[i] = words[i];
        buff.RightAnswers.push_back(words[i]);
        buff.answers.push_back(words[i]);
    //std::cout<< "\n" << words[i];
	}
        getline(questions, temp, '\n');
    text.push_back(buff);
    
    } else {
        getline(questions, temp, '\n');
        WrongAnswers = temp;
        getline(questions, temp, '\n');
        TrueAnswers = temp;

        buff.answers.push_back(WrongAnswers);
        buff.RightAnswers.push_back(TrueAnswers);
    text.push_back(buff);
    }

}
