#include "game.h"
#include "enemy.h"
#include "player.h"

Enemy::Enemy(Game* game, const sf::Vector2f pos, float size, float speed)
	: Actor{ game, pos , speed, size }
{
	shape.setTexture(game->GetShipTexture());
	shape.setTextureRect(sf::IntRect{ 40,0,8,8 });
	
	shape.setScale(sf::Vector2f{ size, size });
	sf::FloatRect bounds = shape.getLocalBounds();
	shape.setOrigin(std::floor(bounds.left + bounds.width / 2.0f),
		std::floorf(bounds.top + bounds.height / 2.f));
}

Enemy::~Enemy()
{
}

Enemy::Enemy()
	: Enemy{nullptr, sf::Vector2f{0,0}, 1.0f, 1.0f}
{
}

void Enemy::Update(float dt)
{
	UpdatePosition(dt);
	shape.setPosition(position);
}

void Enemy::UpdatePosition(float dt)
{	
	sf::Vector2f playerPosition = game->GetPlayer()->GetPosition();
	sf::Vector2f enemyToPlayer = playerPosition - position;

	float length = sqrt(enemyToPlayer.x * enemyToPlayer.x +
		enemyToPlayer.y * enemyToPlayer.y);

	enemyToPlayer /= length;

	position += enemyToPlayer * speed * dt;
}

