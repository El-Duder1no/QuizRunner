#include "screenFunctions.h"

void cls()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void myPause()
{
    std::cout << "\n  Press any key to continue" << std::endl;
    std::cin.get();
}
