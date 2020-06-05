#include "currentUserStruct.h"
#include "resultStruct.h"
#include "resultsParse.h"
#include "testFunctions.h"
#include "userMenu.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#ifdef _WIN32
#define RESULTS_PATH "..\\res\\test_files\\Results.txt"
#else
#define RESULTS_PATH "res/test_files/Results.txt"
#endif

TEST(checkResults, noResults)
{
    std::vector<Results> userResult;
    std::vector<Results> currResult;

    std::ifstream File(RESULTS_PATH);

    currentUser currUser;
    currUser.username = "name";
    currUser.accountType = 1;
    CheckPath(File, userResult);

    EXPECT_FALSE(CheckResult(currUser, userResult, currResult));
    userResult.clear();
    currResult.clear();
}

TEST(USER_RESULTS, resultExist)
{
    std::vector<Results> userResult;
    std::vector<Results> currResult;

    std::ifstream File(RESULTS_PATH);
    currentUser currUser;
    currUser.username = "ip912s24";
    currUser.accountType = 1;
    CheckPath(File, userResult);
    EXPECT_TRUE(CheckResult(currUser, userResult, currResult));
    currResult.clear();
    userResult.clear();
}