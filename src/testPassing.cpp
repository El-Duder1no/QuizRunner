#include "testPassing.h"

void testFilling(
        const std::string testPath,
        const std::string questionsPath,
        std::vector<Questions>& Test)
{
    std::fstream testQuestions(testPath);
    std::ifstream jobBank(questionsPath);

    CheckPath(testQuestions, Test);

    testQuestions.close();

    if (Test.empty()) {
        CheckPath(jobBank, Test);
    }

    jobBank.close();
}

void printQuestion(const std::vector<Questions> Test, const int index)
{
    std::cout << "  Quection ¹" << index + 1 << "\n\n";
    if (Test[index].type == "1" || Test[index].type == "2") {
        std::cout << "  " << Test[index].question << "\n\n";
        std::cout << "  Answer options:\n";
        std::cout << "  " << Test[index].answers[0] << "\n";
        std::cout << "\n  Answer: ";
    } else {
        std::cout << "  " << Test[index].question << "\n\n";
        std::cout << "  Answer: ";
    }
}

double checkAnswers(
        const std::vector<Questions>& Test,
        const std::vector<std::string> answers)
{
    int correctAnswers = 0;
    int testSize = Test.size();

    for (int i = 0; i < testSize; i++) {
        if (Test[i].type == "1" || Test[i].type == "2") {
            if (answers[i] == Test[i].RightAnswers[0]) {
                correctAnswers++;
            }
        } else {
            if (answers[i] == Test[i].RightAnswers[0]
                || answers[i] == Test[i].RightAnswers[1]) {
                correctAnswers++;
            }
        }
    }

    return 100 * correctAnswers / testSize;
}

bool writeResults(
        const std::string resultsPath,
        currentUser currUser,
        const std::string result,
        const std::string time)
{
    std::ofstream resultsFIle(resultsPath);

    if (!resultsFIle.is_open()) {
        return false;
    }

    resultsFIle << currUser.username << " " << result << " " << time << "\n";
    resultsFIle.close();

    return true;
}

void testPass(
        const std::string testPath,
        const std::string questionsPath,
        const std::string resultsPath,
        currentUser currUser)
{
    std::vector<Questions> Test;
    std::vector<std::string> answers;
    testFilling(testPath, questionsPath, Test);

    int lastQuestion = Test.size();
    int currentQuestion = 0;

    pause();

    auto start = std::chrono::high_resolution_clock::now();
    while (currentQuestion < lastQuestion) {
        cls();
        printQuestion(Test, currentQuestion);

        std::string answer;
        std::getline(std::cin, answer);
        answers.push_back(answer);

        pause();
        cls();
        currentQuestion++;
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    double time = duration.count();
    double result = checkAnswers(Test, answers);

    std::string strResults, strTime;
    std::stringstream temp;
    temp << result;
    temp >> strResults;
    temp << time;
    temp >> strTime;

    std::cout << "  Your result: " << strResults << "%\n";
    std::cout << std::setprecision(3) << "  Test time: " << strTime
              << " seconds\n";

    writeResults(resultsPath, currUser, strResults, strTime);
}