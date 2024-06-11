#include <SFML/Graphics.hpp>
#include <iostream>

#define CIRCLE_RADIUS 100.0f

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
	sf::Text text1, text2, text3;
	sf::Uint8 r = 0, g = 0, b = 0;
	sf::String msgStr = "Ready Go! Maincodes !!";

	int x = 0, y = 0;
	
	sf::CircleShape circle_shape(CIRCLE_RADIUS);
	circle_shape.setFillColor(sf::Color::Green);
	circle_shape.setRadius(CIRCLE_RADIUS);
	circle_shape.setOutlineColor(sf::Color::Red);
	circle_shape.setOutlineThickness(20.0f);
	circle_shape.setPosition(x, y);

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



	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML Works");
	window.setFramerateLimit(120);
	sf::Font font;
	if (!font.loadFromFile("../resources/font/DS-DIGIB.TTF"))
	{
		return false;
	}

	textPrint(text1, font, 30, 0, 0, sf::Color::Yellow, sf::Color::White, msgStr);
	textPrint(text2, font, 100, 0, 0, sf::Color::White, sf::Color::White, msgStr);
	textPrint(text3, font, 150, 0, 110, sf::Color::Blue, sf::Color::White, msgStr);





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

		if (event.type == sf::Event::MouseButtonPressed)
		{
			switch (event.key.code)
			{
			case sf::Mouse::Left:
			{
				circle_shape.setFillColor(sf::Color::Yellow);
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				std::cout << "왼쪽버튼 눌림 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
				break;
			}
			case sf::Mouse::Right:
			{
				circle_shape.setFillColor(sf::Color::Magenta);
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				std::cout << "오른쪽버튼 눌림 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
				break;
			}
			}
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			switch (event.key.code)
			{
			case sf::Mouse::Left:
			{
				circle_shape.setFillColor(sf::Color::Green);
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				std::cout << "왼쪽버튼 뗌 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
				break;
			}
			case sf::Mouse::Right:
			{
				circle_shape.setFillColor(sf::Color::Green);
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				std::cout << "오른쪽버튼 뗌 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
				break;
			}
			case sf::Mouse::Middle:
			{
				circle_shape.setFillColor(sf::Color::Green);
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				std::cout << "중간버튼 뗌 : pos.x = " << pos.x << " pos.y : " << pos.y << std::endl;
				break;
			}
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
		/*
		if (((int)interval % 2) == 0)
		{
			window.clear(sf::Color::Black);
			x += 1.0;
			y += 1.0;
			text1.setPosition(x, y);
			window.draw(text1);
			window.draw(text2);
			window.draw(text3);

			window.draw(rectangle);
			window.draw(sprite_on);
			if (x > 200) { x = 0, y = 0; }

		}
		else
		{
			window.clear(sf::Color::Black);
			window.draw(sprite_off);
		}
		*/


		window.clear(sf::Color::White);
		circle_shape.setPosition(sf::Vector2f{ x - 100.0f, y - 100.0f });
		window.draw(circle_shape);
		window.display();
	}
	return 0;
}