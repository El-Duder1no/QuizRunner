#include "signInOut.h"

void registrationMenu()
{
    std::cout << "Выберите пункт меню:\n";
    std::cout << "1 - Вход в учетную запись\n";
    std::cout << "2 - Регистраци¤\n";
    std::cout << "ESC - выход\n";
    std::cout << ">> ";
}

bool isLoginCorrect(std::string username)
{
    if (username.size() < 3 || username.size() > 20) {
        return false;
    }

    int loginSize = username.length();
    char* buff = new char[loginSize];
    strcpy_s(buff, loginSize + 1, username.c_str());

    for (int i = 0; i < loginSize; i++) {
        if (isgraph(buff[i]) == false) {
            return false;
        }
    }
    return true;
}
bool isPassCorrect(std::string password)
{
    if (password.size() < 8 || password.size() > 25) {
        return false;
    }

    char* buff = new char[password.length() + 1];
    strcpy_s(buff, password.length() + 1, password.c_str());

    bool isUpper = false, isDigit = false;
    for (int i = 0; i < password.length() + 1; i++) {
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

bool enterAccount(std::vector<Account>& a, int* ind, std::string& User)
{
    std::string username, password;

    CLS();

    std::cout << "Введите логин:" << std::endl << ">>";
    std::getline(std::cin, username);
    std::cout << "Введите пароль:" << std::endl << ">>";
    std::getline(std::cin, password);

    for (int i = 0; i < password.size(); i++) {
        password[i] += CAESAR_SHIFT;
    }

    int temp = BinSearch(a, ind, username);

    if (temp != -1 && a[ind[temp]].password == password) {
        User = username;
        return true;
    } else {
        return false;
    }
}

int registration(
        std::vector<Account>& a,
        std::string& username,
        std::string& password,
        const std::string accountPath)
{
    CLS();

    std::cout << "Длина имени пользовател¤ должна\n"
              << "составлять от 3 до 20 символов.\n"
              << "Также, оно может состоять \n"
              << "из букв латинского алфавита, цифр или знаков\n\n";

    std::cout << "Длина пароля от 8 до 25 символов.\n"
              << "Пароль должен состоять из букв\n"
              << "латинского алфавита и должен содержать\n"
              << "как минимум одну заглавную букву и цифру.\n\n";

    std::cout << "Введите логин:\n>>";
    std::getline(std::cin, username);
    std::cout << "Введите пароль:\n>>";
    std::getline(std::cin, password);

    //---------
    accountsParse(a, accountPath);
    int* ind = new int[a.size()];
    for (int i = 0; i < a.size(); i++) {
        ind[i] = i;
    }
    SelectSort(a, ind);

    int temp = BinSearch(a, ind, username);

    delete[] ind;

    if (temp != -1) {
        return 0;
    }
    if (isPassCorrect(password) == true && isLoginCorrect(username) == true) {
        return 1;
    } else {
        return 2;
    }
}

void signInOut(const std::string accountPath, std::string& User)
{
    char chooseKey;
    bool registrationState = true;

    registrationMenu();
    while (registrationState) {
        switch (chooseKey = _getch()) {
        // ВХОД
        case '1': {
            std::vector<Account> accounts;
            accountsParse(accounts, accountPath);

            int* index = new int[accounts.size()];
            for (int i = 0; i < accounts.size(); i++) {
                index[i] = i;
            }
            SelectSort(accounts, index);

            bool temp = enterAccount(accounts, index, User);

            switch (temp) {
            case false: {
                system("CLS");
                std::cout << "Неправильный логин или пароль\n";
                system("PAUSE");
                registrationMenu();
                break;
            }
            case true: {
                system("CLS");
                std::cout << "Вход в личный кабинет\n";
                registrationState = false;
                break;
            }
            }
            delete[] index;
            break;
        }
        // РЕГИСТРАЦИЯ
        case '2': {
            std::string username, password;
            std::vector<Account> accounts;

            int temp = registration(accounts, username, password, accountPath);
            switch (temp) {
            case 0: {
                CLS();
                std::cout << "Такой аккаунт уже существует\n";
                PAUSE();
                registrationMenu();
                break;
            }
            case 1: {
                std::cout << "Регистраци¤ прошла успешно\n";
                User = username;

                std::ofstream file(
                        accountPath, std::ios_base::app | std::ios_base::ate);

                if (!file.is_open())
                    std::cerr << "\nФайл не открыт!\n";

                for (int i = 0; i < password.size(); i++) {
                    password[i] += CAESAR_SHIFT;
                }
                file << username << " " << password << " 0\n";

                file.close();
                registrationState = false;
                break;
            }
            case 2: {
                CLS();
                std::cout << "Введен неправильный логин или пароль\n";
                PAUSE();
                registrationMenu();
                break;
            }
            }
            break;
        }
        // ВЫХОД ИЗ ПРОГРАММЫ
        case 27: {
            registrationState = false;
            CLS();
            break;
        }
        default: {
            std::cout << "ОШИБКА ВВОДА\n";
            break;
        }
        }
    }
}