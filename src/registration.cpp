#include "registration.h"

int registration(
        std::vector<Account>& a,
        std::string& username,
        std::string& password,
        std::wstring accountPath)
{
    CLS();

    std::cout << "����� ����� ������������ ������" << std::endl
              << "���������� �� 3 �� 20 ��������." << std::endl
              << "�����, ��� ����� �������� " << std::endl
              << "�� ���� ���������� ��������, ���� ��� ������\n"
              << std::endl;

    std::cout << "����� ������ �� 8 �� 25 ��������." << std::endl
              << "������ ������ �������� �� ����" << std::endl
              << "���������� �������� � ������ ���������" << std::endl
              << "��� ������� ���� ��������� ����� � �����.\n"
              << std::endl;

    std::cout << "������� �����:" << std::endl << ">>";
    std::getline(std::cin, username);
    std::cout << "������� ������:" << std::endl << ">>";
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