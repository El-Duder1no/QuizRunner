#include "userMenu.h"

void UserMenu()
{
    std::cout << "  Select menu item:" << std::endl;
    std::cout << "  1 - View past results" << std::endl;
    std::cout << "  2 - Start test" << std::endl;
    std::cout << "  3 - Log out" << std::endl;
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

    bool userMenuState = true;
    char chooseKey;
    /*if (!CheckPath(results, UsersResults)) {
        std::cout << "  File open error";
        return false;
    }*/

    while (userMenuState) {
        UserMenu();
        std::cin >> chooseKey;
        switch (chooseKey) {
            //CheckResult(user, UsersResults, CurrentUserResults);
        case '1': {
            cls();
            UsersResults.clear();
            parseRes(results, UsersResults);
            if (!CheckResult(user, UsersResults, CurrentUserResults)) {
                printResults(user);
            } else {
                printResults(CurrentUserResults);
            }
            cls();
            break;
        }
        case '2': {
            testPass(testPath, questionsPath, ResultsPath, user);

            cls();
            break;
        }
        case '3': {
            userMenuState = false;
            cls();
            break;
        }
        default: {
            std::cout << "  Input Error" << std::endl;
            myPause();
            cls();
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

void printResults(currentUser& user)
{
    char chooseKey;
    bool check = true;
    while (check) {
        std::cout << "  User results: " << user.username
                  << "\n  Points |  Time\n";
        std::cout << " - "
                  << "\t |  "
                  << "-\n";
        std::cout << "\n  1.Return to menu\n"
                  << "  >> ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            cls();
            check = false;
            break;
        }
        default: {
            std::cout << "  Input Error" << std::endl;
            myPause();
            cls();
            break;
        }
        }
    }
    return;
}

void printResults(std::vector<Results>& CurrentUserResults)
{
    char chooseKey;
    bool check = true;
    int i = 0;
    while (check) {
        std::cout << "  User results: " << CurrentUserResults[i].username
                  << "\n  Points |  Time\n";
        int CurrentUserSize = CurrentUserResults.size();
        for (; i < CurrentUserSize; ++i) {
            std::cout << "  " << CurrentUserResults[i].point << "\t |  "
                      << CurrentUserResults[i].time << "\n";
        }
        std::cout << "\n  1.Return to menu\n"
                  << "  >> ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            cls();
            check = false;
            break;
        }
        default: {
            std::cout << "  Input Error" << std::endl;
            myPause();
            cls();
            i = 0;
            break;
        }
        }
    }
    return;
}
