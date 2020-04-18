#include <SFML/Graphics.hpp>
#include "textbox.h"

using namespace sf;

int main()
{
	sf::RenderWindow window(VideoMode(400, 200), "Window");

	sf::Font arial;
	arial.loadFromFile("arial.ttf");

	Textbox textbox1(24, sf::Color::Green, false);
	textbox1.setFont(arial);
	textbox1.setPosition({50, 100});
	textbox1.setLimit(true, 10);

	while (window.isOpen())
	{
		Event event;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			textbox1.setSelection(true);
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			textbox1.setSelection(false);
		}

		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			case sf::Event::TextEntered:
				textbox1.typedOn(event);
			}
			
		}

		window.clear();
		textbox1.drawTo(window);
		window.display();
	}

	return 0;
}
