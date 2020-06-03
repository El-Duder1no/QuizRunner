#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <string>
#include <vector>

struct Questions {
    std::string type;
    std::string question;
    std::vector<std::string> answers;
    std::vector<std::string> RightAnswers;
};
#endif
