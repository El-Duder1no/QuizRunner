#include "adminMenu.h"

void AdminMenu()
{
    std::cout << "  Select menu item:" << std::endl;
    std::cout << "  1 - Create test" << std::endl;
    std::cout << "  2 - Editing test" << std::endl;
    std::cout << "  3 - Log out" << std::endl;
    std::cout << "  >> ";
}

bool Administrator(
        const std::string questionsPath,
        const std::string TestPath,
        const std::string NotInTestPath)
{
    std::ifstream inputText(questionsPath.c_str());
    std::vector<Questions> QuestionsBank, QuestionsForTest, QuestionsOutOfTest;
    std::fstream Test(TestPath.c_str()), NotInTest(NotInTestPath.c_str());
    char chooseKey;
    bool adminMenuState = true;

    if (!CheckPath(inputText, QuestionsBank)) {
        return false;
    }
    if (!CheckPath(Test, QuestionsForTest)) {
        return false;
    }
    if (!CheckPath(NotInTest, QuestionsOutOfTest)) {
        return false;
    } else {
        while (adminMenuState) {
            AdminMenu();
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                cls();
                CreateTest(QuestionsBank, QuestionsForTest, QuestionsOutOfTest);
                Filing(Test, QuestionsForTest, TestPath);
                Filing(NotInTest, QuestionsOutOfTest, NotInTestPath);
                break;
            }
            case '2': {
                cls();
                EditingTest(QuestionsForTest, QuestionsOutOfTest);
                Filing(Test, QuestionsForTest, TestPath);
                Filing(NotInTest, QuestionsOutOfTest, NotInTestPath);
                break;
            }
            case '3': {
                adminMenuState = false;
                cls();
                break;
            }
            default: {
                std::cout << "  Input Error" << std::endl;
                pause();
                cls();
                break;
            }
            }
        }
    }
    NotInTest.close();
    Test.close();
    inputText.close();
    return true;
}

void CreateTest(
        std::vector<Questions>& text,
        std::vector<Questions>& textBuf,
        std::vector<Questions>& textOut)
{
    bool Create = true;
    char chooseKey;
    while (Create) {
        if (textBuf.empty()) {
            AddQuestions(text, textBuf, textOut);
            return;
        } else {
            std::cout << "  You have already created a test, you can:"
                      << std::endl
                      << "  1. Delete existing test" << std::endl
                      << "  2. Return to menu" << std::endl
                      << "  >> ";
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                textBuf.clear();
                textOut.clear();
                cls();
                break;
            }
            case '2': {
                cls();
                Create = false;
                break;
            }
            default: {
                std::cout << "  Input Error" << std::endl;
                pause();
                cls();
                break;
            }
            }
        }
    }
}

void EditingTest(
        std::vector<Questions>& textBuf, std::vector<Questions>& textOut)
{
    bool Editing = true;
    char chooseKey;
    while (Editing) {
        if (!textBuf.empty()) {
            std::cout << "  1.Remove some questions from the test" << std::endl
                      << "  2.Add questions to an existing test" << std::endl
                      << "  3.Return to menu." << std::endl
                      << "  >> ";
            char n;
            std::cin >> n;
            switch (chooseKey = n) {
            case '1': {
                cls();
                RemoveQuestion(textBuf, textOut);

                break;
            }
            case '2': {
                cls();
                AddQuestions(textBuf, textOut);
                break;
            }
            case '3': {
                cls();
                Editing = false;
                break;
            }
            default: {
                std::cout << "  Input Error" << std::endl;
                pause();
                cls();
                break;
            }
            }
        } else {
            std::cout << "  No existing test!" << std::endl
                      << "  1. Return to menu" << std::endl
                      << "  >> ";
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                cls();
                Editing = false;
                break;
            }
            default: {
                std::cout << "  Input Error" << std::endl;
                pause();
                cls();
                break;
            }
            }
        }
    }
}

void PrintQuestions(std::vector<Questions>& questions, int i)
{
    std::cout << "\n  Question number: " << i + 1 << " | " << questions.size()
              << "\n";
    std::cout << "  Question: " << questions[i].question << "\n\n";
    int questionsSize = questions[i].answers.size();
    std::cout << "  Answer options: ";
    for (int j = 0; j < questionsSize; ++j) {
        std::cout << questions[i].answers[j] << " ";
    }
    std::cout << "\n  Right answers: ";
    questionsSize = questions[i].RightAnswers.size();
    for (int j = 0; j < questionsSize; ++j) {
        std::cout << questions[i].RightAnswers[j] << " ";
    }
}

void AddQuestions(
        std::vector<Questions>& text,
        std::vector<Questions>& textBuf,
        std::vector<Questions>& textOut)
{
    int i = 0;
    char chooseKey;
    textOut.clear();
    int textSize = text.size();
    while (i < textSize) {
        PrintQuestions(text, i);
        std::cout << std::endl
                  << "\n  1.Add question to test" << std::endl
                  << "  2.Next question" << std::endl
                  << "  3.Return to menu." << std::endl
                  << "  >> ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            textBuf.push_back(text[i]);
            ++i;
            cls();
            break;
        }
        case '2': {
            textOut.push_back(text[i]);
            ++i;
            cls();
            break;
        }

        default: {
            std::cout << "  Input Error" << std::endl;
            pause();
            cls();
            break;
        }
        case '3': {
            if (i + 1 != textSize) {
                for (; i < textSize; ++i) {
                    textOut.push_back(text[i]);
                }
            }
            cls();
            return;
        }
        }
    }
    return;
}

void Filing(
        std::fstream& questions,
        std::vector<Questions>& textBuf,
        const std::string questionsPath)
{
    int i = 0;
    questions.close();
    questions.open(
            questionsPath.c_str(), std::ofstream::out | std::ofstream::trunc);
    if (!textBuf.empty()) {
        int textBufSize = textBuf.size();
        while (i < textBufSize) {
            questions << textBuf[i].type << std::endl;
            questions << textBuf[i].question << std::endl;
            int RightAnswersSize = textBuf[i].RightAnswers.size();
            for (int j = 0; j < RightAnswersSize; ++j) {
                questions << textBuf[i].answers[j] << " ";
            }
            questions << std::endl;
            for (int j = 0; j < RightAnswersSize; ++j) {
                questions << textBuf[i].RightAnswers[j] << " ";
            }
            questions << std::endl;
            ++i;
        }
    } else {
        return;
    }
}
void AddQuestions(
        std::vector<Questions>& textBuf, std::vector<Questions>& textOut)
{
    int i = 0;
    char chooseKey;
    if (!textOut.empty()) {
        int textOutSize = textOut.size();
        while (i < textOutSize) {
            PrintQuestions(textOut, i);

            std::cout << std::endl
                      << "\n  1.Add question to test" << std::endl
                      << "  2.Next question" << std::endl
                      << "  3.Return to the test edit menu" << std::endl
                      << "  >> ";
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                textBuf.push_back(textOut[i]);
                textOut.erase(textOut.begin() + i);
                textOutSize = textOut.size();
                cls();
                break;
            }
            case '2': {
                ++i;
                cls();
                break;
            }
            default: {
                std::cout << "  Input Error" << std::endl;
                pause();
                cls();
                break;
            }
            case '3': {
                cls();
                return;
            }
            }
        }
    } else {
        std::cout << "  All questions are added to the test!\n";
        pause();
        cls();
    }
    return;
}

void RemoveQuestion(
        std::vector<Questions>& text, std::vector<Questions>& textOut)
{
    int i = 0;
    char chooseKey;
    int textSize = text.size();
    while (i < textSize) {
        PrintQuestions(text, i);
        std::cout << std::endl
                  << "\n  1.Remove question from test" << std::endl
                  << "  2.Next question" << std::endl
                  << "  3.Return to the test Editing menu." << std::endl
                  << "  >> ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            textOut.push_back(text[i]);
            text.erase(text.begin() + i);
            textSize = text.size();
            cls();
            break;
        }
        case '2': {
            ++i;
            cls();
            break;
        }

        default: {
            std::cout << "  Input Error" << std::endl;
            pause();
            cls();
            break;
        }
        case '3': {
            cls();
            return;
        }
        }
    }
    return;
}
