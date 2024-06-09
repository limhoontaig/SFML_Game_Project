#include "text.h"
#include <iostream>



GameText::GameText(sf::Text _textMsg, sf::Vector2f _pos, sf::Color _color, 
	sf::Color _outColor, sf::String& _string)
{
	sf::Font font;
	//font = GetFont();

}

sf::Font GetFont()
{
	sf::Font font;
	if (!font.loadFromFile("../resources/font/arial.ttf"))
	{
		std::cout << "file read error!" << std::endl;
	}
	return font;
}

//oid GameText::TextPrint()
//{

//}
