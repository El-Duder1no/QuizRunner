#include "userMenu.h"
void UserMenu()
{
    std::cout << "�������� ����� ����:" << std::endl;
    std::cout << "1 - �������� �����������" << std::endl;
    std::cout << "2 - ������ ����" << std::endl;
    std::cout << "ESC - �����" << std::endl;
    std::cout << ">> ";
}

bool User()
{
    bool userMenuState = true;
    int chooseKey;
        while (userMenuState) {
            UserMenu();
            switch (chooseKey = _getch()) {
            case '1': {
                CLS();
                break;
            }
            case '2': {
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
