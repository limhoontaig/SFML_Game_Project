#include "enemy.h"

Enemy::Enemy(const sf::Vector2f pos, float size, sf::Color color, 
	float speed, const Player* player)
	: position {pos}, size{size}, color{color}, 
	speed{speed}, playerRef{player}
{
	shape = sf::CircleShape{ size };
	shape.setFillColor(color);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(3.0f);
}

Enemy::Enemy()
{
}


void Enemy::Update()
{
	shape.setPosition(position);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Enemy::GetPosition()
{
	return sf::Vector2f();
}

void Enemy::UpdatePosition()
{
}

/*
void UpdateEnemyPosition(int numberOfEnemy, float* enemyXPosition,
	float* enemyYPosition, sf::Vector2f pos)
{
	for (int i = 0; i < numberOfEnemy; i++)
	{
		float enemyToPlayerX = pos.x - enemyXPosition[i];
		float enemyToPlayerY = pos.y - enemyYPosition[i];

		float length = sqrt(enemyToPlayerX * enemyToPlayerX +
			enemyToPlayerY * enemyToPlayerY);

		enemyToPlayerX /= length;
		enemyToPlayerY /= length;

		enemyXPosition[i] += enemyToPlayerX * gameSpeed;
		enemyYPosition[i] += enemyToPlayerY * gameSpeed;

	}
}
*/
