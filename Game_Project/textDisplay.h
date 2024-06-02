#pragma once

#include <SFML/Graphics.hpp>
#include "game.h"

class TextDisplay
{
public:
	TextDisplay(Game* game, sf::Text textMsg, sf::Vector2f pos, sf::Color color);
	void TextStartPrint();
	void TextEndPrint();


private:
	Game* game;
	TextDisplay* beginText;
	TextDisplay* endText;
	sf::Text textMsg;
	sf::Vector2f pos;
	sf::Color color;
	sf::String string = "Begin String";

	sf::String beginString = "Start Game";
	sf::String endString = "Game Over";


};
