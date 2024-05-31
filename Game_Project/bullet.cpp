#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include "player.h"

Bullet::Bullet(Game* game, float size, float speed)
	: game(game), size{size}, speed{speed}
{
	Player* player = game->GetPlayer();
	position = player->GetPosition();

	direction = GetClosestEnemyDirection();

	shape.setTexture(game->GetProjectileTexture());
	shape.setTextureRect(sf::IntRect{ 0,0,8,8 });

	shape.setScale(sf::Vector2f{ size, size });
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
			minDistVec = bulletToEnemyVec / dist;
		}
	}
	return minDistVec;
}

