#include "TextDisplay.h"
#include "Player.h"

TextDisplay::TextDisplay(Game* game, sf::Text textMsg, sf::Vector2f pos,
	sf::Color color, sf::Color outColor, sf::String string)
	: game{ game }, textMsg{ textMsg }, pos{ pos }, color{ color },
	outColor{ outColor }, string(string)
{
	textMsg.setFont(this->game->GetFont());
	textMsg.setCharacterSize(70);
	textMsg.setPosition(pos);
	textMsg.setFillColor(color);
	textMsg.setOutlineColor(outColor);
	textMsg.setOutlineThickness(2.0f);
}

void TextDisplay::TextPrint()
{
	if (this->game->GetPlayer()->GetIsActive() == false)
	{

	}
}

