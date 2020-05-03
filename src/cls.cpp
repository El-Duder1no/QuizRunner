#include "cls.h"

void CLS()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}