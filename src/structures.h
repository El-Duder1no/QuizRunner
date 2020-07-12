#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <vector>

struct Account {
    std::string username;
    std::string password;
    int accountType;
};

struct currentUser {
    std::string username;
    int accountType;
};

struct Results {
    std::string username;
    std::string point;
    std::string time;
};

struct Questions {
    std::string type;
    std::string question;
    std::vector<std::string> answers;
    std::vector<std::string> RightAnswers;
};

#endif