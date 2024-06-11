#include <SFML/Graphics.hpp>
#include <iostream>

int textPrint(sf::Text& textMsg, sf::Font& font, int size, float x, float y,
	const sf::Color& color, const sf::Color& outColor, sf::String p)
{
	textMsg.setFont(font);
	textMsg.setCharacterSize(size);
	textMsg.setPosition(x, y);
	textMsg.setFillColor(color);
	textMsg.setOutlineColor(outColor);
	textMsg.setOutlineThickness(1.0f);
	textMsg.setString(p);
	return 0;
}

int main()
{
	sf::RectangleShape rectangle(sf::Vector2f{ 200.0f, 200.0f });
	rectangle.setFillColor(sf::Color::Blue);

	sf::Clock clock;
	sf::Clock ai_Timer;
	float interval = 0, delay1 = 8.0f;
	int count = 0;

	const sf::Time ai_time = sf::seconds(0.5f);

	std::cout << "프로그램이 시작되었습니다. " << std::endl;

	sf::Texture color_off, color_on;
	sf::Sprite sprite_on, sprite_off;

	color_on.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Characters.png");
	//color_off.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Characters.png");
	color_off.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Ships.png");

	sprite_on.setTexture(color_on);
	sprite_on.setTextureRect(sf::IntRect(0, 0, 30, 30));
	sprite_on.setPosition(sf::Vector2f{ 300.0f, 250.0f });
	sprite_on.scale(sf::Vector2f{ 2.0f, 2.0f });

	sprite_off.setTexture(color_off);
	sprite_off.setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprite_off.setPosition(sf::Vector2f{ 100.0f, 150.0f });



	sf::RenderWindow window(sf::VideoMode(504, 504), "SFML Works");
	window.setFramerateLimit(120);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		interval += time;
		
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
				std::cout << "프로그램이 종료되었습니다." << std::endl;
			}
		}

		if (ai_Timer.getElapsedTime() > ai_time)
		{
			ai_Timer.restart();
			std::cout << "ai_Timer..." << interval << std::endl;
		}

		if (interval > delay1 )
		{
			ai_Timer.restart();
			std::cout << "interval = " << interval << " count : " << count << std::endl;

			interval = 0;
			count++;
		}

		if (((int)interval % 2) == 0)
		{
			window.clear(sf::Color::White);
			window.draw(rectangle);
			window.draw(sprite_on);
		}
		else
		{
			window.clear(sf::Color::White);
			window.draw(sprite_off);
		}


		//window.clear(sf::Color::White);
		window.display();
	}
	return 0;
}