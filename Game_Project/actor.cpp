#include "actor.h"

Actor::Actor(Game* game, sf::Vector2f pos, float speed, float size)
	:game{game}, position{pos}, speed{speed}, size{size}
{

}

Actor::~Actor()
{
}

void Actor::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
