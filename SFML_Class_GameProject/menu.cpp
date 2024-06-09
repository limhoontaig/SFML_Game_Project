//#pragma warning (disable : 4996)
#include "menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("../resources/font/arial.ttf"))
	{
		//
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f{ width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 });

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Option");
	menu[1].setPosition(sf::Vector2f{ width / 2, height / (MAX_NUMBER_OF_ITEMS + 1 ) * 2 });

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f{ width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3 });

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex > 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
	else {
		selectedItemIndex = 0;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex < MAX_NUMBER_OF_ITEMS - 1)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
	else {
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}


