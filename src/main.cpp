#include "FirstType.h"
#include "ThirdType.h"
#include "Questions.h"
#include "parseString.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ifstream inputText;
    vector<Questions> QuestionsBank;
    inputText.open("questions.txt");
    if (!inputText) {
        cout << "File open error." << endl;
        return 0;
    } else {
        inputText.seekg(ios_base::beg);
        while (!inputText.eof()) {
            string type, question;
            getline(inputText, type, '\n');

            if (type == "1") {
                FirstType(inputText, QuestionsBank);
            }

            if (type == "2") {
                //                SecondType(inputText, QuestionsBank);
            }

            if (type == "3") {
                ThirdType(inputText, QuestionsBank);
            }
        }

        system("PAUSE");
        return 0;
    }
}
