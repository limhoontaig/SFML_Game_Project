#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Hello SFML");
	window.setFramerateLimit(30);
	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(300.0f, 220.0f);
	sf::RectangleShape myRect(sf::Vector2f{ 50.0f, 15.0f });
	myRect.setFillColor(sf::Color::Cyan);
	myRect.setPosition(sf::Vector2f{ 100.0f, 50.0f });
	myRect.setRotation(45.0);
	float deg = 0.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < 120; i++)
		{
			myRect.setRotation(deg);
			deg += 3.0f;
			window.draw(myRect);
			window.draw(shape);
			window.display();
		}

	}

	sf::Vector2f v{ 2.0f, 3.0f };
	std::cout << v.x << v.y << std::endl;
	return 0;
}