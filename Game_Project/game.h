#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class Enemy;
class Bullet;
class Actor;

class Game
{
public:
	Game();
	bool Initialize(); // ��ü ����
	void RunLoop(); // ���� ����
	void Shutdown(); // ���� ����
	Player* GetPlayer() { return player; }
	std::vector<Actor*> GetActors() const { return actors; }
	sf::Texture& GetShipTexture() { return shipTexture; }
	sf::Texture& GetProjectileTexture() { return projettileTexture; }

private:
	void InitializeGame(); // ���� ���� ��ü ����
	void ProcessInput();  // ���� ���� Ž��
	void UpdateGame(); // ���� �� �����̴� �κ� 
	void DrawGame();
private:
	int screenWidth = 800;
	int screenHeight = 450;
	sf::RenderWindow window{ sf::VideoMode(screenWidth, screenHeight) , "Game"};

	
	sf::Texture shipTexture;
	sf::Texture projettileTexture;

	float bulletFirePeriod;
	float bulletFireTimer;
	
	sf::Clock deltaTimeClock;

	// Game Data
	
	Player* player;
	//std::vector <Enemy*> enemies;
	//std::vector <Bullet*> bullets;
	

	std::vector<Actor*> actors;
};