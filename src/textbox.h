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
	void setLimit(bool ToF);
	void setLimit(bool ToF, int lim);
	void setSelection(bool sel);

	std::string getText();

	void drawTo(sf::RenderWindow& window);
private:
	sf::Text textbox;
	bool isSelected = false;
	std::ostringstream text;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped);
	void deleteLastChar();
};

#endif