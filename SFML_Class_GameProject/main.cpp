#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.h"

int main()
{
	float width = 1280, height = 720;
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML WORKS!");

	// Menu BackGround
	sf::Texture texture;

	if (!texture.loadFromFile("8196177_size.png"))
	{
		std::cout << "Image File Load Error!!!" << std::endl;
		system("pause");
	}

	sf::Sprite menuBg;
	menuBg.setTexture(texture);

	menuBg.setPosition(sf::Vector2f{ 640.0f, 360.0f });
	sf::Rect<float> size = menuBg.getGlobalBounds();
	menuBg.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	//Menu
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:

					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Play Button hasBeen pressed." << std::endl;
						break;
					case 1:
						std::cout << "Option Button hasBeen pressed." << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
			}
		}
		window.clear();
		window.draw(menuBg);
		menu.Draw(window);
		window.display();
	}
	return 0;
}