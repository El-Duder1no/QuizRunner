#include "accountsParse.h"

void accountsParse(std::vector<Account>& a)
{
    std::wstring accountPath = L"\\res\\Accounts.txt";
    std::ifstream file(accountPath);

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