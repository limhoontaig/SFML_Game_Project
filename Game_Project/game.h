#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class Enemy;
class Bullet;
class Actor;
class TextDisplay;

class Game
{
public:
	Game();
	bool Initialize(); // 객체 생성
	void RunLoop(); // 게임 루프
	void Shutdown(); // 종료 로직
	Player* GetPlayer() { return player; }
	std::vector<Actor*> GetActors() const { return actors; }
	sf::Texture& GetShipTexture() { return shipTexture; }
	sf::Texture& GetProjectileTexture() { return projettileTexture; }
	sf::Vector2i GetScreenSize() { return screenSize; }
	float GetElapsedTime() { return elapsedTime; }
	int GetGameScore() { return gameScore; }
	sf::Font& GetFont() { return font; }

public:
	float elapsedTime;
	int gameScore;


private:
	void InitializeGame(); // 게임 내부 객체 생성
	void ProcessInput();  // 게임 종료 탐지
	void UpdateGame(); // 게임 내 움직이는 부분 
	void SpawnBullet(float dt);  // 몇초에 한번씩 총알을 발사하는 부분
	void SpawnEnemy(float dt);  // 몇초에 한번씩 적을 생성하는 부분
	void CheckPlayerToEnemyCollision();
	void CheckBulletToEnemyCollision();
	void DrawGame();
	void TextPrint(sf::Text&, sf::Font&, int, float,
		float, const sf::Color&, sf::Color, sf::String);
private:
	int screenWidth = 800;
	int screenHeight = 550;
	sf::RenderWindow window{ sf::VideoMode(screenWidth, screenHeight) , "Game"};
	sf::Vector2i screenSize = sf::Vector2i{ screenWidth, screenHeight };
		
	sf::Texture shipTexture;
	sf::Texture projettileTexture;

	sf::Font font;
	
	sf::Text text1, text2, text3, textScoreTitle, textScore, textElapsedTimeTitle, textElapsedTime;
	
	float enemyFirePeriod;
	float enemyFireTimer;

	float bulletFirePeriod;
	float bulletFireTimer;
	
	sf::Clock deltaTimeClock;

	Player* player;

	std::vector<Actor*> actors;
};