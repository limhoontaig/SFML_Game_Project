#pragma once

#include <SFML/Graphics.hpp>

class Game;

class Player
{
public:
	Player(Game* game, sf::Vector2f pos, float size,  
		float speed, int screenWidth, int screenHeight);

	void Update(float dt);

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() const;

private:
	void ProcessInput(float dt);

private:
	Game* game;

	sf::Vector2f position;
	float speed;
	float size;
	sf::Sprite shape;

	//sf::RectangleShape shape;
	//sf::Color color;
	
	float gameFactor = 3.0f;
	int screenWidth, screenHeight;

};