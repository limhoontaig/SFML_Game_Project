#pragma once

#include <SFML/Graphics.hpp>
#include "game.h"

class TextDisplay
{
public:
	TextDisplay(Game* game, sf::Text textMsg, sf::Vector2f pos,
		sf::Color color, sf::Color outColor, sf::String string);
	void TextPrint();

private:
	Game* game;
	sf::Text textMsg;
	sf::Font font;
	float size;
	sf::Vector2f pos;
	sf::Color color;
	sf::Color outColor;
	sf::String string;
	
	//= "Begin String";
	// sf::String beginString = "Start Game";
	// sf::String endString = "Game Over";


};
