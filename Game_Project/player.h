#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Vector2f pos, float size, sf::Color color, float speed);

	void Update();

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition();

private:
	void ProcessInput();


private:
	sf::Vector2f position;
	float speed;
	float gameFactor = 10.0f;

	sf::RectangleShape shape;
	float size;
	sf::Color color;
};