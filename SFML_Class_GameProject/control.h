/*
#pragma once
#include <SFML/Graphics.hpp>

class Control
{
public:
	Control();
	bool Initialize();
	void RunLoop();
	//void ShutDown();

	sf::Font& GetFont() { return font; }
	sf::Texture& GetTexture() { return texture; }


private:
	void InitializeGame();
	void ProcessInput();
	void UpdateGame();
	void DrawGame();
private:
	sf::Text text;
	float screenWidth = 1280;
	float screenHeight = 720; // 화면 크기
	sf::RenderWindow window{ sf::VideoMode(screenWidth, screenHeight), "SFML Works" };
	sf::Texture texture;
	sf::Sprite menuBg; // Background png file
	sf::Font font;

};
*/