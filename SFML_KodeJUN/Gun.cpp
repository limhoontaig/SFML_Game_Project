#include "Gun.h"

Gun::Gun()
{
	// player
	gun = sf::CircleShape(20.0f);
	gun.setFillColor(sf::Color::Yellow);
	gun.setPosition(320.0f - 20.0f, 480.0f - 20.0f);

	// Bullet
	bool showBullet = false;
	bullet = sf::CircleShape(5.0f);
	bullet.setFillColor(sf::Color::Red);
}

void Gun::moveRight()
{
}
