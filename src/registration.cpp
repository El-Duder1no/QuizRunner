#include "registration.h"

int registration(
        std::vector<Account>& a,
        std::string& username,
        std::string& password,
        std::wstring accountPath)
{
    CLS();

    std::cout << "Длина имени пользователя должна" << std::endl
              << "составлять от 3 до 20 символов." << std::endl
              << "Также, оно может состоять " << std::endl
              << "из букв латинского алфавита, цифр или знаков\n"
              << std::endl;

    std::cout << "Длина пароля от 8 до 25 символов." << std::endl
              << "Пароль должен состоять из букв" << std::endl
              << "латинского алфавита и должен содержать" << std::endl
              << "как минимум одну заглавную букву и цифру.\n"
              << std::endl;

    std::cout << "Введите логин:" << std::endl << ">>";
    std::getline(std::cin, username);
    std::cout << "Введите пароль:" << std::endl << ">>";
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
    //---------

    if (isPassCorrect(password) == true && isLoginCorrect(username) == true) {
        return 1;
    } else {
        return 2;
    }
}