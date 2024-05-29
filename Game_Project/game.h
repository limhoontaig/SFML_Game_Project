#pragma once
#include <SFML/Graphics.hpp>
class Game
{
public:
	Game();
	bool Initialize(); // 객체 생성
	void RunLoop(); // 게임 루프
	void Shutdown(); // 종료 로직
private:
	void InitializeGame(); // 게임 내부 객체 생성
	void ProcessInput();  // 게임 종료 탐지
	void UpdateGame(); // 게임 내 움직이는 부분 
	void DrawGame();
private:
	int screenWidth = 800;
	int screenHeight = 450;
	sf::RenderWindow window{ sf::VideoMode(screenWidth, screenHeight) , "Game"};

};