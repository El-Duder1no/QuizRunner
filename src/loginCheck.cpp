#include "loginCheck.h"
bool isLoginCorrect(std::string username)
{
	if (username.size() < 3 || username.size() > 20) {
		return false;
	}

	int n = username.length();
	char* buff = new char[n];
	strcpy_s(buff, n + 1, username.c_str());

	for (int i = 0; i < n; i++) {
		if (isgraph(buff[i]) == false) {
			return false;
		}
	}

	return true;
}
