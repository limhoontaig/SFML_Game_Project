#include "textDisplay.h"
#include "player.h"

TextDisplay::TextDisplay(Game* game, sf::Text textMsg, sf::Vector2f pos, sf::Color color)
	: game{ game }, textMsg{ textMsg }, pos{ pos }, color{ color }
{
	textMsg.setFont(this->game->GetFont());
	textMsg.setCharacterSize(70);
	textMsg.setPosition(pos);
	textMsg.setFillColor(color);


}

void TextDisplay::TextStartPrint()
{
	if (this->game->GetPlayer()->GetIsActive() == false)
	{

	}
}

void TextDisplay::TextEndPrint()
{

}
