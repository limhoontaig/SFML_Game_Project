#pragma once
#include <SFML/Graphics.hpp>

class Player;
class Game;
class Enemy
{
public:
	
	Enemy(Game* game, const sf::Vector2f pos, float size, float speed);
	
	Enemy(); // 기본 생성자
	//~Enemy();
	

	void Update(float dt);

	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() const;

private:
	void UpdatePosition(float dt);

private:
	Game* game;
	sf::Vector2f position;
	float speed;

	sf::Sprite shape;
	float size;
};
