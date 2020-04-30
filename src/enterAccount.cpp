#include "enterAccount.h"

bool enterAccount(std::vector<Account>& a, int* ind, std::string& User)
{
    std::string username, password;

    CLS();

    std::cout << "¬ведите логин:" << std::endl << ">>";
    std::cin >> username;
    std::cout << "¬ведите пароль:" << std::endl << ">>";
    std::cin >> password;

    for (int i = 0; i < password.size(); i++) {
        password[i] += 3;
    }

    int temp = BinSearch(a, ind, username);

    if (temp == -1) {
        return false;
    } else if (a[ind[temp]].password == password) {
        User = username;
        return true;
    }
}