#pragma once

#include <SFML/Graphics.hpp>
#include "actor.h"
class Game;

class Player : public Actor
{
public:
	Player(Game* game, sf::Vector2f pos, float size,  
		float speed, int screenWidth, int screenHeight);

	void Update(float dt);

private:
	void ProcessInput(float dt);

private:

	float gameFactor = 3.0f;
	int screenWidth, screenHeight;
};