#include "Npc.h"
#include <iostream>

NPC::NPC(float _x, float _y, float _speed, sf::Color _color)
	: x{ _x }, y{ _y }, speed{ _speed }, color{ _color } , offset_x(_speed), offset_y(_speed)
{
	rectShape = sf::RectangleShape{ sf::Vector2f{30.0f, 10.0f} };
	rectShape.setFillColor(_color);
	rectShape.setPosition(_x, _y);
}

void NPC::update()
{
	sf::Vector2f pos = rectShape.getPosition();
	//std::cout << "pos.x: " << pos.x << " pos.y: " << pos.y << std::endl;
	setSpeed();
	speed = GetSpeed();
	if (pos.x > 600.0f)
	{
		offset_x = -speed;
		setColor();
		rectShape.setFillColor(color);

	}
	else if (pos.x < 30.0f)
	{
		offset_x = speed;
		setColor();
		rectShape.setFillColor(color);
	}
	if (pos.y < 20.0f)
	{
		offset_y = speed;
	}
	else if (pos.y > 250.0f)
	{
		offset_y = - speed;
	}
	rectShape.move(offset_x, offset_y);
}

void NPC::draw(sf::RenderWindow& _window)
{
	_window.draw(rectShape);
}
