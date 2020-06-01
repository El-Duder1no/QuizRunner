#include "adminMenu.h"

void AdminMenu()
{
    std::cout << "Выберите пункт меню:" << std::endl;
    std::cout << "1 - Создание теста" << std::endl;
    std::cout << "2 - Редактирование теста" << std::endl;
    std::cout << "ESC - Выход" << std::endl;
    std::cout << ">> ";
}

bool Administrator(const std::string questionsPath, const std::string TestPath, const std::string NotInTestPath)
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
    }
	 else {
        while (adminMenuState) {
            AdminMenu();
            switch (chooseKey = _getch()) {
            case '1': {
                CLS();
            //    CreateTest
                if (!Filing(Test, QuestionsForTest, TestPath)){
				
                    return 0;
            }
				if(!Filing(NotInTest, QuestionsOutOfTest, NotInTestPath))
                {
				return 0;
}
                break;
            }
            case '2': {
                CLS();
                //EditingTest
                               if (!Filing(Test, QuestionsForTest, TestPath)){
				
                    return 0;
            }
				if(!Filing(NotInTest, QuestionsOutOfTest, NotInTestPath))
                {
				return 0;
}
break;
            }
            case 27: {
                adminMenuState = false;
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
    Test.close();
    inputText.close();

}

void PrintQuestions(std::vector<Questions>& questions, int i)
{
    std::cout << "Номер вопроса: " << i + 1 << " | " << questions.size() << std::endl;
    std::cout << "Вопрос: " << questions[i].question << std::endl;
    for (int j = 0; j < questions[i].RightAnswers.size(); ++j) {
        std::cout << "Варианты ответов: " << questions[i].answers[j] << std::endl;
        std::cout << "Правильные ответы: " << questions[i].RightAnswers[j] << std::
		endl;
    }
}


bool Filing(std::fstream& questions, std::vector<Questions>& textBuf, const std::string questionsPath)
{
	questions.close();
    questions.open(questionsPath.c_str(),std::ofstream::out | std::ofstream::trunc);
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

