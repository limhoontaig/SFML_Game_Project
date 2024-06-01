#include "bullet.h"
#include "game.h"
#include "player.h"
#include "enemy.h"

Bullet::Bullet(Game* game, ActorType type, float size, float speed)
	: Actor{ game, type, game->GetPlayer()->GetPosition(), speed, size }
{
	direction = GetPlayerToClosestEnemyVector();

	shape.setTexture(game->GetProjectileTexture());
	shape.setTextureRect(sf::IntRect{ 0,0,8,8 });

	shape.setScale(sf::Vector2f{ size, size });
	sf::FloatRect bounds = shape.getLocalBounds();
	shape.setOrigin(std::floor(bounds.left + bounds.width / 2.f),
		std::floor(bounds.top + bounds.height / 2.f));
}

Bullet::~Bullet()
{
}

Bullet::Bullet()
	: Bullet{nullptr, type, 0.3f, 5.0f}
{}

void Bullet::Update(float dt)
{
	UpdatePosition(dt);
	shape.setPosition(position);
}

void Bullet::UpdatePosition(float dt)
{
	position += direction * speed * dt;
	//shape.setPosition(position);
}

sf::Vector2f Bullet::GetPlayerToClosestEnemyVector()
{
	Player* player = this->game->GetPlayer();
	std::vector<Actor*> actors = game->GetActors();

	float minDist = 10000.0f;
	sf::Vector2f minDistVec = sf::Vector2f{1.0f, 0.0f};

	for (int i = 0; i < actors.size(); i++)
	{
		if (actors[i]->GetActorType() != ENEMY)
			continue;
		sf::Vector2f enemyPos = actors[i]->GetPosition();

		sf::Vector2f playerToEnemyVec = enemyPos - position;
		float dist = sqrt(playerToEnemyVec.x * playerToEnemyVec.x +
			playerToEnemyVec.y * playerToEnemyVec.y);
		if (dist < minDist)
		{
			minDist = dist;
			minDistVec = playerToEnemyVec / dist;
		}
	}
	return minDistVec;
}

