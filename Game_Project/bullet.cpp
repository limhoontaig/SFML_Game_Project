#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include "player.h"

Bullet::Bullet(Game* game, float size, const sf::Color& color, float speed)
	: game(game), size{size}, color{color}, speed{speed}
{
	Player* player = game->GetPlayer();
	position = player->GetPosition();

	direction = 

	shape = sf::CircleShape{ size };
	shape.setFillColor(color);	
}

void Bullet::Update(float dt)
{
	UpdatePosition(dt);
	shape.setPosition(position);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Bullet::UpdatePosition(float dt)
{
	position += direction * speed *dt;
}

sf::Vector2f Bullet::GetClosestEnemyDirection()
{
	std::vector<Enemy*> enemies = game->GetEnemies();
	float minDist = 10000.0f;
	sf::Vector2f minDistVec;
	for (int i = 0; i < enemies.size(); i++)
	{
		sf::Vector2f enemyPos = enemies[i]->GetPosition();
		sf::Vector2f bulletToEnemyVec = enemyPos - position;

		float dist = sqrt(bulletToEnemyVec.x * bulletToEnemyVec.x +
			bulletToEnemyVec.y * bulletToEnemyVec.y);
		if (dist < minDist)
		{
			minDist = dist;
			bulletToEnemyVec = bulletToEnemyVec / dist;
		}

	}

}

