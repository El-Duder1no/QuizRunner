#include "accountsParse.h"

void accountsParse(std::vector<Account>& a, std::wstring accountPath)
{
    std::ifstream file(accountPath);

    if (!file.is_open())
        std::cout << "Oaee ia ioe?uo" << std::endl;

    while (!file.eof()) {
        std::string temp;
        Account buff;

        std::getline(file, temp, '\n');

        if (temp == "") {
            return;
        }

        std::vector<std::string> words;
        parseString(temp, " ", words);

        buff.accountType = stoi(words.at(2));
        buff.username = words.at(0);
        buff.password = words.at(1);

        words.clear();
        a.push_back(buff);
    }

    file.close();
}