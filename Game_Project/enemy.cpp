#include "enemy.h"
#include "player.h"
#include "game.h"

Enemy::Enemy(Game* game, const sf::Vector2f pos, float size, float speed)
	:game{ game }, position { pos }, size{ size }, speed{ speed }
{
	shape.setTexture(game->GetShipTexture());
	shape.setTextureRect(sf::IntRect{ 40,0,8,8 });
	
	shape.setScale(sf::Vector2f{ size, size });
}

Enemy::Enemy()
{
}


void Enemy::Update(float dt)
{
	UpdatePosition(dt);
	shape.setPosition(position);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Vector2f Enemy::GetPosition() const
{
	return sf::Vector2f(position);
}


void Enemy::UpdatePosition(float dt)
{	
	float enemyToPlayerX = game->GetPlayer()->GetPosition().x - position.x;
	float enemyToPlayerY = game->GetPlayer()->GetPosition().y - position.y;

	float length = sqrt(enemyToPlayerX * enemyToPlayerX +
		enemyToPlayerY * enemyToPlayerY);

	enemyToPlayerX /= length;
	enemyToPlayerY /= length;

	position.x += enemyToPlayerX * speed;
	position.y += enemyToPlayerY * speed;
}

