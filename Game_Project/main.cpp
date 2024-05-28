#define _CRTDBG_MAP_ALLOC
#include <SFML/Graphics.hpp>
#include <iostream>

#include "player.h"
#include "enemy.h"
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

int screenWidth = 800;
int screenHeight = 450;
float gameSpeed = 0.005f;
float gameFactor = 5.0f;


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");

    // player create object
    Player player{ sf::Vector2f{50.0f, 50.0f}, 20.0f ,sf::Color::Red , 
        0.05f, screenWidth, screenHeight};

    // enemies create

    std::vector<Enemy*> enemies;
    
    for (int i = 0; i < 10; i++)
    {
        float enemyRandomX = screenWidth - 100;
        float enemyRandomY = rand() % screenHeight;
        sf::Vector2f enemyPos{ enemyRandomX, enemyRandomY };
        Enemy* e = new Enemy{ enemyPos, 10.0f, sf::Color::Cyan, 0.05f , &player };
        enemies.push_back(e);
    }
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        player.Update();
        //sf::Vector2f pos = player.GetPosition();
        
        for (int i = 0; i < enemies.size(); i++)
        {
            (*enemies[i]).Update();
        }
        
        window.clear();

        player.Draw(window);
        
        
        for (int i = 0; i < enemies.size(); i++)
        {
            (*enemies[i]).Draw(window);
        }
        
        window.display();
    }
    delete[] enemies;

    return 0;
}