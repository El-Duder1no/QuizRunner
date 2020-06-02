#include "userMenu.h"
void UserMenu()
{
    std::cout << "Выберите пункт меню:" << std::endl;
    std::cout << "1 - Просмотр результатов" << std::endl;
    std::cout << "2 - Начать тест" << std::endl;
    std::cout << "ESC - Выход" << std::endl;
    std::cout << ">> ";
}

bool User(const std::string ResultsPath, currentUser& user)
{
    std::ifstream results(ResultsPath.c_str());
    std::vector<Results> UsersResults;
    if (!CheckPath(results, UsersResults)) {
        std::cout << "File open error";
        return false;
    }
    bool userMenuState = true;
    int chooseKey;
    while (userMenuState) {
        UserMenu();
        switch (chooseKey = _getch()) {
        case '1': {
            CLS();
            if (!CheckResult(user, UsersResults)) {
                std::cout << "Предыдущие результаты не найдены!\n\n";
                PAUSE();
            }
            CLS();
            break;
        }
        case '2': {
            // TestStart
            CLS();
            break;
        }
        case 27: {
            userMenuState = false;
            break;
        }
        default: {
            std::cout << "Ошибка ввода" << std::endl;
            PAUSE();
            CLS();
            break;
        }
        }
    }
    return true;
}

bool CheckResult(currentUser& user, std::vector<Results>& usersResults)
{
    int chooseKey;
    std::vector<Results> CurrentUser;
    for (int i = 0; i < usersResults.size(); ++i) {
        if (usersResults[i].username == user.username) {
            CurrentUser.push_back(usersResults[i]);
        }
    }
    if (CurrentUser.empty()) {
        return false;
    } else {
        bool check = true;
        while (check) {
            std::cout << "Результаты пользователя: " << user.username
                      << "\n Баллы"
                      << "\t | \t"
                      << "Время прохождения\n";
            for (int i = 0; i < CurrentUser.size(); ++i) {
                std::cout << CurrentUser[i].point << "\t | \t"
                          << CurrentUser[i].time << "\n";
            }
            std::cout << "\n\n 1.Вернуться в меню\n"
                      << "<<";
            switch (chooseKey = _getch()) {
            case '1': {
                CLS();
                check = false;
                break;
            }
            default: {
                std::cout << "Ошибка ввода" << std::endl;
                PAUSE();
                CLS();
                break;
            }
            }
        }
        return true;
    }
}
