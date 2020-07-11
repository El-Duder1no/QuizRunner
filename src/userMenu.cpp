#include "userMenu.h"
void UserMenu()
{
    std::cout << "  Select menu item:" << std::endl;
    std::cout << "  1 - View past results" << std::endl;
    std::cout << "  2 - Start test" << std::endl;
    std::cout << "  3 - Exit" << std::endl;
    std::cout << "  >> ";
}

bool User(
        const std::string ResultsPath,
        const std::string testPath,
        const std::string questionsPath,
        currentUser& user)
{
    std::ifstream results(ResultsPath.c_str());
    std::vector<Results> UsersResults;
    std::vector<Results> CurrentUserResults;
    if (!CheckPath(results, UsersResults)) {
        std::cout << "  File open error";
        return false;
    }
    bool userMenuState = true;
    char chooseKey;
    while (userMenuState) {
        UserMenu();
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            CLS();
            if (!CheckResult(user, UsersResults, CurrentUserResults)) {
                std::cout << "  No previous results found!\n\n";
            } else {
                printResults(CurrentUserResults);
            }
            PAUSE();
            CLS();
            break;
        }
        case '2': {
            testPass(testPath, questionsPath, ResultsPath, user);
            CLS();
            break;
        }
        case '3': {
            userMenuState = false;
            CLS();
            break;
        }
        default: {
            std::cout << "  Input Error" << std::endl;
            PAUSE();
            CLS();
            break;
        }
        }
    }
    return true;
}

bool CheckResult(
        currentUser& user,
        std::vector<Results>& usersResults,
        std::vector<Results>& CurrentUserResults)
{
    CurrentUserResults.clear();
    int ResultSize = usersResults.size();
    for (int i = 0; i < ResultSize; ++i) {
        if (usersResults[i].username == user.username) {
            CurrentUserResults.push_back(usersResults[i]);
        }
    }
    if (CurrentUserResults.empty()) {
        return false;
    } else {
        return true;
    }
}

void printResults(std::vector<Results>& CurrentUserResults)
{
    char chooseKey;
    bool check = true;
    int i = 0;
    while (check) {
        std::cout << "  User results: " << CurrentUserResults[i].username
                  << "\n  Points"
                  << "\t | \t"
                  << "Time\n";
        int CurrentUserSize = CurrentUserResults.size();
        for (; i < CurrentUserSize; ++i) {
            std::cout << CurrentUserResults[i].point << "\t | \t"
                      << CurrentUserResults[i].time << "\n";
        }
        std::cout << "\n\n  1.Return to menu\n"
                  << "  >> ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            CLS();
            check = false;
            break;
        }
        default: {
            std::cout << "  Input Error" << std::endl;
            PAUSE();
            CLS();
            i = 0;
            break;
        }
        }
    }
    return;
}
