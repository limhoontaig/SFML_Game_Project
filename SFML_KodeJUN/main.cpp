#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 500), "SFML Works!");
	window.setFramerateLimit(120);

	// player
	sf::CircleShape shape(50.0f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(300.0f, 450.0f);



	// target
	std::vector<sf::RectangleShape> npcs(4);

	int inc = 0;
	for (auto& _e : npcs)
	{
		_e.setSize(sf::Vector2f{ 30.0f, 10.0f });
		_e.setFillColor(sf::Color::Cyan);
		_e.setPosition(30.0f+inc, 30.0f+inc);
		inc += 20.0f;
	}

	sf::RectangleShape myRect(sf::Vector2f{ 50.0f, 10.0f });
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


		for (auto& _e:npcs)
		{ 
			sf::Vector2f pos = _e.getPosition();
			if (pos.x > 600.0f)
			{
				offset_x = - (float)((rand() % 10) + 1.0f);
			}
			else if (pos.x < 30.0f)
			{
				offset_x = (float)((rand() % 10) + 1.0f);
			}

			_e.move(offset_x, 0);
		}

		window.clear();
		window.draw(shape);
		for (auto& _e : npcs)
		{
			window.draw(_e);

		}
		window.display();

	}
	return 0;
}