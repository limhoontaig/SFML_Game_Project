#include "enemy.h"

Enemy::Enemy(const sf::Vector2f pos, float size, sf::Color color, 
	float speed) //, const Player* player)
	: position( pos ), size( size ), color( color ), 
	speed( speed ) //, playerRef( player )

{
	shape = sf::CircleShape{ size };
	shape.setFillColor(color);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(3.0f);

}

void Enemy::Update()
{

}
void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
sf::Vector2f Enemy::GetPosition() // const { return position };
{
	return position;
}

void Enemy::UpdatePosition()
{

}
