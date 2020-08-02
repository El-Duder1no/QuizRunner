#include <fstream>
#include <gtest/gtest.h>

#include "resultsParse.h"

#define RESULTS_PATH "res/test_files/Results.txt"

TEST(resultParseTest, correct)
{
    std::vector<Results> actual;
    std::vector<Results> expected;

    Results buff;
    buff.username = "OlegPetrovich";
    buff.point = "98";
    buff.time = "645";
    expected.push_back(buff);

    buff.username = "ip912s24";
    buff.point = "77";
    buff.time = "585";
    expected.push_back(buff);

    resultsParse(RESULTS_PATH, actual);
    ASSERT_STREQ(actual[0].username.c_str(), expected[0].username.c_str());
    ASSERT_STREQ(actual[0].point.c_str(), expected[0].point.c_str());
    ASSERT_STREQ(actual[0].time.c_str(), expected[0].time.c_str());

    ASSERT_STREQ(actual[1].username.c_str(), expected[1].username.c_str());
    ASSERT_STREQ(actual[1].point.c_str(), expected[1].point.c_str());
    ASSERT_STREQ(actual[1].time.c_str(), expected[1].time.c_str());
}