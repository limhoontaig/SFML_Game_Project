#pragma once
#include "NPC_Set.h"
#include <SFML/Graphics.hpp>

class NPC_Set;
class Gun
{
public:
	Gun();
	void moveRight();
	void moveLeft();
	void fireBullet();
	void update(NPC_Set& npcs);
	void draw(sf::RenderWindow& _window);

private:
	sf::CircleShape gun;
	sf::CircleShape bullet;
	bool showBullet = false;

};