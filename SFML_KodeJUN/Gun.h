#pragma once

#include <SFML/Graphics.hpp>

class Gun
{
public:
	Gun();
	void moveRight();
	void moveLeft();
	void bulletSpawn();

private:
	sf::CircleShape gun;
	sf::CircleShape bullet;
	bool showBullet;

};