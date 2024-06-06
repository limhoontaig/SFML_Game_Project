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
#include "Gun.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	sf::RenderWindow window(sf::VideoMode(600, 500), "SFML Works!");
	window.setFramerateLimit(120);

	NPC_Set npcs(10);
	Gun gun;



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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{	
			if (showBullet == false) 
			{
				bullet.setPosition(shape.getPosition().x + 20, shape.getPosition().y);
				bullet.move(+1.0f, 0.0f);
				showBullet = true;
			}
		}

		npcs.update();

		// bullet update
		if (bullet.getPosition().y < 0.0f)
			showBullet = false;// shape.setPosition(sf::Vector2f{ 500.0f, 450.0f });
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