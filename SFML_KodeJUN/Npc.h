#pragma once

#include <SFML/Graphics.hpp>

class NPC
{
public:
	NPC(float _x, float _y, float _speed, sf::Color _color);
	sf::Color colors[4] = { sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Yellow };
	void update();
	void draw(sf::RenderWindow& _window);
	void setSpeed() { speed = (float)(rand()%5 +1.0f); }
	void setColor() { color = colors[rand() % 4]; }
	sf::Color GetColor() { return color; }
	float GetSpeed() { return speed; }
private:
	float x, y;
	float speed;
	sf::Color color;
	sf::RectangleShape rectShape;
	float offset_x;
	float offset_y;
};