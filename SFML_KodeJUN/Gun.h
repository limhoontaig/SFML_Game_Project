#pragma once

#include <SFML/Graphics.hpp>

class Gun
{
public:
	Gun();
	void moveRight();
	void moveLeft();
	void fireBullet();
	void update();
	void draw(sf::RenderWindow& _window);

private:
	sf::CircleShape gun;
	sf::CircleShape bullet;
	bool showBullet = false;

};