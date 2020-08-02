#include "resultsParse.h"
#include "structures.h"
#include "testFunctions.h"
#include "userMenu.h"

#include <fstream>
#include <gtest/gtest.h>
#include <string>
#include <vector>

#define RESULTS_PATH "res/test_files/Results.txt"

TEST(checkResults, noResults)
{
    std::vector<Results> userResult;
    std::vector<Results> currResult;

    currentUser currUser;
    currUser.username = "name";
    currUser.accountType = 1;
    CheckPath(RESULTS_PATH, userResult);

    EXPECT_FALSE(CheckResult(currUser, userResult, currResult));
    userResult.clear();
    currResult.clear();
}

TEST(USER_RESULTS, resultExist)
{
    std::vector<Results> userResult;
    std::vector<Results> currResult;

    currentUser currUser;
    currUser.username = "ip912s24";
    currUser.accountType = 1;
    CheckPath(RESULTS_PATH, userResult);
    EXPECT_TRUE(CheckResult(currUser, userResult, currResult));
    currResult.clear();
    userResult.clear();
}