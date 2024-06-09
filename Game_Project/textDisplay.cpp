#include "textDisplay.h"
#include "player.h"

TextDisplay::TextDisplay(Game* game, sf::Text textMsg, sf::Vector2f pos, 
	sf::Color color, sf::Color outColor, sf::String string, TextDisplayType type)
	: game{ game }, textMsg{textMsg}, pos{pos}, color{color}, string{string}, type{type}
{
	textMsg.setFont(this->game->GetFont());
	textMsg.setCharacterSize(70);
	textMsg.setPosition(pos);
	textMsg.setFillColor(color);
	textMsg.setOutlineColor(outColor);
	textMsg.setOutlineThickness(2.0f);
}

void TextDisplay::TextUpdate()
{
}

void TextDisplay::draw(sf::RenderWindow& window)
{
	window.clear();
	{
		game->GetElapsedTime();
		if (game->GetElapsedTime() < 1.5 && game->GetElapsedTime() > 0)
			window.draw(text2);
		if (game->GetElapsedTime() < 1.5 && game->GetElapsedTime() > 0.5f)
			window.draw(text1);
		if (game->GetElapsedTime() < 1.5 && game->GetElapsedTime() > 1.0f)
			window.draw(text3);
		window.draw(textElapsedTimeTitle);
		window.draw(textElapsedTime);
		window.draw(textScoreTitle);
		window.draw(textScore);
	}

	window.display();
}

void TextDisplay::TextPrint()
{
	if (this->game->GetPlayer()->GetIsActive() == false)
	{

	}
}

