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
	sf::Vector2i GetScreenSize() { return screenSize; }

private:
	void InitializeGame(); // ���� ���� ��ü ����
	void ProcessInput();  // ���� ���� Ž��
	void UpdateGame(); // ���� �� �����̴� �κ� 
	void SpawnBullet(float dt);  // ���ʿ� �ѹ��� �Ѿ��� �߻��ϴ� �κ�
	void SpawnEnemy(float dt);  // ���ʿ� �ѹ��� ���� �����ϴ� �κ�
	void CheckPlayerToEnemyCollision();
	void CheckBulletToEnemyCollision();
	void DrawGame();
private:
	int screenWidth = 800;
	int screenHeight = 450;
	sf::RenderWindow window{ sf::VideoMode(screenWidth, screenHeight) , "Game"};
	sf::Vector2i screenSize = sf::Vector2i{ screenWidth, screenHeight };
		
	sf::Texture shipTexture;
	sf::Texture projettileTexture;

	float enemyFirePeriod;
	float enemyFireTimer;

	float bulletFirePeriod;
	float bulletFireTimer;
	
	sf::Clock deltaTimeClock;

	Player* player;

	std::vector<Actor*> actors;
};