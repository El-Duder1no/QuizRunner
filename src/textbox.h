#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class Textbox {
public:
	Textbox();
	Textbox(int size, sf::Color color, bool sel);

private:
	sf::Text textbox;
	bool isSelected = false;
};

#endif