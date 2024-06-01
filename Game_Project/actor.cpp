#include "actor.h"

Actor::Actor(Game* game, ActorType type, sf::Vector2f pos, float speed, float size)
	:game{game}, position{pos}, speed{speed}, size{size}, type{type}, isActive{true}
{

}

Actor::~Actor()
{
}

void Actor::Draw(sf::RenderWindow& window)
{
	if (isActive == true)
	{
		window.draw(shape);
	}
}
