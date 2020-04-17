#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Textbox {
public:
	Textbox();
	Textbox(int size, sf::Color color, bool sel);

	void setFont(sf::Font &font);
	void setPosition(sf::Vector2f pos);
private:
	sf::Text textbox;
	bool isSelected = false;
	std::ostringstream text;

	void inputLogic(int charTyped);
	void deleteLastChar();
};

#endif