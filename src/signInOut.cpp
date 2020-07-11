#include "signInOut.h"

void registrationMenu()
{
    CLS();
    std::cout << "  Select menu item:\n";
    std::cout << "  1 - Sign in\n";
    std::cout << "  2 - Sign up\n";
    std::cout << "  3 - Exit\n";
    std::cout << "  >> ";
}
void registrationInfo()
{
    CLS();

    std::cout << "  The username must be between\n"
              << "  3 and 20 characters long.\n"
              << "  Also, it must consist of \n"
              << "  letters of the Latin alphabet, numbers or characters\n\n";

    std::cout << "  The password must be between 8 and 25 characters long.\n"
              << "  password must consist of the Latin alphabet\n"
              << "  and must contain at least one uppercase letter and "
                 "number.\n\n";
}

bool isLoginCorrect(const std::string username)
{
    if (username.size() < 3 || username.size() > 20) {
        return false;
    }

    int usernameSize = username.length();

    char* buff = new char[usernameSize];
    strcpy(buff, username.c_str());

    for (int i = 0; i < usernameSize; i++) {
        if (isgraph(buff[i]) == false) {
            return false;
        }
    }
    return true;
}
bool isPassCorrect(const std::string password)
{
    if (password.size() < 8 || password.size() > 25) {
        return false;
    }

    int passwordSize = password.length();

    char* buff = new char[passwordSize + 1];
    strcpy(buff, password.c_str());

    bool isUpper = false, isDigit = false;
    for (int i = 0; i < passwordSize + 1; i++) {
        if (isgraph(buff[i])) {
            if (isdigit(buff[i])) {
                isDigit = true;
            }
            if (isalpha(buff[i])) {
                if (isupper(buff[i])) {
                    isUpper = true;
                }
            }
        }
    }

    if (isUpper == true && isDigit == true) {
        return true;
    } else {
        return false;
    }
}

void accountsParse(std::vector<Account>& a, const std::string accountPath)
{
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

bool enterAccount(
        currentUser& User,
        std::string password,
        std::string username,
        const std::string accountPath)
{
    std::vector<Account> accounts;
    accountsParse(accounts, accountPath);

    int passwordSize = password.size();
    for (int i = 0; i < passwordSize; i++) {
        password[i] += CAESAR_SHIFT;
    }

    std::vector<Account>::iterator searchResult;
    searchResult = std::find_if(
            accounts.begin(), accounts.end(), [username](const Account& a) {
                return a.username == username;
            });

    if (searchResult != accounts.end()
        && (*searchResult).password == password) {
        User.username = (*searchResult).username;
        User.accountType = (*searchResult).accountType;
        return true;
    } else {
        return false;
    }
}

int registration(
        const std::string username,
        const std::string password,
        const std::string accountPath)
{
    std::vector<Account> accounts;
    accountsParse(accounts, accountPath);

    std::vector<Account>::iterator searchResult;
    searchResult = std::find_if(
            accounts.begin(), accounts.end(), [username](const Account& a) {
                return a.username == username;
            });

    if (searchResult != accounts.end()) {
        return 0;
    }
    if (isPassCorrect(password) == true && isLoginCorrect(username) == true) {
        return 1;
    } else {
        return 2;
    }
}

bool signInOut(const std::string accountPath, currentUser& User)
{
    char chooseKey;
    bool registrationState = true;

    registrationMenu();
    while (registrationState) {
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            std::string username, password;

            CLS();

            std::cout << "  Enter login:\n  >> ";
            std::cin >> username;
            std::cout << "  Enter password:\n  >> ";
            std::cin >> password;

            bool temp = enterAccount(User, password, username, accountPath);
            if (temp == true) {
                system("CLS");
                registrationState = false;
                break;
            } else {
                system("CLS");
                std::cout << "  Incorrect login or password\n";
                system("PAUSE");
                registrationMenu();
                break;
            }
            break;
        }
        case '2': {
            std::string username, password;

            registrationInfo();

            std::cout << "  Enter login:\n  >> ";
            std::cin >> username;
            std::cout << "  Enter password:\n  >> ";
            std::cin >> password;

            int temp = registration(username, password, accountPath);
            switch (temp) {
            case 0: {
                CLS();
                std::cout << "  This account already exists.\n";
                PAUSE();
                registrationMenu();
                break;
            }
            case 1: {
                CLS();
                std::cout << "  Registration completed successfully.\n";
                User.username = username;
                User.accountType = 0;

                std::ofstream file(
                        accountPath, std::ios_base::app | std::ios_base::ate);

                if (!file.is_open()) {
                    break;
                }

                int passwordSize = password.size();
                for (int i = 0; i < passwordSize; i++) {
                    password[i] += CAESAR_SHIFT;
                }
                file << username << " " << password << " 0\n";

                file.close();
                registrationState = false;
                break;
            }
            case 2: {
                CLS();
                std::cout << "  Incorrect login or password\n";
                PAUSE();
                registrationMenu();
                break;
            }
            }
            break;
        }
        case '3': {
            registrationState = false;
            CLS();
            return false;
        }
        default: {
            std::cout << "  Input Error\n";
            break;
        }
        }
    }
}
