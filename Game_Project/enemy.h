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
	

	void Update(float dt);

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() const;// const { return position };

private:
	void UpdatePosition(float dt);

private:
	sf::Vector2f position;
	float speed;
	const Player* playerRef;

	sf::CircleShape shape;
	float size;
	sf::Color color;
};
