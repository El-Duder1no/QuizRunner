#include "adminMenu.h"

void AdminMenu()
{
    std::cout << "Выберите пункт меню:" << std::endl;
    std::cout << "1 - Создание теста" << std::endl;
    std::cout << "2 - Редактирование теста" << std::endl;
    std::cout << "ESC - Выход" << std::endl;
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
            switch (chooseKey = _getch()) {
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
            case 27: {
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
        return true;
    }
    NotInTest.close();
    Test.close();
    inputText.close();
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

            switch (chooseKey = _getch()) {
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
    int i = 0;
    char chooseKey;
    while (Editing) {
        if (!textBuf.empty()) {
            std::cout << "1.Удалить некоторые вопросы из теста" << std::endl
                      << "2.Добавить вопросы в существубщий тест" << std::endl
                      << "3.Вернуться в меню." << std::endl
                      << "<< ";
            switch (chooseKey = _getch()) {
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

            switch (chooseKey = _getch()) {
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
    for (int j = 0; j < questions[i].RightAnswers.size(); ++j) {
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
    while (i < text.size()) {
        PrintQuestions(text, i);
        std::cout << std::endl
                  << "1.Добавить вопрос в тест" << std::endl
                  << "2.Следующий вопрос" << std::endl
                  << "3.Вернуться в меню." << std::endl
                  << "<< ";

        switch (chooseKey = _getch()) {
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
            if (i + 1 != text.size()) {
                for (; i < text.size(); ++i) {
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
        while (i < textBuf.size()) {
            questions << textBuf[i].type << std::endl;
            questions << textBuf[i].question << std::endl;
            for (int j = 0; j < textBuf[i].RightAnswers.size(); ++j) {
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
        while (i < textOut.size()) {
            PrintQuestions(textOut, i);

            std::cout << std::endl
                      << "1.Добавить вопрос в тест" << std::endl
                      << "2.Следующий вопрос" << std::endl
                      << "3.Вернуться назад" << std::endl
                      << "<< ";

            switch (chooseKey = _getch()) {
            case '1': {
                textBuf.push_back(textOut[i]);
                textOut.erase(textOut.begin() + i);
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
    while (i < text.size()) {
        PrintQuestions(text, i);
        std::cout << std::endl
                  << "1.Удалить вопрос из теста" << std::endl
                  << "2.Следующий вопрос" << std::endl
                  << "3.Вернуться в меню." << std::endl
                  << "<< ";

        switch (chooseKey = _getch()) {
        case '1': {
            textOut.push_back(text[i]);
            text.erase(text.begin() + i);
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
