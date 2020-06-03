#include "adminMenu.h"

void AdminMenu()
{
    std::cout << "Выберите пункт меню:" << std::endl;
    std::cout << "1 - Создание теста" << std::endl;
    std::cout << "2 - Редактирование теста" << std::endl;
    std::cout << "3 - Выход" << std::endl;
    std::cout << ">> ";
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
                CLS();
                CreateTest(QuestionsBank, QuestionsForTest, QuestionsOutOfTest);
                if (!Filing(Test, QuestionsForTest, TestPath)) {
                    return 0;
                }
                if (!Filing(NotInTest, QuestionsOutOfTest, NotInTestPath)) {
                    return 0;
                }
                break;
            }
            case '2': {
                CLS();
                EditingTest(QuestionsForTest, QuestionsOutOfTest);
                if (!Filing(Test, QuestionsForTest, TestPath)) {
                    return 0;
                }
                if (!Filing(NotInTest, QuestionsOutOfTest, NotInTestPath)) {
                    return 0;
                }
                break;
            }
            case '3': {
                adminMenuState = false;
                CLS();
                break;
            }
            default: {
                std::cout << "Ошибка ввода" << std::endl;
                PAUSE();
                CLS();
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
            std::cout << "У вас уже создан тест, вы можете:" << std::endl
                      << "1. Удалить существующий тест" << std::endl
                      << "2. Вернуться в меню" << std::endl
                      << "<< ";
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                textBuf.clear();
                textOut.clear();
                CLS();
                break;
            }
            case '2': {
                CLS();
                Create = false;
                break;
            }
            default: {
                std::cout << "ОШИБКА ВВОДА" << std::endl;
                PAUSE();
                CLS();
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
            std::cout << "1.Удалить некоторые вопросы из теста" << std::endl
                      << "2.Добавить вопросы в существубщий тест" << std::endl
                      << "3.Вернуться в меню." << std::endl
                      << "<< ";
            char n;
            std::cin >> n;
            switch (chooseKey = n) {
            case '1': {
                CLS();
                RemoveQuestion(textBuf, textOut);

                break;
            }
            case '2': {
                CLS();
                AddQuestions(textBuf, textOut);
                break;
            }
            case '3': {
                CLS();
                Editing = false;
                break;
            }
            default: {
                std::cout << "ОШИБКА ВВОДА" << std::endl;
                PAUSE();
                CLS();
                break;
            }
            }
        } else {
            std::cout << "Нет существующего теста!" << std::endl
                      << "1. Вернуться в меню" << std::endl
                      << "<< ";
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                CLS();
                Editing = false;
                break;
            }
            default: {
                std::cout << "Ошибка ввода" << std::endl;
                PAUSE();
                CLS();
                break;
            }
            }
        }
    }
}

void PrintQuestions(std::vector<Questions>& questions, int i)
{
    std::cout << "Номер вопроса: " << i + 1 << " | " << questions.size()
              << std::endl;
    std::cout << "Вопрос: " << questions[i].question << std::endl;
    int questionsSize = questions[i].RightAnswers.size();
    for (int j = 0; j < questionsSize; ++j) {
        std::cout << "Варианты ответов: " << questions[i].answers[j]
                  << std::endl;
        std::cout << "Правильные ответы: " << questions[i].RightAnswers[j]
                  << std::endl;
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
                  << "1.Добавить вопрос в тест" << std::endl
                  << "2.Следующий вопрос" << std::endl
                  << "3.Вернуться в меню." << std::endl
                  << "<< ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            textBuf.push_back(text[i]);
            ++i;
            CLS();
            break;
        }
        case '2': {
            textOut.push_back(text[i]);
            ++i;
            CLS();
            break;
        }

        default: {
            std::cout << "ОШИБКА ВВОДА" << std::endl;
            PAUSE();
            CLS();
            break;
        }
        case '3': {
            if (i + 1 != textSize) {
                for (; i < textSize; ++i) {
                    textOut.push_back(text[i]);
                }
            }
            CLS();
            return;
        }
        }
    }
    return;
}

bool Filing(
        std::fstream& questions,
        std::vector<Questions>& textBuf,
        const std::string questionsPath)
{
    questions.close();
    questions.open(
            questionsPath.c_str(), std::ofstream::out | std::ofstream::trunc);
    int i = 0;
    if (!questions) {
        return false;
    } else if (!textBuf.empty()) {
        int textBufSize = textBuf.size();
        while (i < textBufSize) {
            questions << textBuf[i].type << std::endl;
            questions << textBuf[i].question << std::endl;
            int RightAnswersSize = textBuf[i].RightAnswers.size();
            for (int j = 0; j < RightAnswersSize; ++j) {
                questions << textBuf[i].answers[j] << std::endl;
                questions << textBuf[i].RightAnswers[j] << std::endl;
            }
            ++i;
        }
    }
    return true;
}

void AddQuestions(
        std::vector<Questions>& textBuf, std::vector<Questions>& textOut)
{
    int i = 0, chooseKey;
    if (!textOut.empty()) {
        int textOutSize = textOut.size();
        while (i < textOutSize) {
            PrintQuestions(textOut, i);

            std::cout << std::endl
                      << "1.Добавить вопрос в тест" << std::endl
                      << "2.Следующий вопрос" << std::endl
                      << "3.Вернуться назад" << std::endl
                      << "<< ";
            std::cin >> chooseKey;
            switch (chooseKey) {
            case '1': {
                textBuf.push_back(textOut[i]);
                textOut.erase(textOut.begin() + i);
                textOutSize = textOut.size();
                CLS();
                break;
            }
            case '2': {
                ++i;
                CLS();
                break;
            }
            default: {
                std::cout << "ОШИБКА ВВОДА" << std::endl;
                PAUSE();
                CLS();
                break;
            }
            case '3': {
                CLS();
                return;
            }
            }
        }
    } else {
        std::cout << "В тест добавлены все вопросы!\n";
        PAUSE();
        CLS();
    }
    return;
}

void RemoveQuestion(
        std::vector<Questions>& text, std::vector<Questions>& textOut)
{
    int i = 0, chooseKey;
    int textSize = text.size();
    while (i < textSize) {
        PrintQuestions(text, i);
        std::cout << std::endl
                  << "1.Удалить вопрос из теста" << std::endl
                  << "2.Следующий вопрос" << std::endl
                  << "3.Вернуться в меню." << std::endl
                  << "<< ";
        std::cin >> chooseKey;
        switch (chooseKey) {
        case '1': {
            textOut.push_back(text[i]);
            text.erase(text.begin() + i);
            textSize = text.size();
            CLS();
            break;
        }
        case '2': {
            ++i;
            CLS();
            break;
        }

        default: {
            std::cout << "Ошибка ввода" << std::endl;
            PAUSE();
            CLS();
            break;
        }
        case '3': {
            CLS();
            return;
        }
        }
    }
    return;
}
