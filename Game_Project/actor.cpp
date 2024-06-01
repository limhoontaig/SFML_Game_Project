#include "actor.h"

Actor::Actor(Game* game, ActorType type, sf::Vector2f pos, float speed, float size)
	:game{game}, position{pos}, speed{speed}, size{size}, type{type}
{

}

Actor::~Actor()
{
}

void Actor::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
