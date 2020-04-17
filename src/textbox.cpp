#include "textbox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox {
public:
	Textbox() {}
	Textbox(int size, sf::Color color, bool sel) {
		textbox.setCharacterSize = size;
		textbox.setColor(color);
		isSelected = sel;

		if (sel) {
			textbox.setString("_");
		} else {
			textbox.setString("");
		}
	}

	void setFont(sf::Font& font) {
		textbox.setFont(font);
	}

	void setPosition(sf::Vector2f pos) {
		textbox.setPosition(pos);
	}

	void setLimit(bool ToF) {
		hasLimit = ToF;
	}

	void setLimit(bool ToF, int lim) {
		hasLimit = ToF;
		limit = lim;
	}
private:
	sf::Text textbox;
	bool isSelected = false;
	std::ostringstream text;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped) {
		if (charTyped != DELETE_KEY &&
			charTyped != ENTER_KEY &&
			charTyped != ESCAPE_KEY) {
			text << static_cast<char>(charTyped);
		} else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "_");
	}

	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) 
			newT += t[i];
		text.str("");
		text << newT;

		textbox.setString(text.str());
	}
};