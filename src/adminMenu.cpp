#include "adminMenu.h"

void AdminMenu()
{
    std::cout << "�������� ����� ����:" << std::endl;
    std::cout << "1 - �������� �����" << std::endl;
    std::cout << "2 - �������������� �����" << std::endl;
    std::cout << "ESC - �����" << std::endl;
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
                std::cout << "������ �����" << std::endl;
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
    std::cout << "����� �������: " << i + 1 << " | " << questions.size() << std::endl;
    std::cout << "������: " << questions[i].question << std::endl;
    for (int j = 0; j < questions[i].RightAnswers.size(); ++j) {
        std::cout << "�������� �������: " << questions[i].answers[j] << std::endl;
        std::cout << "���������� ������: " << questions[i].RightAnswers[j] << std::
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

