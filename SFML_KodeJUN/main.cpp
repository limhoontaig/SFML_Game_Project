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
	
	sf::RenderWindow window(sf::VideoMode(640, 500), "SFML Works!");
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
			gun.fireBullet();

		npcs.update();
		gun.update();

		window.clear();
		npcs.draw(window);
		gun.draw(window);
		window.display();

	}
	
	return 0;
}