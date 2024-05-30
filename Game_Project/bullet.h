#pragma once

#include <SFML/Graphics.hpp>

class Game;

class Bullet
{
public:
	Bullet(Game* game, float size, const sf::Color& color, float speed);
	
	Bullet() {};

	void Update(float dt);

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() const { return position; }

private:
	void UpdatePosition(float dt);

private:
	Game* game;
	sf::Vector2f position;
	sf::Vector2f direction;
	float speed;

	sf::CircleShape shape;
	float size;
	sf::Color color;


}; 

