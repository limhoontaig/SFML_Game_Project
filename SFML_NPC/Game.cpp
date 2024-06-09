#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "TextDisplay.h"
#include <iostream>

//class Player;

Game::Game()
	:player{ nullptr }, bulletFirePeriod{ 0.0 }, bulletFireTimer{ 0.0 }, enemyFirePeriod{ 0.0 }, enemyFireTimer{ 0.0 }, elapsedTime {0.0}, gameScore{0}
{
	actors.clear();
}

bool Game::Initialize()
{
	// Initialze SFML System

	// INITTIALIZE RESOURCES
	if (!shipTexture.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Ships.png"))
	{
		return false;
	}
	if (!projettileTexture.loadFromFile("../resources/sprites/SpaceShooterAssetPack_Projectiles.png"))
	{
		return false;
	}

	if (!font.loadFromFile("../resources/font/arial.ttf"))
	{
		return false;
	}

	//Initialze Game
	InitializeGame();

	return true;
}

void Game::RunLoop()
{
	while (window.isOpen())
	{
		ProcessInput();
		UpdateGame();
		DrawGame();
	}

}

void Game::Shutdown()
{
	for (int i = 0; i < actors.size(); i++)
	{
		delete actors[i];
	}
}


void Game::InitializeGame()
{

	// player create object
	Player* player = new Player{ this, ActorType::PLAYER, sf::Vector2f{screenWidth / 2.0f,
		screenHeight / 2.0f}, 3.0f , 150.0f };
	actors.push_back(player);
	this->player = player;

	// enemies create period
	enemyFirePeriod = (float)(rand() % 2) + 0.3f;
	enemyFireTimer = enemyFirePeriod;

	// Weapon (Bullet 신규 생성)
	bulletFirePeriod = 0.5f;
	bulletFireTimer = bulletFirePeriod;
}

void Game::ProcessInput()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::UpdateGame()
{
	float dt = deltaTimeClock.restart().asSeconds();
	float time = deltaTimeClock.getElapsedTime().asSeconds();

	if (player->GetIsActive() == true)
		elapsedTime += time * 1000;

	TextPrint(text2, font, 30, 50.0f, 50.0f,
		sf::Color::Red, sf::Color::Cyan, "Welcome to a Galaxy Shooter Game.");
	TextPrint(text1, font, 56, 50.0f, 100.0f,
		sf::Color::Magenta, sf::Color::White, "Enjoy Your Spare Time!");
	TextPrint(text3, font, 100, 50.0f, 160.0f,
		sf::Color::Yellow, sf::Color::Blue, "GAME START!!!");
	TextPrint(textElapsedTimeTitle, font, 20, 50.0f, 500.0f,
		sf::Color::Yellow, sf::Color::Blue, "Time to Go: ");
	TextPrint(textScoreTitle, font, 20, 350.0f, 500.0f,
		sf::Color::Yellow, sf::Color::Blue, "GAME Score: ");
	TextPrint(textElapsedTime, font, 20, 190.0f, 500.0f,
		sf::Color::Yellow, sf::Color::Blue, std::to_string(elapsedTime * 100));
	TextPrint(textScore, font, 20, 500.0f, 500.0f,
		sf::Color::Yellow, sf::Color::Blue, std::to_string(gameScore));

	SpawnEnemy(dt);

	SpawnBullet(dt);

	for (int i = 0; i < actors.size(); i++)
	{
		actors[i]->Update(dt);
	}
	CheckBulletToEnemyCollision();
	CheckPlayerToEnemyCollision();
}

void Game::SpawnBullet(float dt)
{
	// Logic Update
	bulletFireTimer -= dt;
	if (bulletFireTimer < 0.0f)
	{
		bulletFireTimer = bulletFirePeriod;
		actors.emplace_back(new Bullet{ this, ActorType::BULLET, 3.0f, 500.0f });
	}
}

void Game::SpawnEnemy(float dt)
{
	enemyFireTimer -= dt;
	if (enemyFireTimer < 0.0f)
	{
		enemyFireTimer = enemyFirePeriod;
		sf::Vector2f enemyInitPosition = sf::Vector2f{ (float)(rand() % screenWidth),
			(float)(rand() % screenHeight) };
		actors.emplace_back(new Enemy{ this, ActorType::ENEMY,
			enemyInitPosition, 3.0f, 100.0f });
	}
}

void Game::CheckPlayerToEnemyCollision()
{
	for (int i = 0; i < actors.size(); i++)
	{
		if (actors[i]->GetActorType() == ENEMY)
		{
			sf::Vector2f enemyPos = actors[i]->GetPosition();
			sf::Vector2f playerToEnemyPos = enemyPos - player->GetPosition();
			float dist = sqrt(playerToEnemyPos.x * playerToEnemyPos.x +
				playerToEnemyPos.y * playerToEnemyPos.y);
			if (dist < 0.5f)
			{
				// player collision to enemy
				player->SetIsActive(false);
			}

		}
	}
}

void Game::CheckBulletToEnemyCollision()
{
	for (int i = 0; i < actors.size(); i++)
	{
		for (int j = 0; j < actors.size(); j++) {
			if (actors[i]->GetActorType() == ActorType::BULLET &&
				actors[j]->GetActorType() == ActorType::ENEMY)
			{
				if (actors[i]->GetIsActive() == false || actors[j]->GetIsActive() == false)
					continue;
				sf::Vector2f bulletPos = actors[i]->GetPosition();
				sf::Vector2f enemyPos = actors[j]->GetPosition();

				sf::Vector2f bulletToEnemyPos = bulletPos - enemyPos;
				float dist = sqrt(bulletToEnemyPos.x * bulletToEnemyPos.x +
					bulletToEnemyPos.y * bulletToEnemyPos.y);
				if (dist < 0.5f)
				{
					// 적과 총알이 부딪힘
					actors[i]->SetIsActive(false);
					actors[j]->SetIsActive(false);
					gameScore += 1000;
				}
			}
		}
	}
}

void Game::DrawGame()
{
	window.clear();
	{
		if (elapsedTime < 1.5 && elapsedTime > 0)
			window.draw(text2);
		if (elapsedTime < 1.5 && elapsedTime > 0.5f)
			window.draw(text1);
		if (elapsedTime < 1.5 && elapsedTime > 1.0f)
			window.draw(text3);
		window.draw(textElapsedTimeTitle);
		window.draw(textElapsedTime);
		window.draw(textScoreTitle);
		window.draw(textScore);

		if (elapsedTime > 1.5)
		{
			for (int i = 0; i < actors.size(); i++)
			{
				actors[i]->Draw(window);
			}

		}
	}

	window.display();
}

void Game::TextPrint(sf::Text& textMsg, sf::Font& font, int size, float x,
	float y, const sf::Color& color, sf::Color outColor, sf::String p)
{
	textMsg.setFont(font); //폰트 
	textMsg.setCharacterSize(size); //크기
	textMsg.setPosition(x, y); //x, y 위치
	textMsg.setFillColor(color); //색    
	textMsg.setOutlineColor(outColor); //글자 테두리 색
	textMsg.setOutlineThickness(1.f); //글자 테두리 굵기
	textMsg.setString(p); //출력할 문자열
}
