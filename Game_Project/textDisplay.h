#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include "game.h"

enum TextDisplayType
{
	STARTUP, INPROCESS, PLAYERFALSE, RESTART, ENDOFGAME,
};

class TextDisplay
{
public:
	TextDisplay(Game* game, sf::Text textMsg, sf::Vector2f pos,
		sf::Color color, sf::Color outColor, sf::String string, TextDisplayType type);
	void TextUpdate();
	void draw(sf::RenderWindow& window);
	void TextPrint();

private:
	Game* game;
	sf::Text textMsg;
	TextDisplayType type;
	sf::Font font;
	float size;
	sf::Vector2f pos;
	sf::Color color;
	sf::Color outColor;
	sf::String string;
	
	//= "Begin String";
	// sf::String beginString = "Start Game";
	// sf::String endString = "Game Over";
	std::vector<TextDisplay> textDisplays;
	sf::Text text1, text2, text3, textScoreTitle, textScore, textElapsedTimeTitle, textElapsedTime;

};
