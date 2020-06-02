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
	std::vector<Results> UserResults;
    if(!CheckPath(results, UserResults))
    {
    	std::cout<<"File open error";
    	return false;
	}
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

bool CheckResult()
{
}

