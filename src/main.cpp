#include "parseString.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include "Questions.h"
#include <vector>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ifstream inputText;
    inputText.open("questions.txt");
    if (!inputText)
    {
        cout << "File open error." << endl;
        return 0;
    }
    system("PAUSE");
    return 0;
}
