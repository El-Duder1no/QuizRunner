#include "userMenu.h"
void UserMenu()
{
    std::cout << "Выберите пункт меню:" << std::endl;
    std::cout << "1 - Просмотр результатов" << std::endl;
    std::cout << "2 - Начать тест" << std::endl;
    std::cout << "ESC - Выход" << std::endl;
    std::cout << ">> ";
}

bool User(const std::string ResultsPath)
{
	std::ifstream inputText(ResultsPath.c_str());
	std::vector<Results> UserResults;
    bool userMenuState = true;
    int chooseKey;
        while (userMenuState) {
            UserMenu();
            switch (chooseKey = _getch()) {
            case '1': {
            	//CheckResult()
                CLS();
                break;
            }
            case '2': {
            	//TestStart
                CLS();
                userMenuState = false;
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
