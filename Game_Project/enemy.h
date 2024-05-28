#pragma once
#include <SFML/Graphics.hpp>
//#include "player.h"

class Player;

class Enemy
{
public:
	
	Enemy(const sf::Vector2f pos, float size, sf::Color color, 
		float speed, const Player* player);
	
	Enemy(); // 기본 생성자
	//~Enemy();
	

	void Update();

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition();// const { return position };

private:
	void UpdatePosition();

private:
	sf::Vector2f position;
	float speed;
	const Player* playerRef;

	sf::CircleShape shape;
	float size;
	sf::Color color;
};
