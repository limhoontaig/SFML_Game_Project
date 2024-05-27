#define _CRTDBG_MAP_ALLOC
#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

int screenWidth = 800;
int screenHeight = 450;
const int numberOfEnemy = 10;
float gameSpeed = 0.005f;
float gameFactor = 5.0f;

void UpdatePlayerPosition(float &currentxPosition, float &currentyPosition)
{
    
}

void UpdateEnemyPosition(int numberOfEnemy, float* enemyXPosition, float* enemyYPosition, sf::Vector2f pos)
{
    for (int i = 0; i < numberOfEnemy; i++)
    {
        float enemyToPlayerX = pos.x - enemyXPosition[i];
        float enemyToPlayerY = pos.y - enemyYPosition[i];

        float length = sqrt(enemyToPlayerX * enemyToPlayerX + enemyToPlayerY * enemyToPlayerY);
        
        enemyToPlayerX /= length;
        enemyToPlayerY /= length;

        enemyXPosition[i] += enemyToPlayerX * gameSpeed;
        enemyYPosition[i] += enemyToPlayerY * gameSpeed;
 
    }
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    
    float* enemyXPosition = new float [numberOfEnemy];
    float* enemyYPosition = new float [numberOfEnemy];
    const float enemySize = 10.0f;
    const sf::Color enemyColor = { 155, 100, 155 };
    sf::CircleShape enemies[numberOfEnemy];
    for (int i = 0; i < numberOfEnemy; i++)
    {
        enemyXPosition[i] = screenWidth - 100;
        enemyYPosition[i] = rand() % screenHeight;
        enemies[i] = sf::CircleShape(enemySize);
        enemies[i].setPosition(sf::Vector2f(enemyXPosition[i], enemyYPosition[i]));
        enemies[i].setRadius(enemySize);
        enemies[i].setFillColor(enemyColor);
        enemies[i].setOutlineColor(sf::Color::Red);
        enemies[i].setOutlineThickness(3.0f);
    }

    Player player{ sf::Vector2f{50.0f, 50.0f}, 20.0f ,sf::Color::Red , 0.05f, screenWidth, screenHeight};
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.Update();
        player.Draw(window);
        sf::Vector2f pos = player.GetPosition();
        UpdateEnemyPosition(numberOfEnemy, enemyXPosition, enemyYPosition, pos);
        
        window.clear();
        
        for (int i = 0; i < numberOfEnemy; i++)
        {
            enemies[i].setPosition(sf::Vector2f(enemyXPosition[i], enemyYPosition[i]));
            window.draw(enemies[i]);
        }
        window.display();
    }
    delete[] enemyXPosition;
    delete[] enemyYPosition;    
    return 0;
}
