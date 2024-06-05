#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 500), "SFML Works!");
	window.setFramerateLimit(120);
	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(300.0f, 450.0f);
	sf::RectangleShape myRect(sf::Vector2f{ 50.0f, 15.0f });
	myRect.setFillColor(sf::Color::Cyan);
	myRect.setPosition(sf::Vector2f{ 100.0f, 50.0f });
		
	float offset_x = 1.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			shape.move(-1.0f, 0.0f);
			if (shape.getPosition().x < 0)
				shape.setPosition(sf::Vector2f{ 0.0f, 450.0f });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			shape.move(+1.0f, 0.0f);
			if (shape.getPosition().x > 500)
				shape.setPosition(sf::Vector2f{ 500.0f, 450.0f });
		}



		sf::Vector2f pos = myRect.getPosition();
		if (pos.x > 600.0f)
		{
			offset_x = -1.0f;
		}
		else if (pos.x < 30.0f)
		{
			offset_x = 1.0f;
		}

		myRect.move(offset_x, 0);

		window.clear();
		window.draw(shape);
		window.draw(myRect);
		window.display();

	}
	return 0;
}