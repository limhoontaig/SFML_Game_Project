#include "Gun.h"

Gun::Gun()
{
	// player
	gun = sf::CircleShape(20.0f);
	gun.setFillColor(sf::Color::Yellow);
	gun.setPosition(320.0f - 20.0f, 500.0f - 20.0f);

	// Bullet
	bool showBullet = false;
	bullet = sf::CircleShape(5.0f);
	bullet.setFillColor(sf::Color::Red);
}

void Gun::moveRight()
{
	gun.move(+1.0f, 0.0f);
	if (gun.getPosition().x > 600.0f)
		gun.setPosition(sf::Vector2f{ 600.0f, 480.0f });
}

void Gun::moveLeft()
{
	gun.move(-1.0f, 0.0f);
	if (gun.getPosition().x < 0)
		gun.setPosition(sf::Vector2f{ 0.0f, 480.0f });
}

void Gun::fireBullet()
{
	if (showBullet == false)
	{
		bullet.setPosition(gun.getPosition().x + 15, gun.getPosition().y);
		//bullet.move(0.0f, -1.0f);
		showBullet = true;
	}
}

void Gun::update()
{
	if (showBullet == true)
	{
		bullet.move(0.0f, -8.0f);
		if (bullet.getPosition().y < 0.0f)
		{
			showBullet = false;
		}
	}
}

void Gun::draw(sf::RenderWindow& _window)
{
	_window.draw(gun);
	if (showBullet == true)
	{
		_window.draw(bullet);
	}
}


