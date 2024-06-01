#pragma once

#include <SFML/Graphics.hpp>
#include "actor.h"

class Game;

class Player : public Actor
{
public:
	Player(Game* game, sf::Vector2f pos, float size, float speed);
	virtual ~Player();
	virtual void Update(float dt) override;
private:
	void ProcessInput(float dt);
};