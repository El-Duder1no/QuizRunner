#include "userMenu.h"
void UserMenu()
{
    std::cout << "�������� ����� ����:" << std::endl;
    std::cout << "1 - �������� �����������" << std::endl;
    std::cout << "2 - ������ ����" << std::endl;
    std::cout << "ESC - �����" << std::endl;
    std::cout << ">> ";
}

bool User(const std::string ResultsPath, currentUser& user)
{
	std::ifstream results(ResultsPath.c_str());
	std::vector<Results> UsersResults;
    if(!CheckPath(results, UsersResults))
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
            	CLS();
				CheckResult(user, UsersResults);
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
                std::cout << "������ �����" << std::endl;
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
	std::vector<Results> CurrentUser;
	for(int i = 0; i < usersResults.size(); ++i){
		if(usersResults[i].username == user.username){
			CurrentUser.push_back(usersResults[i]);
		}
	}
	std::cout << "���������� ������������: " << user.username
	<< "\n �����" << "\t | \t" << "����� �����������\n";
	for(int i = 0; i < CurrentUser.size(); ++i)
	{
		std::cout<< CurrentUser[i].point << "\t | \t" << CurrentUser[i].time 
		<< "\n";
			}
			PAUSE();
                CLS();
}
