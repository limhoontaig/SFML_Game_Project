#include "enemy.h"
#include "player.h"

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
	UpdatePosition();
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Enemy::GetPosition() const
{
	return sf::Vector2f();
}

void Enemy::UpdatePosition()
{	
	float enemyToPlayerX = playerRef->GetPosition().x - position.x;
	float enemyToPlayerY = playerRef->GetPosition().y - position.y;

	float length = sqrt(enemyToPlayerX * enemyToPlayerX +
		enemyToPlayerY * enemyToPlayerY);

	enemyToPlayerX /= length;
	enemyToPlayerY /= length;

	position.x += enemyToPlayerX * speed;
	position.y += enemyToPlayerY * speed;
}

