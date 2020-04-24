#include <iostream>
#include <conio.h>
#include <string>

#include "parseString.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	char chooseKey;
	bool registrationState = true;

	cout << "Âûáåðèòå ïóíêò ìåíþ:" << endl;
	cout << "1 - Âõîä â ó÷åòíóþ çàïèñü" << endl;
	cout << "2 - Ðåãèñòðàöèÿ" << endl;
	cout << "ESC - âûõîä" << endl;
	
	while (registrationState) {
		switch (chooseKey = _getch())
		{
		case '1' : 
			cout << "Òû âûáðàë âõîä â ó÷åòêó" << endl;
			// ÔÓÍÊÖÈß ÂÕÎÄÀ
			break;
		case '2':
			cout << "Òû âûáðàë ðåãèñòðàöèþ" << endl;
			// ÔÓÍÊÖÈß ÐÅÃÈÑÒÐÀÖÈÈ
			break;
		case 27:
			cout << "Òû âûáðàë âûéòè èç ïðîãðàììû" << endl;
			registrationState = false;
			break;
		default : 
			cout << "ÎØÈÁÊÀ ÂÂÎÄÀ" << endl;
			break;
		}
	}

	system("PAUSE");
	return 0;
}
