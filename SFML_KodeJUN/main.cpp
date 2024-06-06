#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include "Npc.h"
#include "NPC_Set.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	sf::RenderWindow window(sf::VideoMode(600, 500), "SFML Works!");
	window.setFramerateLimit(120);

	// player
	sf::CircleShape shape(20.0f);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(300.0f, 450.0f);

	// Bullet
	sf::CircleShape bullet(5.0f);
	bullet.setFillColor(sf::Color::Red);
	bool showBullet = false;


	NPC_Set npcs(10);

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


		npcs.update();

		// bullet update
		if (showBullet == true)
		{
			bullet.move(0.0f, -8.0f);
		}

		window.clear();
		window.draw(shape);
		npcs.draw(window);
		if (showBullet == true)
		{
			window.draw(bullet);
		}
		window.display();

	}
	
	return 0;
}