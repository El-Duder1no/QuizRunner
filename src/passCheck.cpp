#include "passCheck.h"

bool isPassCorrect(std::string password)
{
	if (password.size() < 8 || password.size() > 25)
		return 0;

	char* buff = new char[password.length() + 1];
	strcpy_s(buff, password.length() + 1, password.c_str());

	bool isUpper = false, isDigit = false;
	for (int i = 0; i < password.length() + 1; i++) {
		if (isdigit(buff[i])) {
			isDigit = true;
		}
		if (isalpha(buff[i])) {
			if (isupper(buff[i])) {
				isUpper = true;
			}
		}
	}

	if (isUpper == true && isDigit == true) {
		return true;
	}
	else {
		return false;
	}
}