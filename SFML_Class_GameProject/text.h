#pragma once

#include <SFML/Graphics.hpp>

class GameText
{
public:
	GameText(sf::Text _textMsg, sf::Vector2f _pos, sf::Color _color,
		sf::Color _outColor, sf::String& _string);
	void GetFont();
	sf::Font TextPrint();

private:
	sf::Text _textMsg;
	sf::Vector2f _pos;
	sf::Font _font;
	float _size;
	sf::Color _color;
	sf::Color _outColor;
	sf::String _string;

};