#include "signInOut.h"

void registrationMenu()
{
    std::cout << "Выберите пункт меню:\n";
    std::cout << "1 - Вход в учетную запись\n";
    std::cout << "2 - Регистрация\n";
    std::cout << "ESC - выход\n";
    std::cout << ">> ";
}
void registrationInfo()
{
    CLS();

    std::cout << "Длина имени пользователя должна\n"
              << "составлять от 3 до 20 символов.\n"
              << "Также, оно может состоять \n"
              << "из букв латинского алфавита, цифр или знаков\n\n";

    std::cout << "Длина пароля от 8 до 25 символов.\n"
              << "Пароль должен состоять из букв\n"
              << "латинского алфавита и должен содержать\n"
              << "как минимум одну заглавную букву и цифру.\n\n";
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

	int accountsSize = accounts.size();
    int* index = new int[accountsSize];
    for (int i = 0; i < accountsSize; i++) {
        index[i] = i;
    }
    SelectSort(accounts, index);

	int passwordSize = password.size();
    for (int i = 0; i < passwordSize; i++) {
        password[i] += CAESAR_SHIFT;
    }

    int temp = BinSearch(accounts, index, username);

    if (temp != -1 && accounts[index[temp]].password == password) {
        User.username = accounts[index[temp]].username;
        User.accountType = accounts[index[temp]].accountType;
        delete[] index;
        return true;
    } else {
        delete[] index;
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

	int accountsSize = accounts.size();
    int* index = new int[accountsSize];
    for (int i = 0; i < accountsSize; i++) {
        index[i] = i;
    }
    SelectSort(accounts, index);
    int temp = BinSearch(accounts, index, username);

    delete[] index;

    if (temp != -1) {
        return 0;
    }
    if (isPassCorrect(password) == true && isLoginCorrect(username) == true) {
        return 1;
    } else {
        return 2;
    }
}

void signInOut(const std::string accountPath, currentUser& User)
{
    char chooseKey;
    bool registrationState = true;

    registrationMenu();
    while (registrationState) {
        switch (chooseKey = _getch()) {
        // ВХОД
        case '1': {
            std::string username, password;

            CLS();

            std::cout << "Введите логин:\n>>";
            std::getline(std::cin, username);
            std::cout << "Введите пароль:\n>>";
            std::getline(std::cin, password);

            bool temp = enterAccount(User, password, username, accountPath);

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
            break;
        }
        // РЕГИСТРАЦИЯ
        case '2': {
            std::string username, password;

            registrationInfo();

            std::cout << "Введите логин:\n>>";
            std::getline(std::cin, username);
            std::cout << "Введите пароль:\n>>";
            std::getline(std::cin, password);

            int temp = registration(username, password, accountPath);
            switch (temp) {
            case 0: {
                CLS();
                std::cout << "Такой аккаунт уже существует\n";
                PAUSE();
                registrationMenu();
                break;
            }
            case 1: {
                std::cout << "Регистрация прошла успешно\n";
                User.username = username;
                User.accountType = 0;

                std::ofstream file(
                        accountPath, std::ios_base::app | std::ios_base::ate);

                if (!file.is_open()) {
                    std::cerr << "\nФайл не открыт!\n";
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
