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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			gun.moveRight();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			gun.moveLeft();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			gun.bulletSpawn();

		npcs.update();

		// bullet update
		if (gun.getPosition().y < 0.0f)
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