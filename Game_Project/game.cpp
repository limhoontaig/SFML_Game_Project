#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

//class Player;

Game::Game()
	:player{ nullptr }
{
	enemies.clear();
	bullets.clear();
}

bool Game::Initialize()
{
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
	// Player memort delete
	delete player;

	// enenies memory 해제
	for (int i = 0; i < enemies.size(); i++)
	{
		delete enemies[i];
	}

	// Bullets 메모리해제
	for (int i = 0; i < bullets.size(); i++)
	{
		delete bullets[i];
	}
}

void Game::InitializeGame()
{
	// player create object
	player = new Player{ sf::Vector2f{50.0f, 50.0f}, 20.0f ,sf::Color::Red ,
		100.0f, screenWidth, screenHeight };
	// enemies
	for (int i = 0; i < 10; i++)
	{
		float enemyRandomX = (screenWidth - 100); // rand() %
		float enemyRandomY = rand() % screenHeight;
		sf::Vector2f enemyPos{ enemyRandomX, enemyRandomY };

		Enemy* e = new Enemy{ enemyPos, 10.0f, sf::Color::Cyan, 0.02f , player };
		enemies.push_back(e);
	}

	// 신규 Bullet 생성
	bulletFirePeriod = 1.0f;
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
	bulletFireTimer -= dt;
	if (bulletFireTimer < 0)
	{
		Bullet* b = new Bullet{ this, 3.0f, sf::Color::Green, 100.0f };
		bullets.push_back(b);
		bulletFireTimer = bulletFirePeriod;	

	}

	// Player Update
	player->Update(dt);

	// Enemy Update
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Update(dt);
	}

	// Bullet Update
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update(dt);
	}
}

void Game::DrawGame()
{
	window.clear();

	// Player Draw
	player->Draw(window);

	// Enemy Draw
	for (int i = 0; i < enemies.size(); i++)
	{
		(*enemies[i]).Draw(window);
	}

	//Bullet Draw
	for (int i = 0; i < bullets.size(); i++)
	{
		(*bullets[i]).Draw(window);
	}

	window.display();
}
