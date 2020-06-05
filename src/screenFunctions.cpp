#include "screenFunctions.h"

void CLS()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void PAUSE()
{
    std::cout << "\nPress any key to continue" << std::endl;
    std::cin.get();
}
