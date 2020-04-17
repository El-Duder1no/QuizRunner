#include "textbox.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

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

private:
	sf::Text textbox;
	bool isSelected = false;
};