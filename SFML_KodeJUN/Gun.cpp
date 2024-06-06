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
	{
		gun.move(+1.0f, 0.0f);
		if (gun.getPosition().x > 500)
			gun.setPosition(sf::Vector2f{ 500.0f, 450.0f });
	}
	
}

void Gun::moveLeft()
{
	
	{
		gun.move(-1.0f, 0.0f);
		if (gun.getPosition().x < 0)
			gun.setPosition(sf::Vector2f{ 0.0f, 450.0f });
	}
}

void Gun::bulletSpawn()
{
	{
		if (showBullet == false)
		{
			bullet.setPosition(gun.getPosition().x + 20, gun.getPosition().y);
			bullet.move(+1.0f, 0.0f);
			showBullet = true;
		}
	}
}


