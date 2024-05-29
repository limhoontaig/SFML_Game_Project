#define _CRTDBG_MAP_ALLOC
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

int screenWidth = 800;
int screenHeight = 450;
float gameFactor = 5.0f;


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
    window.setFramerateLimit(120);
    // player create object
    Player player{ sf::Vector2f{50.0f, 50.0f}, 20.0f ,sf::Color::Red , 
        100.0f, screenWidth, screenHeight};

    // enemies create

    std::vector<Enemy*> enemies;
    
    for (int i = 0; i < 10; i++)
    {
        float enemyRandomX = screenWidth - 100;
        float enemyRandomY = rand() % screenHeight;
        sf::Vector2f enemyPos{ enemyRandomX, enemyRandomY };
        Enemy* e = new Enemy{ enemyPos, 10.0f, sf::Color::Cyan, 0.2f , &player };
        enemies.push_back(e);
    }
    
    // Bullet create
    std::vector<Bullet*> bullets;
    float bulletFirePeriod = 1.0f;
    float bulletFireTimer = bulletFirePeriod;
   
    sf::Clock deltaTimeClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Timer 생성
        float dt = deltaTimeClock.restart().asSeconds();
        bulletFireTimer -= dt;
        if (bulletFireTimer < 0)
        {
            // 신규 Bullet 생성
            Bullet* b = new Bullet{ player.GetPosition(), sf::Vector2f(0,-1),
                                    3.0f, sf::Color::Green, 500.0f };
            bullets.push_back(b);
            bulletFireTimer = bulletFirePeriod;
        }

        // Player Update
        player.Update(dt);
        
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
        
        window.clear();

        // Player Draw
        player.Draw(window);
        
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
    return 0;
}