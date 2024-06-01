#include "game.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"

//class Player;

Game::Game()
	:player{ nullptr }, bulletFirePeriod{0.0}, bulletFireTimer{0.0}
{
	enemies.clear();
	bullets.clear();

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
	player = new Player{ this, sf::Vector2f{screenWidth / 2.0f, 
		screenHeight / 2.0f}, 3.0f , 100.0f };
	actors.push_back(player);

	// enemies
	for (int i = 0; i < 10; i++)
	{
		sf::Vector2f enemyInitPosition = sf::Vector2f{ (float)(screenWidth - 100), 
			(float)(rand() % screenHeight) };
		actors.emplace_back(new Enemy{ this, enemyInitPosition, 3.0f, 100.0f });
	}

	// Weapon (Bullet 신규 생성)
	bulletFirePeriod = 1.0f;
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

	// Logic Update
	bulletFireTimer -= dt;
	if (bulletFireTimer < 0.0f)
	{
		bulletFireTimer = bulletFirePeriod;	
		actors.emplace_back(new Bullet{ this, 3.0f, 500.0f });
	}

	for (int i = 0; i < actors.size(); i++)
	{
		actors[i]->Update(dt);
	}

}

void Game::DrawGame()
{
	window.clear();
	{
		for (int i = 0; i < actors.size(); i++)
		{
			actors[i]->Draw(window);
		}
	}

	window.display();
}
