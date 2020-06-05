#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "resultStruct.h"
#include "resultsParse.h"
#include "testFunctions.h"
#include "userMenu.h"

#ifdef _WIN32
#define RESULTS_PATH "..\\res\\test_files\\Results.txt"
#else
#define RESULTS_PATH "res/test_files/Results.txt"
#endif

std::vector<Results> userResult;

TEST(checkResults, noResults)
{
    std::ifstream File(RESULTS_PATH);

    currentUser currUser;
    currUser.username = "name";
    currUser.accountType = 1;
    CheckPath(File, userResult);

    EXPECT_FALSE(CheckResult(currUser, userResult));
    userResult.clear();
}

TEST(USER_RESULTS, resultExist)
{
    std::ifstream File(RESULTS_PATH);
    currentUser currUser;
    currUser.username = "ip912s24";
    currUser.accountType = 1;
    CheckPath(File, userResult);
    EXPECT_TRUE(CheckResult(currUser, userResult));
    userResult.clear();
}