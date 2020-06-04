#include <fstream>
#include <gtest/gtest.h>

#include "resultsParse.h"

#ifdef _WIN32
#define RESULTS_PATH "..\\res\\test_files\\Results.txt"
#else
#define RESULTS_PATH "res/test_files/Results.txt"
#endif

bool resultsTest(
        std::ifstream& results,
        std::vector<Results>& actual,
        const std::vector<Results>& expected)
{
    resultsParse(results, actual);

    int count = 0;
    for (int i = 0; i < 2; i++) {
        if (actual[i].username == expected[i].username
            && actual[i].point == expected[i].point
            && actual[i].time == expected[i].time) {
            count++;
        }
    }
    if (count == 2)
        return true;
    else
        return false;
}

TEST(resultParseTest, correct)
{
    std::ifstream file(RESULTS_PATH);
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

    resultsParse(file, actual);
    ASSERT_STREQ(actual[0].username.c_str(), expected[0].username.c_str());
    ASSERT_STREQ(actual[0].point.c_str(), expected[0].point.c_str());
    ASSERT_STREQ(actual[0].time.c_str(), expected[0].time.c_str());

    ASSERT_STREQ(actual[1].username.c_str(), expected[1].username.c_str());
    ASSERT_STREQ(actual[1].point.c_str(), expected[1].point.c_str());
    ASSERT_STREQ(actual[1].time.c_str(), expected[1].time.c_str());
}