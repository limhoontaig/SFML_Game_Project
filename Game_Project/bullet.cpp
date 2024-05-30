#include "bullet.h"
#include "game.h"
#include "player.h"

Bullet::Bullet(Game* game, float size, const sf::Color& color, float speed)
	: game(game), size{size}, color{color}, speed{speed}
{
	Player* player = game->GetPlayer();
	position = player->GetPosition();

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

