#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "currentUserStruct.h"
#include "signInOut.h"

#define ACCOUNTS_PATH "..\\res\\test_files\\Accounts.txt"

std::string username, password;
std::vector<Account> accounts;

currentUser User;

int regTest(
        const std::string username,
        const std::string password,
        const std::string accountPath)
{
    int result = registration(username, password, accountPath);

    std::string accountSave = "OlegPetrovich Sdvvz3ug 0\nip912s24 Doskde6w 1\n";

    std::ofstream file(ACCOUNTS_PATH, std::ios_base::trunc);
    file << accountSave;
    file.close();

    return result;
}

TEST(LoginTest, correct)
{
    username = "Ira";
    EXPECT_TRUE(isLoginCorrect(username));
    username = "VeryVeryLongUsername";
    EXPECT_TRUE(isLoginCorrect(username));
    username = "OlegPetrovich";
    EXPECT_TRUE(isLoginCorrect(username));
    username = "ip912s24";
    EXPECT_TRUE(isLoginCorrect(username));
}

TEST(LoginTest, incorrect)
{
    username = "";
    EXPECT_FALSE(isLoginCorrect(username));
    username = "Ia";
    EXPECT_FALSE(isLoginCorrect(username));
    username = "BahmannRestovCheemsRoman";
    EXPECT_FALSE(isLoginCorrect(username));
    username = "-=xXNAGIBATOR1337Xx=-";
    EXPECT_FALSE(isLoginCorrect(username));
}

TEST(PasswordTest, correct)
{
    password = "Passw0rd";
    EXPECT_TRUE(isPassCorrect(password));
    password = "xgNAXa5DyZsw33L91hQJECa0l";
    EXPECT_TRUE(isPassCorrect(password));
    password = "4TPyzp04OzhnRyQ";
    EXPECT_TRUE(isPassCorrect(password));
    password = "EP8Nnqqz5wsnAjkIMj1p";
    EXPECT_TRUE(isPassCorrect(password));
}

TEST(PasswordTest, incorrect)
{
    password = "";
    EXPECT_FALSE(isPassCorrect(password));
    password = "oVwwYStKg7wNhQeXfzeQiAvqVsZSeo";
    EXPECT_FALSE(isPassCorrect(password));
    password = "Hell0";
    EXPECT_FALSE(isPassCorrect(password));
    password = "PassG3n";
    EXPECT_FALSE(isPassCorrect(password));
}

TEST(accauntParseTest, correct)
{
    accountsParse(accounts, ACCOUNTS_PATH);
    EXPECT_EQ(accounts[0].username, "OlegPetrovich");
    EXPECT_EQ(accounts[0].password, "Sdvvz3ug");
    EXPECT_EQ(accounts[0].accountType, 0);
    EXPECT_EQ(accounts[1].username, "ip912s24");
    EXPECT_EQ(accounts[1].password, "Doskde6w");
    EXPECT_EQ(accounts[1].accountType, 1);
}

TEST(enterTest, correct)
{
    accounts.clear();
    username = "OlegPetrovich";
    password = "Passw0rd";
    EXPECT_TRUE(enterAccount(User, password, username, ACCOUNTS_PATH));

    accounts.clear();
    username = "ip912s24";
    password = "Alphab3t";
    EXPECT_TRUE(enterAccount(User, password, username, ACCOUNTS_PATH));
}

TEST(enterTest, allCases)
{
    accounts.clear();
    username = "OlegPetrovich";
    password = "Password";
    EXPECT_FALSE(enterAccount(User, password, username, ACCOUNTS_PATH));

    accounts.clear();
    username = "ip912s23";
    password = "Alphab3t";
    EXPECT_FALSE(enterAccount(User, password, username, ACCOUNTS_PATH));
}

TEST(registrationTest, correct)
{
    username = "OlegPetrovich";
    password = "Password";
    EXPECT_EQ(regTest(username, password, ACCOUNTS_PATH), 0);

    username = "Sasha";
    password = "Passw0rd";
    EXPECT_EQ(regTest(username, password, ACCOUNTS_PATH), 1);

    username = "Sasha";
    password = "Password";
    EXPECT_EQ(regTest(username, password, ACCOUNTS_PATH), 2);
}